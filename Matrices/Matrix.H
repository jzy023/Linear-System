#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <iomanip>      

template<class type>
class Matrix {
	// static_assert(std::is_floating_point<type>::value, 
	// 	"Type must be either double or float");

protected:
	long unsigned int rows_;
	long unsigned int cols_;
	std::vector<type> matrix_;

	static void checkMat(const Matrix<type> &m);

	void clear();

	type inner(std::vector<type> &v1, std::vector<type> &v2){
		type ans = 0;
		for (int i = 0; i < v1.size(); i++){
			ans += v1[i]*v2[i];
		}
		return ans;
	};

	std::vector<type> outer(std::vector<type> &v1, std::vector<type> &v2){
		std::vector<type> ans(v1.size()*v2.size());
		for (int i = 0; i < v1.size(); i++){
			for (int j = 0; j < v2.size(); j++){
				ans(i*v2.size()+j) = v1[i]*v2[j];
			}
		}
		return ans;
	};

	type VNorm(std::vector<type> &v1, int i){
		type ans = 0;
		if (i == 1){
			for (type i : v1){
				ans += std::abs(i);
			}
			return ans;
		} else if (i == 2){
			for (type i : v1){
				ans += i*i;
			}
			return std::sqrt(ans);
		} else {
			for (type i : v1){
				ans = std::max(std::abs(i),ans);
			}
			return ans;
		}
	};

	inline std::vector<type> chunk(std::vector<int> &v1, std::vector<int> &v2);
		
public:
	// constructor & destructor
	Matrix(){};
	Matrix(std::vector<std::vector<type>> &m);
	Matrix(long unsigned int rows, long unsigned int cols);
	Matrix(long unsigned int rows, long unsigned int cols, std::vector<type> &m);
	Matrix(long unsigned int rows, long unsigned int cols, std::vector<std::vector<type>> &m);
	virtual ~Matrix() = default; // <-- ??

	// getter functions
	/* int func() const -->  cannot call any non-const member functions,
	   nor can it change any member variables.*/
	inline long unsigned int size(int i) const { return (i == 0)?rows_:cols_; }
	inline std::vector<long unsigned int> size() const { return {rows_,cols_}; }
	inline std::vector<type>& M() { return matrix_; }
	inline std::vector<type> Row(long unsigned int i) const;
	inline std::vector<type> Col(long unsigned int i) const;
	inline void Show() const;

	// compute transpose
	virtual Matrix<type> *T();


	// return sparse version of squareMatrix
	inline std::vector<std::vector<type>> Sparse();

	// return Norm <-- NEED IMPROVEMENT!!
	inline type Norm();

	// operator overloads
	type& operator()(const long unsigned int i, const long unsigned int j);
	void operator=(const Matrix<type> &m);

	void operator+=(const Matrix<type> &m);
	void operator+=(const type val);
	void operator-=(const Matrix<type> &m);
	void operator-=(const type val);
	void operator*=(const Matrix<type> &m);
	void operator*=(const type val);
	void operator/=(const Matrix<type> &m);
	void operator/=(const type val);
	void operator&=(const Matrix<type> &m);


	Matrix<type>* operator&(const Matrix<type> &m);



};

#endif
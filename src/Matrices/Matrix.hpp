#ifndef MATRIX_H
#define MATRIX_H

#include "includes.hpp"

template<class type>
class Matrix {
	// static_assert(std::is_floating_point<type>::value, 
	// 	"Type must be either double or float");

protected:
	long unsigned rows_;
	long unsigned cols_;
	std::vector<type> matrix_;

	static void checkMat(const Matrix<type> &m);

	void clear();

	type inner(std::vector<type> &v1, std::vector<type> &v2){
		type ans = 0;
		for (size_t i = 0; i < v1.size(); i++){
			ans += v1[i]*v2[i];
		}
		return ans;
	};

	std::vector<type> outer(std::vector<type> &v1, std::vector<type> &v2){
		std::vector<type> ans(v1.size()*v2.size());
		for (size_t i = 0; i < v1.size(); i++){
			for (size_t j = 0; j < v2.size(); j++){
				ans[i*v2.size()+j] = v1[i]*v2[j];
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

	std::vector<type> chunk(std::vector<long unsigned> &v1, std::vector<long unsigned> &v2);
		
public:
	// constructor & destructor
	Matrix(){};
	Matrix(std::vector<std::vector<type>> &m);
	Matrix(long unsigned rows, long unsigned cols);
	Matrix(long unsigned rows, long unsigned cols, std::vector<type> &m);
	Matrix(long unsigned rows, long unsigned cols, std::vector<std::vector<type>> &m);
	virtual ~Matrix() = default; // <-- ??

	// getter functions
	/* int func() const -->  cannot call any non-const member functions,
	   nor can it change any member variables.*/
	inline long unsigned size(int i) const { return (i == 0)?rows_:cols_; }
	inline std::vector<long unsigned> size() const { return {rows_,cols_}; }
	inline std::vector<type>& M() { return matrix_; }
	inline std::vector<type> Row(long unsigned i) const;
	inline std::vector<type> Col(long unsigned i) const;
	void Show() const;

	// compute transpose
	virtual Matrix<type> *T();


	// return sparse version of squareMatrix
	std::vector<std::vector<type>> sparse();

	// return Norm <-- NEED IMPROVEMENT!!
	type Norm();

	// operator overloads
	type& operator()(const long unsigned i, const long unsigned j);
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
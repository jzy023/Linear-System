#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>
#include <map>
#include <vector>
#include <type_traits>

template<class type>
class Matrix {
	static_assert(std::is_arithmetic<type>::value, "Type must be numeric");

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

		inline std::vector<type> Chunk(std::vector<int> &v1, std::vector<int> &v2);
		
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
	inline std::vector<long unsigned int> size() const { return {rows_,cols_}; }
	inline std::vector<type>& M() { return matrix_; }
	inline std::vector<type> Row(long unsigned int i) const;
	inline std::vector<type> Col(long unsigned int i) const;

	

	inline void Show() const;

	// compute transpose
	virtual Matrix<type> *T();

	// QR decomposition 


	// operator overloads
	type operator()(const long unsigned int i, const long unsigned int j);

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


};

#endif
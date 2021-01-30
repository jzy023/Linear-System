#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>
#include <vector>
#include <type_traits>

template<class type>
class Matrix {
	static_assert(std::is_arithmetic<type>::value, "Type must be numeric");

	protected:
		long unsigned int rows_;
		long unsigned int cols_;
		std::vector<std::vector<type>> matrix_;

		void clear();

		static void checkMat(const Matrix<type> &m);

	public:
	// constructor & destructor
	Matrix(){};
	Matrix(long unsigned int rows, long unsigned int cols);
	Matrix(std::vector<std::vector<int>> &m);
	virtual ~Matrix() = default; // <-- ??

	// build matrix
	void build(const std::vector<type> &m); // <-- need improvement on security

	// compute transpose
	virtual Matrix<type> *T();

	// operator overloads
	void operator=(const Matrix<type> &m);

	void operator+=(const Matrix<type> &m);
	void operator+=(const type val);

	void operator-=(const Matrix<type> &m);
	void operator-=(const type val);

	void operator*=(const Matrix<type> &m);
	void operator*=(const type val);

	void operator/=(const Matrix<type> &m);
	void operator/=(const type val);


	// get rows, cols and particular element
	/* int func() const -->  cannot call any non-const member functions,
	   nor can it change any member variables.*/
	type getEle(int i, int j) const { return matrix_[i][j]; }

	std::vector<std::vector<type>> getMat() const { return matrix_; }

	std::vector<long unsigned int> getSize() const 
	{
		return {rows_,cols_}; 
	}

};

#endif
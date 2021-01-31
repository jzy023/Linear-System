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
		std::vector<type> matrix_;

		void clear();

		type inner(std::vector<type> &v1, std::vector<type> &v2);

		static void checkMat(const Matrix<type> &m);

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
	std::vector<long unsigned int> size() const { return {rows_,cols_}; }
	std::vector<type>& M() { return matrix_; }
	std::vector<type> Row( long unsigned int i );
	std::vector<type> Col( long unsigned int i );

	// compute transpose
	virtual Matrix<type> *T();

	// compute 



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
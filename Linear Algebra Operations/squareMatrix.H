#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include <math.h>
#include <vector>
#include <type_traits>

#include "Matrix.H"

template<class type>
class squareMatrix : public Matrix<type>
{
	static_assert(std::is_arithmetic<type>::value, "Type must be numeric");

private:
	// std::vector<std::vector<type>> matrix_;
	

public:
	// constructors & destructor
	squareMatrix(){};
	squareMatrix(std::vector<std::vector<type>> &m);
	squareMatrix(long unsigned int n);
	squareMatrix(long unsigned int n, std::vector<type> &m);
	squareMatrix(long unsigned int n, std::vector<std::vector<type>> &m);
	
	~squareMatrix() = default;

	// resize matrix_ without ultering elements
	void resize();

	// return daigonal elemtents
	inline std::vector<type> diag();

	// return trace of M
	inline type trace();

	// calculate determinant of M 
	type det(); // mast function
	type detCore(std::vector<type> M, int n);

	// compute transpose
	inline squareMatrix<type> *T() override;
 
	// LU decomposition
	std::vector<squareMatrix<type>> *LU();
	std::vector<squareMatrix<type>> *LU1();

	// calculate eigenvalue of M
	type eigen();

	// calculate eigenvector of M
	squareMatrix<type> eigenVec(); 


};

#endif
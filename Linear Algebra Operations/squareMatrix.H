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
	squareMatrix(long unsigned int n);
	squareMatrix(std::vector<std::vector<type>> &m);
	~squareMatrix() = default;

	// resize matrix_ without ultering elements
	void resize();

	// return daigonal elemtents
	std::vector<type> diag();

	// return trace of M
	type trace();

	// calculate determinant of M 
	type det(); // mast function
	type detCore(std::vector<std::vector<type>> M, int n);

	// // compute transpose
	squareMatrix<type> *T() override;
 
	// QR decomposition


	// calculate eigenvalue of M
	type eigen();

	// calculate eigenvector of M
	squareMatrix<type> eigenVec(); 


};

#endif
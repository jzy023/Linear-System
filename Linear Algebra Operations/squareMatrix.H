#ifndef squareMatrix_H
#define squareMatrix_H

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
	// constructors
	squareMatrix(){};
	squareMatrix(long unsigned int n);
	squareMatrix(std::vector<std::vector<type>> &m);

	// resize matrix_ without ultering elements
	void resize();

	// return daigonal elemtents
	std::vector<type> diag();

	// return trace of M
	type trace();

	// calculate determinant of M 
	type det(); // mast function
	type detCore(std::vector<std::vector<type>> M, int n);
 
	// QR decomposition


	// calculate eigenvalue of M
	type eigen();

	// calculate eigenvector of M
	squareMatrix<type> eigenVec(); 


};

#endif
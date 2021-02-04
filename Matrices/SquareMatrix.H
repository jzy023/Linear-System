#ifndef SquareMATRIX_H
#define SquareMATRIX_H

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
	static void checkSquareMat(const squareMatrix<type> &m);
	

public:
	// constructors & destructor
	squareMatrix(){};
	squareMatrix(std::vector<std::vector<type>> &m);
	squareMatrix(long unsigned int n);
	squareMatrix(long unsigned int n, std::vector<type> &m);
	squareMatrix(long unsigned int n, std::vector<std::vector<type>> &m);
	~squareMatrix() = default;

	// resize matrix_ without ultering elements
	void Resize();

	// return diagonal elemtents
	inline std::vector<type> Diag();

	// return trace of M
	inline type Trace();

	// calculate determinant of M 
	type Det(); // mast function
	type DetCore(std::vector<type> M, int n);

	// compute transpose
	squareMatrix<type> *T() override;
 
	// LU decomposition
	std::vector<squareMatrix<type>> *LU();
	std::vector<squareMatrix<type>> *LU1();

	// calculate eigenvalue of M
	type Eigen();

	// calculate eigenvector of M
	squareMatrix<type> EigenVec(); 

};

#endif
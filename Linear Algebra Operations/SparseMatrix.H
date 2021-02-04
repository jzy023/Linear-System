#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <math.h>
#include <vector>
#include <type_traits>

#include "Matrix.H"
#include "SquareMatrix.H"

template<class type>
class sparseMatrix : public squareMatrix<type>
{
	static_assert(std::is_arithmetic<type>::value, "Type must be numeric");

private:
	std::vector<std::vector<type>> ele_;
	std::vector<std::vector<type>> idx_;

public:
	// constructors & destructor
	sparseMatrix(){};
	sparseMatrix(std::vector<std::vector<type>> &m);
	sparseMatrix(long unsigned int n);
	sparseMatrix(long unsigned int n, std::vector<type> &m);
	sparseMatrix(long unsigned int n, std::vector<std::vector<type>> &m);
	~sparseMatrix() = default;


};

#endif
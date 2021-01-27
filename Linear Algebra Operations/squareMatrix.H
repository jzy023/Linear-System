#ifndef matrix_H
#define matrix_H

#include <math.h>
#include <vector>
#include <type_traits>

template<class type>
class squareMatrix {
	static_assert(std::is_arithmetic<type>::value, "Type must be numeric");

private:
	long unsigned int rnc_; // rows and columns
	std::vector<std::vector<type>> matrix_;

	static void checkMat(const squareMatrix<type> &m);
	

public:
	// constructors
	squareMatrix(long unsigned int n);

	//build matrix_
	void build(const std::vector<type> &m); // <-- need improvement on security

	// resize matrix_ without ultering elements
	void resize();


	// get rows, cols and particular element
	/* int func() const -->  cannot call any non-const member functions,
	   nor can it change any member variables.*/
	int getSize() const { return rnc_; }
	type getEle(int i, int j) const { return matrix_[i][j]; }

	// return daigonal elemtents
	std::vector<type> diag();

	// return trace of M
	type trace();

	// calculate determinant of M 
	type det(); // mast function
	type detCore(std::vector<std::vector<type>> M, int n);
 
	// calculate eigenvalue of M
	type eigen();

	// calculate eigenvector of M
	squareMatrix<type> eigenVec(); 


};

#endif
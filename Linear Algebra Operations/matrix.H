#ifndef matrix_H
#define matrix_H

template<class type>
class Matrix {
	static_assert(std::is_arithmetic<type>::value, "Type must be numeric");

private:
	long unsigned int rows_;
	long unsigned int cols_;
	std::vector<std::vector<type>> matrix_;

	static void checkMat(const Matrix<type> &m);
	

public:
	// constructors
	Matrix(long unsigned int rows, long unsigned int cols);

	//build matrix_
	void build(const std::vector<type> &m); // <-- need improvement on security

	// resize matrix_ without ultering elements
	void resize();


	// get rows, cols and particular element
	/* int func() const -->  cannot call any non-const member functions,
	   nor can it change any member variables.*/
	int getNRow() const { return rows_; } 
	int getNCol() const { return cols_; }
	int getEle(int i, int j) const { return matrix_[i][j]; }

	// return daigonal elemtents
	std::vector<type> diag();

	// return trace of M
	type trace();

	// calculate determinant of M 
	double det();
 
	// calculate eigenvalue of M
	double eigen();

	// calculate eigenvector of M
	Matrix<type> eigenVec(); 


};

#endif
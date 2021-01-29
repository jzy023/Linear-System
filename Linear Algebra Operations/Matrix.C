#include "Matrix.H"

// CONSTRUCTORS
template<class type>
Matrix<type>::Matrix(long unsigned int rows, long unsigned int cols)
:
rows_(rows),
cols_(cols),
matrix_(std::vector<std::vector<type>>(rows,std::vector<type>(cols)))
{
}

// PRIVATE METHODS
template<class type>
void Matrix<type>::clear()
{
	matrix_ = {};
	rows_ = 0;
	cols_ = 0;
}


// PUBLIC METHODS
template<class type>
void Matrix<type>::operator=(const Matrix<type> &m){
	clear();
	rows_ = m.rows_;
	cols_ = m.cols_;
	matrix_ = std::vector<std::vector<type>>(rows_,std::vector<type>(cols_));
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i][j] += m.matrix_[i][j];
		}
	}
}


template<class type>
void Matrix<type>::operator+=(const Matrix<type> &m){
	if (rows_ != m.rows_ || cols_ != m.cols_){
		std::cout << "illegal operation due to different size\n";
		return;
	}
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i][j] += m.matrix_[i][j];
		}
	}
}
template<class type>
void Matrix<type>::operator+=(const type val){
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i][j] += val;
		}
	}
}


template<class type>
void Matrix<type>::operator-=(const Matrix<type> &m){
	if (rows_ != m.rows_ || cols_ != m.cols_){
		std::cout << "illegal operation due to different size\n";
		return;
	}
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i][j] -= m.matrix_[i][j];
		}
	}
}
template<class type>
void Matrix<type>::operator-=(const type val){
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i][j] -= val;
		}
	}
}


template<class type>
void Matrix<type>::operator*=(const Matrix<type> &m){
	if (rows_ != m.rows_ || cols_ != m.cols_){
		std::cout << "illegal operation due to different size\n";
		return;
	}
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i][j] *= m.matrix_[i][j];
		}
	}
}
template<class type>
void Matrix<type>::operator*=(const type val){
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i][j] *= val;
		}
	}
}


template<class type>
void Matrix<type>::operator/=(const Matrix<type> &m){
	if (rows_ != m.rows_ || cols_ != m.cols_){
		std::cout << "illegal operation due to different size\n";
		return;
	}
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i][j] /= m.matrix_[i][j];
		}
	}
}
template<class type>
void Matrix<type>::operator/=(const type val){
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i][j] /= val;
		}
	}
}
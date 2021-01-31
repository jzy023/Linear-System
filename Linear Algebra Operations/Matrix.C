#include "Matrix.H"


// PRIVATE METHODS -----------------------------------------------------------
template<class type>
void Matrix<type>::clear()
{
	matrix_ = {};
	rows_ = 0;
	cols_ = 0;
}

template<class type>
type inner(std::vector<type> &v1, std::vector<type> &v2)
{
	type ans = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		ans += v1[i]*v2[i];
	}
	return ans;
}

template<class type>
void Matrix<type>::checkMat(const Matrix<type> &m)
{
	if (m.matrix_.empty())
	{
		throw std::domain_error("matrix has empty dimensions");
	}
	if (m.matrix_.size() != m.size()[0]*m.size()[1])
	{
		throw std::domain_error("matrix has inconsistent dimensions");
	}
}


// CONSTRUCTORS ---------------------------------------------------------------
template<class type>
Matrix<type>::Matrix(std::vector<std::vector<type>> &m)
{
	rows_ = m.size();
	cols_ = m[0].size();
	matrix_ = std::vector<type>(rows_*cols_);
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] = m[i][j];
		}
	}
	checkMat(*this);
}

template<class type>
Matrix<type>::Matrix(long unsigned int rows, long unsigned int cols)
:
rows_(rows),
cols_(cols),
matrix_(std::vector<type>(rows*cols))
{
	checkMat(*this);
}

template<class type>
Matrix<type>::Matrix(long unsigned int rows, long unsigned int cols, 
					 std::vector<type> &m)
:
rows_(rows),
cols_(cols),
matrix_(m)
{
	checkMat(*this);
}

template<class type>
Matrix<type>::Matrix(long unsigned int rows, long unsigned int cols, 
					 std::vector<std::vector<type>> &m)
:
rows_(rows),
cols_(cols)
{
	matrix_ = std::vector<type>(rows_*cols_);
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] = m[i][j];
		}
	}
	checkMat(*this);
}


// PUBLIC METHODS -------------------------------------------------------------
template<class type>
std::vector<type> Matrix<type>::Row( long unsigned int i )
{
	std::vector<type> row(cols_);
	for (int j = 0; j < cols_; j++)
	{
		row[j] = matrix_[i*cols_ + j]; 
	}
	return row;
}

template<class type>
std::vector<type> Matrix<type>::Col( long unsigned int j )
{
	std::vector<type> col(rows_);
	for (int i = 0; i < rows_; i++)
	{
		col[i] = matrix_[i*cols_ + j];
	}
	return col;
}

template<class type>
Matrix<type> *Matrix<type>::T()
{
	std::vector<type> v(cols_*rows_);
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			v[j*rows_+i] = matrix_[i*cols_+j];
		}
	}
	return new Matrix<type>(cols_,rows_,v);
}

template<class type>
type Matrix<type>::operator()(const long unsigned int i, 
							  const long unsigned int j)
{
	return matrix_[i*cols_+j]; 
}

template<class type>
void Matrix<type>::operator=(const Matrix<type> &m)
{
	clear();
	rows_ = m.rows_;
	cols_ = m.cols_;
	matrix_ = m.matrix_;
}

template<class type>
void Matrix<type>::operator+=(const Matrix<type> &m)
{
	if (rows_ != m.rows_ || cols_ != m.cols_){
		throw std::domain_error("matrices have different dimensions");
	}
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] += m.matrix_[i*cols_+j];
		}
	}
}
template<class type>
void Matrix<type>::operator+=(const type val)
{
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] += val;
		}
	}
}

template<class type>
void Matrix<type>::operator-=(const Matrix<type> &m)
{
	if (rows_ != m.rows_ || cols_ != m.cols_){
		throw std::domain_error("matrices have different dimensions");
	}
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] -= m.matrix_[i*cols_+j];
		}
	}
}
template<class type>
void Matrix<type>::operator-=(const type val)
{
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] -= val;
		}
	}
}


template<class type>
void Matrix<type>::operator*=(const Matrix<type> &m)
{
	if (rows_ != m.rows_ || cols_ != m.cols_){
		throw std::domain_error("matrices have different dimensions");
	}
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] *= m.matrix_[i*cols_+j];
		}
	}
}
template<class type>
void Matrix<type>::operator*=(const type val)
{
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] *= val;
		}
	}
}

template<class type>
void Matrix<type>::operator/=(const Matrix<type> &m)
{
	if (rows_ != m.rows_ || cols_ != m.cols_){
		throw std::domain_error("matrices have different dimensions");
	}
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] /= m.matrix_[i*cols_+j];
		}
	}
}
template<class type>
void Matrix<type>::operator/=(const type val)
{
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] /= val;
		}
	}
}

// template<class type>
// void Matrix<type>::operator&=(const Matrix<type> &m)
// {
// 	if (cols_ != m.rows_){
// 		throw std::domain_error("matrices have different dimensions");
// 	}
// 	for (int i = 0; i < rows_; i++)
// 	{
// 		std::vector<type> row = matrix_[i];
// 		for (int j = 0; j < cols_; j++)
// 		{
// 			std::vector<type> col = m.matrix_[][j];
// 			matrix_[i][j] = Matrix<type>::inner(row, col);
// 		}
// 	}
// }
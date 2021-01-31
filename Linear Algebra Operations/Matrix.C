#include "Matrix.H"

// PRIVATE METHODS
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
	if (m.matrix_.empty() || m.matrix_.front().empty())
	{
		throw std::domain_error("matrix has empty dimensions");
	}
	// for (const auto &rows : m.matrix_)
	// {
	// 	if (rows.size() != m.rows_)
	// 	{
	// 		throw std::domain_error("non square matrix");
	// 	}
	// }
}


// CONSTRUCTORS
template<class type>
Matrix<type>::Matrix(long unsigned int rows, long unsigned int cols)
:
rows_(rows),
cols_(cols),
matrix_(std::vector<std::vector<type>>(rows,std::vector<type>(cols)))
{
	checkMat(*this);
}

template<class type>
Matrix<type>::Matrix(std::vector<std::vector<int>> &m)
{
	rows_ = m.size();
	cols_ = m[0].size();
	matrix_ = std::vector<std::vector<type>>(rows_,std::vector<type>(cols_));
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i][j] = m[i][j];
		}
	}
	checkMat(*this);
}


// PUBLIC METHODS
template<class type>
std::vector<type> Matrix<type>::Row( long unsigned int i )
{
	std::vector<type> row = matrix_[i];
	return row;
}

template<class type>
std::vector<type> Matrix<type>::Col( long unsigned int j )
{
	std::vector<type> col(rows_,0);
	for (int i = 0; i < rows_; i++)
	{
		col[i] = matrix_[i][j];
	}
	return col;
}




template<class type>
void Matrix<type>::build(const std::vector<type> &m)
{
	for (int i = 0; i < rows_; i++)
	{
		auto &row = matrix_[i];
		for (int j = 0; j < rows_; ++j)
		{
			row[j] = m[i*rows_+j];
		}
	}
}


template<class type>
Matrix<type> *Matrix<type>::T()
{
	std::vector<std::vector<type>> v(cols_,std::vector<type>(rows_));
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			v[j][i] = matrix_[i][j];
		}
	}
	return new Matrix<type>(v);
}


// template<class type>
// type Matrix<type>::(){


template<class type>
type Matrix<type>::operator()(const long unsigned int i, 
							  const long unsigned int j)
{
	return matrix_[i][j]; 
}


template<class type>
void Matrix<type>::operator=(const Matrix<type> &m)
{
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
void Matrix<type>::operator+=(const Matrix<type> &m)
{
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
void Matrix<type>::operator+=(const type val)
{
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i][j] += val;
		}
	}
}


template<class type>
void Matrix<type>::operator-=(const Matrix<type> &m)
{
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
void Matrix<type>::operator-=(const type val)
{
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i][j] -= val;
		}
	}
}


template<class type>
void Matrix<type>::operator*=(const Matrix<type> &m)
{
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
void Matrix<type>::operator*=(const type val)
{
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i][j] *= val;
		}
	}
}


template<class type>
void Matrix<type>::operator/=(const Matrix<type> &m)
{
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
void Matrix<type>::operator/=(const type val)
{
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			matrix_[i][j] /= val;
		}
	}
}

// template<class type>
// void Matrix<type>::operator&=(const Matrix<type> &m)
// {
// 	if (cols_ != m.rows_){
// 		std::cout << "illegal matrix multiplication\n";
// 		return;
// 	}
// 	for (int i = 0; i < rows_; i++)
// 	{
// 		std::vector<type> row = matrix_[i];
// 		for (int j = 0; j < cols_; j++)
// 		{
// 			std::vector<type> col = m.matrix_[][j];
// 			matrix_[i][j] = Matrix<type>::dot(row, col);
// 		}
// 	}
// }
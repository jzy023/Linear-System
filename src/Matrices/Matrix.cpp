#include "Matrix.hpp"

// PRIVATE METHODS ------------------------------------------------------------
template<class type>
void Matrix<type>::clear()
{
	std::vector<type>().swap(matrix_);
	rows_ = 0;
	cols_ = 0;
}

template<class type>
void Matrix<type>::checkMat(const Matrix<type> &m)
{
	if (!std::is_floating_point<type>::value)
	{
		throw std::domain_error("matrix must have floating type");
	}
	if (m.matrix_.empty())
	{
		throw std::domain_error("matrix has empty dimensions");
	}
	if (m.matrix_.size() != m.size()[0]*m.size()[1])
	{
		throw std::domain_error("matrix has inconsistent dimensions");
	}
}

template<class type>
std::vector<type> Matrix<type>::chunk(std::vector<long unsigned> &v1, std::vector<long unsigned> &v2)
{
	if (v1.size() != 2 || v2.size() != 2 ||
		v1[0] >= v2[0] || v1[1] >= v2[1] )
	{
		throw std::domain_error("illegal input");
	}
	if (v1[0] < 0 || v2[0] < 0 ||
		v1[1] < 0 || v2[1] < 0 ||
		v1[0] > rows_ || v2[0] > rows_ || 
		v1[1] > cols_ || v2[1] > cols_ )
	{
		throw std::domain_error("illegal input");
	}
	int newRows = v2[0] - v1[0] + 1;
	int newCols = v2[1] - v1[1] + 1;
	std::vector<type> v(newRows*newCols);
	for (long unsigned i = v1[0]; i < v2[0]+1; i++)
	{
		for (long unsigned j = v1[1]; j < v2[1]+1; j++)
		{
			v[i*newCols+j] = matrix_[i*cols_+j];
		}
	}
	return v;
}


// CONSTRUCTORS ---------------------------------------------------------------
template<class type>
Matrix<type>::Matrix(std::vector<std::vector<type>> &m)
{
	rows_ = m.size();
	cols_ = m[0].size();
	matrix_ = std::vector<type>(rows_*cols_);
	for (long unsigned i = 0; i < rows_; i++)
	{
		for (long unsigned j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] = m[i][j];
		}
	}
	checkMat(*this);
}

template<class type>
Matrix<type>::Matrix(long unsigned rows, long unsigned cols)
:
rows_(rows),
cols_(cols),
matrix_(std::vector<type>(rows*cols))
{
	checkMat(*this);
}

template<class type>
Matrix<type>::Matrix(long unsigned rows, long unsigned cols, 
					 std::vector<type> &m)
:
rows_(rows),
cols_(cols),
matrix_(m)
{
	checkMat(*this);
}

template<class type>
Matrix<type>::Matrix(long unsigned rows, long unsigned cols, 
					 std::vector<std::vector<type>> &m)
:
rows_(rows),
cols_(cols)
{
	matrix_ = std::vector<type>(rows_*cols_);
	for (long unsigned i = 0; i < rows_; i++)
	{
		for (long unsigned j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] = m[i][j];
		}
	}
	checkMat(*this);
}


// PUBLIC METHODS -------------------------------------------------------------
template<class type>
std::vector<type> Matrix<type>::Row( long unsigned i ) const 
{
	std::vector<type> row(cols_);
	for (long unsigned j = 0; j < cols_; j++)
	{
		row[j] = matrix_[i*cols_ + j]; 
	}
	return row;
}

template<class type>
std::vector<type> Matrix<type>::Col( long unsigned j ) const 
{
	std::vector<type> col(rows_);
	for (long unsigned i = 0; i < rows_; i++)
	{
		col[i] = matrix_[i*cols_ + j];
	}
	return col;
}


template<class type>
void Matrix<type>::Show() const
{
	int setw = 1; int perc = 4;
	int max = *std::max_element(matrix_.begin(),matrix_.end());
	if (max == 0) setw++;
	while(max != 0){
		max /= 10; setw++;
	}
	std::cout << std::fixed << std::setprecision(perc) << std::setfill(' ');
	std::cout << "returned matrix:\n";
	for (long unsigned i = 0; i < rows_; i++){
		for (long unsigned j = 0; j < cols_; j++){
			if (j == 0 && cols_ != 1)
				std::cout << "|" << std::setw(setw + perc + 1) << matrix_[i*cols_+j] << ", ";
			else if (j == 0 && cols_ == 1)
				std::cout << "|" << std::setw(setw + perc + 1) << matrix_[i*cols_+j] << "|";
			else if (j == cols_-1)
				std::cout << std::setw(setw + perc + 1) << matrix_[i*cols_+j] << "|";
			else
				std::cout << std::setw(setw + perc + 1) << matrix_[i*cols_+j] << ", ";
		}
		std::cout << "\n";
	}
}


template<class type>
Matrix<type> *Matrix<type>::T()
{
	std::vector<type> v(cols_*rows_);
	for (long unsigned i = 0; i < rows_; i++)
	{
		for (long unsigned j = 0; j < cols_; j++)
		{
			v[j*rows_+i] = matrix_[i*cols_+j];
		}
	}
	return new Matrix<type>(cols_,rows_,v);
}


template<class type> // <-- NEED IMPROVEMENT!!
type Matrix<type>::Norm()
{
	type ans = 0;
	for (type i : matrix_)
	{
		ans += i*i;
	}
	return std::sqrt(ans);
};


template<class type>
std::vector<std::tuple<long unsigned, long unsigned, type>> Matrix<type>::sparseElements()
{
	int len = 0;
	for (int i : matrix_)
	{
		if (i != 0)
		{
			len++;
		}
	}
    std::vector<std::tuple<long unsigned, long unsigned, type>> elements;
    elements.reserve(len);
	for (long unsigned i = 0; i < (rows_*cols_); i++)
	{
		if (matrix_[i] != 0)
		{
            int row = i / cols_;
            int col = i % cols_;
            type value = matrix_[i];
            elements.emplace_back(row, col, value);
		}
	}
	return elements;
}


template<class type>
sparseMatrix<type> Matrix<type>::sparse()
{
	int len = 0;
	for (int i : matrix_)
	{
		if (i != 0)
		{
			len++;
		}
	}
    std::vector<std::tuple<long unsigned, long unsigned, type>> elements;
    elements.reserve(len);
	for (long unsigned i = 0; i < (rows_*cols_); i++)
	{
		if (matrix_[i] != 0)
		{
            int row = i / cols_;
            int col = i % cols_;
            type value = matrix_[i];
            elements.emplace_back(row, col, value);
		}
	}

    sparseMatrix ans(rows_, cols_ , elements);
	return ans;
}



// Dot product -> Inner product, Cross product -> Outter product 



// OPERATORS ------------------------------------------------------------------
template<class type>
type& Matrix<type>::operator()(const long unsigned i, 
							  const long unsigned j)
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
	if (rows_ != m.rows_ || cols_ != m.cols_)
	{
		throw std::domain_error("matrices have different dimensions");
	}
	for (long unsigned i = 0; i < rows_; i++)
	{
		for (long unsigned j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] += m.matrix_[i*cols_+j];
		}
	}
}
template<class type>
void Matrix<type>::operator+=(const type val)
{
	for (long unsigned i = 0; i < rows_; i++)
	{
		for (long unsigned j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] += val;
		}
	}
}

template<class type>
void Matrix<type>::operator-=(const Matrix<type> &m)
{
	if (rows_ != m.rows_ || cols_ != m.cols_)
	{
		throw std::domain_error("matrices have different dimensions");
	}
	for (long unsigned i = 0; i < rows_; i++)
	{
		for (long unsigned j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] -= m.matrix_[i*cols_+j];
		}
	}
}
template<class type>
void Matrix<type>::operator-=(const type val)
{
	for (long unsigned i = 0; i < rows_; i++)
	{
		for (long unsigned j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] -= val;
		}
	}
}


template<class type>
void Matrix<type>::operator*=(const Matrix<type> &m)
{
	if (rows_ != m.rows_ || cols_ != m.cols_)
	{
		throw std::domain_error("matrices have different dimensions");
	}
	for (long unsigned i = 0; i < rows_; i++)
	{
		for (long unsigned j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] *= m.matrix_[i*cols_+j];
		}
	}
}
template<class type>
void Matrix<type>::operator*=(const type val)
{
	for (long unsigned i = 0; i < rows_; i++)
	{
		for (long unsigned j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] *= val;
		}
	}
}

template<class type>
void Matrix<type>::operator/=(const Matrix<type> &m)
{
	if (rows_ != m.rows_ || cols_ != m.cols_)
	{
		throw std::domain_error("matrices have different dimensions");
	}
	for (long unsigned i = 0; i < rows_; i++)
	{
		for (long unsigned j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] /= m.matrix_[i*cols_+j];
		}
	}
}
template<class type>
void Matrix<type>::operator/=(const type val)
{
	for (long unsigned i = 0; i < rows_; i++)
	{
		for (long unsigned j = 0; j < cols_; j++)
		{
			matrix_[i*cols_+j] /= val;
		}
	}
}

template<class type>
void Matrix<type>::operator&=(const Matrix<type> &m)
{
	if (cols_ != m.rows_)
	{
		throw std::domain_error("illegal dimensions");
	}
	std::vector<type> tempM(rows_*m.cols_);
	for (long unsigned i = 0; i < rows_; i++)
	{
		std::vector<type> row = Matrix<type>::Row(i);
		for (long unsigned j = 0; j < m.cols_; j++)
		{
			std::vector<type> col = m.Col(j);
			tempM[i*m.cols_+j] = Matrix<type>::inner(row, col);
		}
	}
	clear();
	rows_ = tempM.size()/m.cols_;
	cols_ = m.cols_;
	matrix_ = tempM;
}

template<class type>
Matrix<type>* Matrix<type>::operator&(const Matrix<type> &m)
{
	if (cols_ != m.rows_)
	{
		throw std::domain_error("illegal dimensions");
	}
	std::vector<type> tempM(rows_*m.cols_);
	for (long unsigned i = 0; i < rows_; i++)
	{
		std::vector<type> row = Matrix<type>::Row(i);
		for (long unsigned j = 0; j < m.cols_; j++)
		{
			std::vector<type> col = m.Col(j);
			tempM[i*m.cols_+j] = Matrix<type>::inner(row, col);
		}
	}
	long unsigned rows = tempM.size()/m.cols_;
	long unsigned cols = m.cols_;
	return new Matrix<type>(rows,cols,tempM);
}


template class Matrix<double>;
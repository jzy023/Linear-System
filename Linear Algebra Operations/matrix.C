#include "matrix.H"

template<class type>
Matrix<type>::Matrix(long unsigned int rows, long unsigned int cols)
:
rows_(rows),
cols_(cols),
matrix_(std::vector<std::vector<type>>(rows,std::vector<type>(cols)))
{
	Matrix::checkMat(*this);
};


template<class type>
void Matrix<type>::checkMat(const Matrix<type> &m)
{
	if (m.matrix_.empty() || m.matrix_.front().empty())
	{
		throw std::domain_error("matrix has empty dimensions");
	}
	for (const auto &rows : m.matrix_)
	{
		if (rows.size() != m.cols_)
		{
			throw std::domain_error("non square matrix");
		}
	}
}


template<class type>
void Matrix<type>::build(const std::vector<type> &m)
{
	if (m.size() != rows_*cols_)
	{
		throw std::domain_error("invalid!");
	}
	for (int i = 0; i < rows_; i++)
	{
		auto &row = matrix_[i];
		for (int j = 0; j < cols_; ++j)
		{
			row[j] = m[i*cols_+j];
		}
	}
}


template<class type>
std::vector<type> Matrix<type>::diag()
{
	if (rows_ != cols_)
	{
		return {0};
	}
	std::vector<type> ans(rows_,0);
	for (int i = 0; i < rows_; i++){
		ans[i] = matrix_[i][i];
	}
	return ans;
}


template<class type>
type Matrix<type>::trace()
{
	type ans = 0.0;
	for (int i = 0; i < rows_; i++){
		ans += matrix_[i][i];
	}
	return ans;
}


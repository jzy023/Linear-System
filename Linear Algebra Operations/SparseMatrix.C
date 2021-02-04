#include "SparseMatrix.H"

// PRIVATE METHODS ------------------------------------------------------------
template<class type>
void sparseMatrix<type>::clear()
{
	std::vector<type>().swap(ele_);
	std::vector<type>().swap(idx_);
	rows_ = 0;
	cols_ = 0;
}

template<class type>
void sparseMatrix<type>::checkMat(const sparseMatrix<type> &m)
{
	if (m.matrix_.empty())
	{
		throw std::domain_error("matrix has empty dimensions");
	}
	if (m.ele_.size() != m.idx_.size())
	{
		throw std::domain_error("matrix has inconsistent dimensions");
	}
	if (*std::max_element(m.idx_.begin(),m.idx_.end()) > m.size()[0]*m.size()[1])
	{
		throw std::domain_error("matrix has illegal dimensions");
	}
}


// CONSTRUCTORS ---------------------------------------------------------------
template<class type>
sparseMatrix<type>::sparseMatrix(long unsigned int rows, long unsigned int cols)
:
rows_(rows),
cols_(cols)
{
	checkMat(*this);
}

template<class type>
sparseMatrix<type>::sparseMatrix(long unsigned int rows, 
								 long unsigned int cols,
								 std::vector<std::vector<type>> &m)
:
rows_(rows),
cols_(cols),
ele_(m[0]),
idx_(m[1])
{
	checkMat(*this);
}


// PUBLIC METHODS -------------------------------------------------------------

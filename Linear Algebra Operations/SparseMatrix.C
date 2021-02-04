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
	if (m.idx_.empty() || m.ele_.empty())
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
sparseMatrix<type>::sparseMatrix(std::vector<long unsigned int> size)
:
rows_(size[0]),
cols_(size[1])
{
	checkMat(*this);
}

template<class type>
sparseMatrix<type>::sparseMatrix(std::vector<long unsigned int> size,
								 std::vector<std::vector<type>> &m)
:
rows_(size[0]),
cols_(size[1]),
idx_(m[0]),
ele_(m[1])
{
	checkMat(*this);
}

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
idx_(m[0]),
ele_(m[1])
{
	checkMat(*this);
}


// PUBLIC METHODS -------------------------------------------------------------
template<class type>
void sparseMatrix<type>::Show() const
{
	std::cout << "returned matrix:\n";
	for (int i = 0; i < idx_.size(); i++){
		if (idx_.size() > 5){
			if (i > 2 && i < idx_.size() - 2)
				continue;
			if (i == 0)
				std::cout << "idx: |" << idx_[i] << ", ";
			else if (i == 2)
				std::cout << "..., ";
			else if (i == idx_.size() - 1)
				std::cout << idx_[i] << "|\n";
			else
				std::cout << idx_[i] << ", ";
		}
		else{
			if (i == 0)
				std::cout << "idx: |" << idx_[i] << ", ";
			else if (i == idx_.size() - 1)
				std::cout << idx_[i] << "|\n";
			else
				std::cout << idx_[i] << ", ";
		}
	}
	for (int i = 0; i < idx_.size(); i++){
		if (idx_.size() > 5){
			if (i > 2 && i < idx_.size() - 2)
				continue;
			if (i == 0)
				std::cout << "ele: |" << ele_[i] << ", ";
			else if (i == 2)
				std::cout << "..., ";
			else if (i == idx_.size() - 1)
				std::cout << ele_[i] << "|\n";
			else
				std::cout << ele_[i] << ", ";
		}
		else{
			if (i == 0)
				std::cout << "ele: |" << ele_[i] << ", ";
			else if (i == idx_.size() - 1)
				std::cout << ele_[i] << "|\n";
			else
				std::cout << ele_[i] << ", ";
		}
	}
}


#include "SparseMatrix.hpp"

// PRIVATE METHODS ------------------------------------------------------------
template<class type>
void sparseMatrix<type>::clear()
{
	std::vector<std::tuple<long unsigned, long unsigned, type>>().swap(eles_);
	rows_ = 0;
	cols_ = 0;
}

template<class type>
void sparseMatrix<type>::checkMat(const sparseMatrix<type> &m)
{
	if (!std::is_floating_point<type>::value)
	{
		throw std::domain_error("matrix must have floating type");
	}
	if (m.eles_.empty())
	{
		throw std::domain_error("matrix has empty dimensions");
	}

    // computationally demanding
    long unsigned maxFirstInt = std::numeric_limits<long unsigned>::min();
    long unsigned maxSecondInt = std::numeric_limits<long unsigned>::min();
    for (const auto& tup : m.eles_) {
        long unsigned firstInt = std::get<0>(tup);
        long unsigned secondInt = std::get<1>(tup);

        if (firstInt > maxFirstInt) {
            maxFirstInt = firstInt;
        }

        if (secondInt > maxSecondInt) {
            maxSecondInt = secondInt;
        }
    }
    if (maxFirstInt > m.rows_ || maxSecondInt > m.cols_)
    {
        throw std::domain_error("matrix eles exceeding rows and cols");
    }
    
    // if (eles_.size() != m.size()[0]*m.size()[1])
	// {
	// 	throw std::domain_error("matrix has illegal dimensions");
	// }
	// if (*std::max_element(m.idx_.begin(),m.idx_.end()) > m.size()[0]*m.size()[1])
	// {
	// 	throw std::domain_error("matrix has illegal dimensions");
	// }
}


// CONSTRUCTORS ---------------------------------------------------------------
template<class type>
sparseMatrix<type>::sparseMatrix(std::vector<long unsigned> size)
:
rows_(size[0]),
cols_(size[1])
{
	checkMat(*this);
}

template<class type>
sparseMatrix<type>::sparseMatrix(std::vector<long unsigned> size,
                                 std::vector<std::tuple<long unsigned, long unsigned, type>> &elements)
:
rows_(size[0]),
cols_(size[1]),
eles_(elements)
{
    checkMat(*this);
}

template<class type>
sparseMatrix<type>::sparseMatrix(long unsigned rows, long unsigned cols)
:
rows_(rows),
cols_(cols)
{
	checkMat(*this);
}

template<class type>
sparseMatrix<type>::sparseMatrix(long unsigned rows, 
								 long unsigned cols,
								 std::vector<std::tuple<long unsigned, long unsigned, type>> &elements)
:
rows_(rows),
cols_(cols),
eles_(elements)
{
	checkMat(*this);
}


// PUBLIC METHODS -------------------------------------------------------------
// template<class type>
// void sparseMatrix<type>::Show() const
// {
// 	int setw = 1; int perc = 4;
// 	int max = *std::max_element(ele_.begin(),ele_.end());
// 	if (max == 0) setw++;
// 	while(max != 0){
// 		max /= 10; setw++;
// 	}
// 	std::cout << std::fixed << std::setprecision(perc) << std::setfill(' ');
// 	std::cout << "returned matrix:\n";
// 	for (long unsigned i = 0; i < idx_.size(); i++){
// 		if (idx_.size() > 5){
// 			if (i > 2 && i < idx_.size() - 2)
// 				continue;
// 			if (i == 0)
// 				std::cout << "idx: |" << std::setw(setw + perc + 1) << idx_[i] << ", ";
// 			else if (i == 2)
// 				std::cout << "..., ";
// 			else if (i == idx_.size() - 1)
// 				std::cout << std::setw(setw + perc + 1) << idx_[i] << "|\n";
// 			else
// 				std::cout << std::setw(setw + perc + 1) << idx_[i] << ", ";
// 		}
// 		else{
// 			if (i == 0)
// 				std::cout << "idx: |" << std::setw(setw + perc + 1) << idx_[i] << ", ";
// 			else if (i == idx_.size() - 1)
// 				std::cout << std::setw(setw + perc + 1) << idx_[i] << "|\n";
// 			else
// 				std::cout << std::setw(setw + perc + 1) << idx_[i] << ", ";
// 		}
// 	}
// 	for (long unsigned i = 0; i < idx_.size(); i++){
// 		if (idx_.size() > 5){
// 			if (i > 2 && i < idx_.size() - 2)
// 				continue;
// 			if (i == 0)
// 				std::cout << "ele: |" << std::setw(setw + perc + 1) << ele_[i] << ", ";
// 			else if (i == 2)
// 				std::cout << "..., ";
// 			else if (i == idx_.size() - 1)
// 				std::cout << std::setw(setw + perc + 1) << ele_[i] << "|\n";
// 			else
// 				std::cout << std::setw(setw + perc + 1) << ele_[i] << ", ";
// 		}
// 		else{
// 			if (i == 0)
// 				std::cout << "ele: |" << std::setw(setw + perc + 1) << ele_[i] << ", ";
// 			else if (i == idx_.size() - 1)
// 				std::cout << std::setw(setw + perc + 1) << ele_[i] << "|\n";
// 			else
// 				std::cout << std::setw(setw + perc + 1) << ele_[i] << ", ";
// 		}
// 	}
// }


// PRE DECLARATION ------------------------------------------------------------
template class sparseMatrix<double>;
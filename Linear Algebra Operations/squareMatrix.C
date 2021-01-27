#include "squareMatrix.H"

template<class type>
squareMatrix<type>::squareMatrix(long unsigned int n)
:
rnc_(n),
matrix_(std::vector<std::vector<type>>(n,std::vector<type>(n)))
{
	squareMatrix::checkMat(*this);
};


template<class type>
void squareMatrix<type>::checkMat(const squareMatrix<type> &m)
{
	if (m.matrix_.empty() || m.matrix_.front().empty())
	{
		throw std::domain_error("matrix has empty dimensions");
	}
	// for (const auto &rows : m.matrix_)
	// {
	// 	if (rows.size() != m.rnc_)
	// 	{
	// 		throw std::domain_error("non square matrix");
	// 	}
	// }
}


template<class type>
void squareMatrix<type>::build(const std::vector<type> &m)
{
	for (int i = 0; i < rnc_; i++)
	{
		auto &row = matrix_[i];
		for (int j = 0; j < rnc_; ++j)
		{
			row[j] = m[i*rnc_+j];
		}
	}
}


template<class type>
std::vector<type> squareMatrix<type>::diag()
{
	if (rnc_ != rnc_)
	{
		return {0};
	}
	std::vector<type> ans(rnc_,0);
	for (int i = 0; i < rnc_; i++){
		ans[i] = matrix_[i][i];
	}
	return ans;
}


template<class type>
type squareMatrix<type>::trace()
{
	type ans = 0.0;
	for (int i = 0; i < rnc_; i++){
		ans += matrix_[i][i];
	}
	return ans;
}


template<class type>
type squareMatrix<type>::det(){
	int det = 0;
	if (rnc_ == 2){
		det = ( matrix_[0][0]*matrix_[1][1] 
			  - matrix_[0][1]*matrix_[1][0]);
	}
	else{
		// for (int i = 0; i < n; ++i)
		// {
		// 	/* code */
		// }

	}

	return det;
}


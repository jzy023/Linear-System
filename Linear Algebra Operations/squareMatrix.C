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
	for (int i = 0; i < rnc_; i++)
	{
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
type squareMatrix<type>::detCore(std::vector<std::vector<type>> M, int n){
	// credit: tutorialspoint.com/cplusplus-program-to-compute-determinant-of-a-matrix
	type det = 0;
	std::vector<std::vector<type>> subM(n-1, std::vector<type> (n-1,0));
	if (n == 1)
	{
		det = M[0][0];
	}
	if (n == 2)
	{
		det = ( M[0][0]*M[1][1] 
			  - M[0][1]*M[1][0]);
	}
	else
	{
		for (int x = 0; x < n; x++)
		{
			int subi = 0;
			for (int i = 1; i < n; i++)
			{
				int subj = 0;
				for (int j = 0; j < n; j++)
				{
					if (x == j)
					{
						continue;
					}
					subM[subi][subj] = M[i][j];
					subj++; 
				}
				subi++;
			}
			type now = (pow(-1,x)*M[0][x]*detCore(subM,n-1));
			det += now; 
		}

	}
	return det;
}

template<class type>
type squareMatrix<type>::det(){
	// mask function for determinant function
	if (rnc_ > 10)
	{
		std::cout << "Warning: large matrix size\n";
	}
	return detCore(matrix_, rnc_);
}


#include "squareMatrix.H"

template<class type>
squareMatrix<type>::squareMatrix(long unsigned int n) 
:
Matrix<type>::Matrix(n,n)
{
	Matrix<type>::checkMat(*this);
};

template<class type>
squareMatrix<type>::squareMatrix(std::vector<std::vector<type>> &m)
:
Matrix<type>::Matrix(m)
{
	Matrix<type>::checkMat(*this);
};


// PUBLIC METHODS
template<class type>
std::vector<type> squareMatrix<type>::diag()
{
	if (this->rows_ != this->rows_)
	{
		return {0};
	}
	std::vector<type> ans(this->rows_,0);
	for (int i = 0; i < this->rows_; i++)
	{
		ans[i] = this->matrix_[i][i];
	}
	return ans;
}


template<class type>
type squareMatrix<type>::trace()
{
	type ans = 0.0;
	for (int i = 0; i < this->rows_; i++){
		ans += this->matrix_[i][i];
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
	if (this->rows_ > 10)
	{
		std::cout << "Warning: large matrix size\n";
	}
	return detCore(this->matrix_, this->rows_);
}


template<class type>
squareMatrix<type> *squareMatrix<type>::T(){
	std::vector<std::vector<type>> v(this->cols_,std::vector<type>(this->rows_));
	for (int i = 0; i < this->rows_; i++)
	{
		for (int j = 0; j < this->cols_; j++)
		{
			v[j][i] = this->matrix_[i][j];
		}
	}
	return new squareMatrix<type>(v);
}


template<class type>
type squareMatrix<type>::eigen(){
	type ans = 0;

	return ans; 
}



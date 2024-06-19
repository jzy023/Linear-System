#include "SquareMatrix.hpp"

// PRIVATE METHODS ------------------------------------------------------------
template<class type>
void squareMatrix<type>::checkSquareMat(const squareMatrix<type> &m)
{
	if (m.matrix_.empty())
	{
		throw std::domain_error("matrix has empty dimensions");
	}
	if (m.matrix_.size() != m.size()[0]*m.size()[1])
	{
		throw std::domain_error("matrix has inconsistent dimensions");
	}
	if (m.size()[0] != m.size()[1])
	{
		throw std::domain_error("matrix is not square");
	}
}

// CONSTRUCTORS ---------------------------------------------------------------
template<class type>
squareMatrix<type>::squareMatrix(std::vector<std::vector<type>> &m)
:
Matrix<type>::Matrix(m)
{
	checkSquareMat(*this);
};

template<class type>
squareMatrix<type>::squareMatrix(long unsigned n) 
:
Matrix<type>::Matrix(n,n)
{
	checkSquareMat(*this);
};

template<class type>
squareMatrix<type>::squareMatrix(long unsigned n, 
								 std::vector<type> &m) 
:
Matrix<type>::Matrix(n,n,m)
{
	checkSquareMat(*this);
};

template<class type>
squareMatrix<type>::squareMatrix(long unsigned n, 
								 std::vector<std::vector<type>> &m) 
:
Matrix<type>::Matrix(n,n,m)
{
	checkSquareMat(*this);
};


// PUBLIC METHODS -------------------------------------------------------------
template<class type>
std::vector<type> squareMatrix<type>::Diag()
{
	std::vector<type> ans(this->rows_,0);
	for (long unsigned i = 0; i < this->rows_; i++)
	{
		ans[i] = this->matrix_[i*this->cols_+i];
	}
	return ans;
}


template<class type>
type squareMatrix<type>::Trace()
{
	type ans = 0.0;
	for (long unsigned i = 0; i < this->rows_; i++){
		ans += this->matrix_[i*this->cols_+i];
	}
	return ans;
}


template<class type>
type squareMatrix<type>::DetCore(std::vector<type> M, int n){
	// credit: tutorialspoint.com/cplusplus-program-to-compute-determinant-of-a-matrix
	type det = 0;
	std::vector<type> subM(pow(n-1,2));
	if (n == 1)
	{
		det = M[0];
	}
	if (n == 2)
	{
		det = ( M[0]*M[3] 
			  - M[1]*M[2]);
	}
	else
	{
		for (int x = 0; x < n; x++)
		{
			long unsigned subi = 0;
			for (int i = 1; i < n; i++)
			{
				long unsigned subj = 0;
				for (int j = 0; j < n; j++)
				{
					if (x == j)
					{
						continue;
					}
					subM[subi*(n-1)+subj] = M[i*n+j];
					subj++; 
				}
				subi++;
			}
			type now = (pow(-1,x)*M[x]*DetCore(subM,n-1));
			det += now; 
		}
	}
	return det;
}
template<class type>
type squareMatrix<type>::Det(){
	// mask function for determinant function
	if (this->rows_ > 10)
	{
		std::cout << "Warning: large matrix size\n";
	}
	return DetCore(this->matrix_, this->rows_);
}


template<class type>
squareMatrix<type> *squareMatrix<type>::T(){
	std::vector<type> v(this->cols_*this->rows_);
	for (long unsigned i = 0; i < this->rows_; i++)
	{
		for (long unsigned j = 0; j < this->cols_; j++)
		{
			v[j*this->rows_+i] = this->matrix_[i*this->cols_+j];
		}
	}
	return new squareMatrix<type>(this->rows_,v);
}


template<class type>
std::vector<squareMatrix<type>> *squareMatrix<type>::LU(){
	// Doolittle Algorithm
	// credit: geeksforgeeks.org/doolittle-algorithm-lu-decomposition
	long unsigned n = this->rows_;
	std::vector<type> LMat(pow(n,2),0);
	std::vector<type> UMat(pow(n,2),0);
	for (long unsigned i = 0; i < n; i++)
	{
		for (long unsigned k = i; k < n; k++)
		{
			long unsigned sumU = 0;
			long unsigned sumL = 0;
			for (long unsigned j = 0; j < i; j++)
			{
				sumU += (LMat[i*n+j]*UMat[j*n+k]);
				sumL += LMat[k*n+j]*UMat[j*n+i];
			}
			UMat[i*n+k] = this->matrix_[i*n+k] - sumU;
			LMat[k*n+i] = (this->matrix_[k*n+i] - sumL)/UMat[i*n+i];
		}
	}
	squareMatrix<type> L(n,LMat);
	squareMatrix<type> U(n,UMat);
	return new std::vector<squareMatrix<type>>{L,U};
}


// template<class type>
// type squareMatrix<type>::eigen(){
// 	type ans = 0;

// 	return ans; 
// }


template class squareMatrix<double>;




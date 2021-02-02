#include "squareMatrix.H"


// CONSTRUCTORS ---------------------------------------------------------------
template<class type>
squareMatrix<type>::squareMatrix(std::vector<std::vector<type>> &m)
:
Matrix<type>::Matrix(m)
{
	Matrix<type>::checkMat(*this);
};

template<class type>
squareMatrix<type>::squareMatrix(long unsigned int n) 
:
Matrix<type>::Matrix(n,n)
{
	Matrix<type>::checkMat(*this);
};

template<class type>
squareMatrix<type>::squareMatrix(long unsigned int n, 
								 std::vector<type> &m) 
:
Matrix<type>::Matrix(n,n,m)
{
	Matrix<type>::checkMat(*this);
};

template<class type>
squareMatrix<type>::squareMatrix(long unsigned int n, 
								 std::vector<std::vector<type>> &m) 
:
Matrix<type>::Matrix(n,n,m)
{
	Matrix<type>::checkMat(*this);
};


// PUBLIC METHODS -------------------------------------------------------------
template<class type>
std::vector<type> squareMatrix<type>::diag()
{
	std::vector<type> ans(this->rows_,0);
	for (int i = 0; i < this->rows_; i++)
	{
		ans[i] = this->matrix_[i*this->cols_+i];
	}
	return ans;
}

template<class type>
type squareMatrix<type>::trace()
{
	type ans = 0.0;
	for (int i = 0; i < this->rows_; i++){
		ans += this->matrix_[i*this->cols_+i];
	}
	return ans;
}

template<class type>
type squareMatrix<type>::detCore(std::vector<type> M, int n){
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
					subM[subi*(n-1)+subj] = M[i*n+j];
					subj++; 
				}
				subi++;
			}
			type now = (pow(-1,x)*M[x]*detCore(subM,n-1));
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
	std::vector<type> v(this->cols_*this->rows_);
	for (int i = 0; i < this->rows_; i++)
	{
		for (int j = 0; j < this->cols_; j++)
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
	int n = this->rows_;
	std::vector<type> LMat(pow(n,2),0);
	std::vector<type> UMat(pow(n,2),0);
	for (int i = 0; i < n; i++)
	{
		// upper matrix 
		for (int k = i; k < n; k++)
		{
			int sum = 0;
			for (int j = 0; j < i; j++)
			{
				sum += (LMat[i*n+j]*UMat[j*n+k]);
			}
			UMat[i*n+k] = this->matrix_[i*n+k] - sum;
		}
		// lower matrix
		for (int k = i; k < n; k++)
		{
			if (i == k)
			{
				LMat[i*n+i] = 1;
			}
			else
			{
				int sum = 0;
				for (int j = 0; j < i; j++)
				{
					sum += LMat[k*n+j]*UMat[j*n+i];
				}
				LMat[k*n+i] = (this->matrix_[k*n+i] - sum)/UMat[i*n+i];
			}
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



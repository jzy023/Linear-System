#include "LinearSystem.H"

// PRIVATE METHODS ------------------------------------------------------------
template<class type>
Matrix<type> linearSystem<type>::ini(Matrix<type> &A, Matrix<type> &b)
{
	std::vector<std::vector<type>> ans(b.size(),1);
	for (int i = 0; i < A.size()[0]; i++)
	{
		ans[i][0] = b[i]/A(i,i);
	}
	return Matrix<type>(ans);
}

template<class type>
void linearSystem<type>::checkSys(const linearSystem<type> &s)
{
	if (s.A_.size()[0] != s.A_.size()[1] ||
		s.A_.size()[0] != s.b_.size())
	{
		throw std::domain_error("matrix has inconsistent dimensions");
	}
	if (s.b_.size()[1] != 1)
	{
		throw std::domain_error("illegal dimension for matrix b");
	}
}

// CONSTRUCTORS ---------------------------------------------------------------
template<class type>
linearSystem<type>::linearSystem(Matrix<type> &A, Matrix<type> &b)
:
A_(A),
b_(b)
{
	checkSys(*this);
	xIni_ = ini(A, b);
}

template<class type>
linearSystem<type>::linearSystem(Matrix<type> &A, Matrix<type> &b, int maxIter)
:
A_(A),
b_(b),
maxIter_(maxIter)
{
	checkSys(*this);
	xIni_ = ini(A, b);
}

template<class type>
linearSystem<type>::linearSystem(Matrix<type> &A, Matrix<type> &b, double tol)
:
A_(A),
b_(b),
tol_(tol)
{
	checkSys(*this);
	xIni_ = ini(A, b);
}

template<class type>
linearSystem<type>::linearSystem(Matrix<type> &A, Matrix<type> &b, int maxIter, double tol)
:
A_(A),
b_(b),
maxIter_(maxIter),
tol_(tol)
{
	checkSys(*this);
	xIni_ = ini(A, b);
}


// PUBLIC METHODS -------------------------------------------------------------
template<class type>
Matrix<type> linearSystem<type>::Jacobi()
{
	Matrix<type> xPrev = xIni_;
	Matrix<type> x(b_.size());
	int iter = 0;
	double err = 1;
	// while (iter < maxIter_ && err < tol_)
	// {
	// 	for (int i = 0; i < A_.size()[0]; i++)
	// 	{
	// 		type sum = 0;
	// 		for (int j = 1; j < b_.size(); j++)
	// 		{
	// 			if (i == j)
	// 			{
	// 				continue;
	// 			}
	// 			sum += A_(i,j)*xPrev(j,0); // <-- need improvement 
	// 		}
	// 		x[i] = (b_(i,0) - sum)/A_(i,i);
	// 	}
	// 	xPrev = x;

	// 	err = ();
	// 	iter++;
	// }

	return x;
}
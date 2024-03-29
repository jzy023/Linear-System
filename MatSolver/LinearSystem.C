#include "LinearSystem.H"

// PRIVATE METHODS ------------------------------------------------------------
template<class type>
Matrix<type> linearSystem<type>::ini(Matrix<type> &A, Matrix<type> &b)
{
	std::vector<std::vector<type>> ans(b.size(0),{1});
	for (int i = 0; i < A.size(0); i++)
	{
		ans[i][0] = b(i,0)/A(i,i);
	}
	return Matrix<type>(ans);
}

template<class type>
void linearSystem<type>::checkSys(const linearSystem<type> &s)
{
	if (!std::is_floating_point<type>::value)
	{
		throw std::domain_error("matrix must have floating type");
	}
	if (s.A_.size(0) != s.A_.size(1) ||
		s.A_.size(0) != s.b_.size())
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
	// checkSys(*this);
	xIni_ = ini(A, b);
}

template<class type>
linearSystem<type>::linearSystem(Matrix<type> &A, Matrix<type> &b, int maxIter)
:
A_(A),
b_(b),
maxIter_(maxIter)
{
	// checkSys(*this);
	xIni_ = ini(A, b);
}

template<class type>
linearSystem<type>::linearSystem(Matrix<type> &A, Matrix<type> &b, double tol)
:
A_(A),
b_(b),
tol_(tol)
{
	// checkSys(*this);
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
	// checkSys(*this);
	xIni_ = ini(A, b);
}


// PUBLIC METHODS -------------------------------------------------------------
template<class type>
Matrix<type> linearSystem<type>::Jcb()
{
	Matrix<type> xPrev = xIni_;
	Matrix<type> x(b_.size(0),b_.size(1));
	Matrix<type> resTemp; // <-- NEED IMPROVEMENT!!!
	int iter = 0;
	double err = 1.0;
	while (iter < maxIter_ && err > tol_)
	{
		for (int i = 0; i < A_.size(0); i++)
		{
			type sum = 0;
			for (int j = 1; j < b_.size(0); j++)
			{
				if (i == j)
				{
					continue;
				}
				sum += A_(i,j)*xPrev(j,0); // <-- NEED IMPROVEMENT!!!
			}
			x(i,0) = (b_(i,0) - sum)/A_(i,i);
		}
		xPrev = x;
		resTemp = *(A_ & x);
		resTemp -= b_;
		err = resTemp.Norm();
		iter++;
	}
	std::cout << "number of iteration: " << iter 
				  << ", local residual: " << err << "\n";
	return x;
}


template<class type>
Matrix<type> linearSystem<type>::GS()
{
	Matrix<type> x = xIni_;
	Matrix<type> resTemp;
	int iter = 0;
	double err = 1.0;
	while (iter < maxIter_ && err > tol_)
	{
		for (int i = 0; i < A_.size(0); i++)
		{
			type sum = 0;
			for (int j = 1; j < b_.size(0); j++)
			{
				if (i == j)
				{
					continue;
				}
				sum += A_(i,j)*x(j,0); // <-- NEED IMPROVEMENT!!!
			}
			x(i,0) = (b_(i,0) - sum)/A_(i,i);
		}
		resTemp = *(A_ & x);
		resTemp -= b_;
		err = resTemp.Norm();
		iter++;
	}
	std::cout << "number of iteration: " << iter 
				  << ", local residual: " << err << "\n";
	return x;
}


template<class type>
Matrix<type> linearSystem<type>::SOR(float rf)
{
	Matrix<type> x = xIni_;
	Matrix<type> resTemp;
	int iter = 0;
	double err = 1.0;
	while (iter < maxIter_ && err > tol_)
	{
		for (int i = 0; i < A_.size(0); i++)
		{
			type sum = 0;
			for (int j = 1; j < b_.size(0); j++)
			{
				if (i == j)
				{
					continue;
				}
				sum += A_(i,j)*x(j,0); // <-- NEED IMPROVEMENT!!!
			} // rf is the relaxation factor
			x(i,0) = (1 - rf)*x(i,0) + rf*(b_(i,0) - sum)/A_(i,i);
		}
		resTemp = *(A_ & x);
		resTemp -= b_;
		err = resTemp.Norm();
		iter++;
	}
	std::cout << "number of iteration: " << iter 
				  << ", local residual: " << err << "\n";
	return x;
}
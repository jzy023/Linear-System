#include "../Matrices/Matrix.C"
#include "../Matrices/SquareMatrix.C"

template<class type>
class linearSystem{

private:
	Matrix<type> A_;
	Matrix<type> b_;
	Matrix<type> xIni_;
	int maxIter_ = 1000;
	double tol_ = 1e-6;

	static void checkSys(const linearSystem<type> &s);

	Matrix<type> ini(Matrix<type> &A, Matrix<type> &b);

public:
	// constructor & destructor
	linearSystem(){};
	linearSystem(Matrix<type> &A, Matrix<type> &b);
	linearSystem(Matrix<type> &A, Matrix<type> &b, int maxIter);
	linearSystem(Matrix<type> &A, Matrix<type> &b, double tol);
	linearSystem(Matrix<type> &A, Matrix<type> &b, int maxIter, double tol);

	Matrix<type> Jcb(); // Jacobi method <-- modify to return by reference??
	Matrix<type> GS();	// GaussSeidel method
	Matrix<type> SOR(float rf);

};
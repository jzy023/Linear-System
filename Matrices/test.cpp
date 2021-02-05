#include <iostream>

// tested functionalities
#include "Matrix.C"
#include "SquareMatrix.C"
#include "SparseMatrix.C"

int main(int argc, char const *argv[])
{	
	// initiaization
	std::vector<double> M1{1,0,0,0,
					       1,1,0,0,
					       1,1,1,0,
					       1,1,1,1};
	squareMatrix<double> myMat1(4,M1);

	std::vector<std::vector<double>> M2{{2,2,1,2},
									 {1,4,7,3},
									 {1,1,2,1},
									 {4,1,2,5}};
	squareMatrix<double> myMat2(M2);

	std::vector<double> row1{1};
	std::vector<double> row2{1};
	std::vector<double> row3{1};
	std::vector<double> row4{1};
	std::vector<std::vector<double>> M3{row1,row2,row3,row4};
	Matrix<double> myMat3(M3);

	Matrix<double> myMat4 = myMat3;

	// test outputs
	std::cout << "trace of M is " << myMat1.Trace() << "\n";
	std::cout << "determinant of M is " << myMat1.Det() << "\n";

	std::cout << "-----------\n";
	Matrix<double> myMatTran(*myMat1.T());
	myMatTran.Show();

	std::cout << "-----------\n";
	myMat1 &= myMat3;
	myMat1.Show();

	std::cout << "-----------\n";
	squareMatrix<double> myMatL((*myMat2.LU())[1]);
	myMatL.Show();

	std::cout << "-----------\n";
	std::vector<long unsigned int> sparseSize = myMatTran.size();
	std::vector<std::vector<double>> sparseBuild = myMatTran.Sparse();
	sparseMatrix<double> mySpar(sparseSize,sparseBuild);
	mySpar.Show();


	return 0;
}
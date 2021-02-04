#include <iostream>

// tested functionalities
#include "Matrix.C"
#include "SquareMatrix.C"
#include "SparseMatrix.C"

int main(int argc, char const *argv[])
{	
	// initiaization
	std::vector<int> M1{1,0,0,0,
					    1,1,0,0,
					    1,1,1,0,
					    1,1,1,1};
	squareMatrix<int> myMat1(4,M1);

	std::vector<std::vector<int>> M2{{2,2,1,2},
									 {1,4,7,3},
									 {1,1,2,1},
									 {4,1,2,5}};
	squareMatrix<int> myMat2(M2);

	std::vector<int> row1{1};
	std::vector<int> row2{1};
	std::vector<int> row3{1};
	std::vector<int> row4{1};
	std::vector<std::vector<int>> M3{row1,row2,row3,row4};
	Matrix<int> myMat3(M3);

	Matrix<int> myMat4 = myMat3;

	// test outputs
	std::cout << "trace of M is " << myMat1.Trace() << "\n";
	std::cout << "determinant of M is " << myMat1.Det() << "\n";

	std::cout << "-----------\n";
	Matrix<int> myMatTran(*myMat1.T());
	myMatTran.Show();

	// std::cout << "-----------\n";
	// myMat1 &= myMat3;
	// myMat1.Show();

	std::cout << "-----------\n";
	squareMatrix<int> myMatL((*myMat2.LU())[1]);
	myMatL.Show();

	std::cout << "-----------\n";
	std::vector<long unsigned int> sparseSize = myMat1.size();
	std::vector<std::vector<int>> sparseBuild = myMat1.Sparse();
	sparseMatrix<int> mySpar(sparseSize,sparseBuild);
	for (int i = 0; i < mySpar.Ele().size(); i++)
	{
		std::cout << "idx: " << mySpar.Idx()[i]
				  << ", ele: " << mySpar.Ele()[i] << "\n";
	}


	return 0;
}
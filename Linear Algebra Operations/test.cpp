#include <iostream>

// tested functionalities
#include "Matrix.C"
#include "squareMatrix.C"

int main(int argc, char const *argv[])
{	
	// initiaization
	std::vector<int> M1{1,0,0,0,
					    1,1,0,0,
					    1,1,1,0,
					    1,1,1,1};
	squareMatrix<int> myMat1(4,M1);

	std::vector<std::vector<int>> M2{{1,1,1,1},
									 {0,1,1,1},
									 {0,0,1,1},
									 {0,0,0,1}};
	squareMatrix<int> myMat2(M2);

	std::vector<int> row1{11,12,13};
	std::vector<int> row2{21,22,23};
	std::vector<int> row3{31,32,33};
	std::vector<std::vector<int>> M3{row1,row2,row3};
	squareMatrix<int> myMat3(M3);

	Matrix<int> myMat4 = myMat3;

	// test outputs
	std::cout << "trace of M is " << myMat1.trace() << "\n";
	std::cout << "determinant of M is " << myMat1.det() << "\n";

	Matrix<int> myMatTran(*myMat3.T());
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << myMatTran.M()[i*3+j] << ", ";
		}
		std::cout << "\n";
	}

	return 0;
}
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
	squareMatrix<int> myMat(4);
	myMat.build(M1);

	std::vector<std::vector<int>> M2{{1,1,1,1},
									 {0,1,1,1},
									 {0,0,1,1},
									 {0,0,0,1}};
	squareMatrix<int> myMat2(M2);

	std::vector<int> row1{11,12,13};
	std::vector<int> row2{21,22,23};
	std::vector<std::vector<int>> M3{row1,row2};
	Matrix<int> myMat3(M3);


	// test outputs
	std::cout << "trace of M is " << myMat.trace() << "\n";
	std::cout << "determinant of M is " << myMat.det() << "\n";

	squareMatrix<int> myMatTran(*myMat.T());
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << myMatTran.getMat()[i][j] << ", ";
		}
		std::cout << "\n";
	}


	return 0;
}
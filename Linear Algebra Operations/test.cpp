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

	std::vector<int> row1{1};
	std::vector<int> row2{1};
	std::vector<int> row3{1};
	std::vector<int> row4{1};
	std::vector<std::vector<int>> M3{row1,row2,row3,row4};
	squareMatrix<int> myMat3(M3);

	Matrix<int> myMat4 = myMat3;

	// test outputs
	std::cout << "trace of M is " << myMat1.trace() << "\n";
	std::cout << "determinant of M is " << myMat1.det() << "\n";

	Matrix<int> myMatTran(*myMat1.T());
	for (int i = 0; i < myMat1.size()[0]; i++){
		for (int j = 0; j < myMat1.size()[0]; j++){
			std::cout << myMatTran.M()[i*myMat1.size()[0]+j] << ", ";
		}
		std::cout << "\n";
	}
	std::cout << "-----------\n";

	myMat1 &= myMat3;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 1; j++){
			std::cout << myMat1.M()[i*1+j] << ", ";
		}
		std::cout << "\n";
	}
	
	return 0;
}
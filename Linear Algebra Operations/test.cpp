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
	// myMat2.build(M2);

	std::vector<int> row1{11,12,13};
	std::vector<int> row2{21,22,23};
	std::vector<std::vector<int>> M{row1,row2};
	Matrix<int> myMat3(M);


	// test outputs
	std::cout << "trace of M is " << myMat.trace() << "\n";


	std::cout << "diagonal elements of M are: [";
	std::vector<int> v = myMat.diag();
	for (int i = 0; i < v.size()-1; ++i)
	{
		std::cout << v[i] << ", ";
	}
	std::cout << *(v.end()-1) << "]\n";


	std::cout << "determinant of M is " << myMat.det() << "\n";


	std::cout << "M1 + M2 = \n[";
	myMat += myMat2;
	std::vector<std::vector<int>> A = myMat.getMat();
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "[";
		for (int j = 0; j < 4; ++j)
		{
			std::cout << " " << A[i][j];
		}
		std::cout << " ]\n";
	}


	return 0;
}
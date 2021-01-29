#include <iostream>

// tested functionalities
#include "Matrix.C"
#include "squareMatrix.C"

int main(int argc, char const *argv[])
{	
	// initiaization
	std::vector<int> M{1,0,0,0,
					   1,1,0,0,
					   1,1,1,0,
					   1,1,1,1};
	squareMatrix<int> myMat(4);

	myMat.build(M);

	std::vector<int> M2{1,1,1,1,
						0,1,1,1,
						0,0,1,1,
						0,0,0,1};
	squareMatrix<int> myMat2(4);
	myMat2.build(M2);

	std::vector<int> M3{1,1,1,
						0,1,1,
						0,0,1};
	squareMatrix<int> myMat3(3);
	myMat3.build(M3);


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
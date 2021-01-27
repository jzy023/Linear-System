#include <iostream>

// tested functionalities
#include "squareMatrix.C"


int main(int argc, char const *argv[])
{	
	// initiaization
	std::vector<int> M{1,2,3,4,
					   0,1,0,2,
					   0,0,1,3,
					   2,3,1,6};
	squareMatrix<int> myMat(4);
	myMat.build(M);


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


	return 0;
}
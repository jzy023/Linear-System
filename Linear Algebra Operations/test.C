#include <iostream>
#include <vector>
#include <type_traits>

// tested functionalities
#include "matrix.C"


int main(int argc, char const *argv[])
{	
	std::vector<int> M{11,12,13,21,22,23,31,32,33};
	Matrix<int> myMat(3,3);
	myMat.build(M);

	std::cout << myMat.trace();

	
	return 0;
}
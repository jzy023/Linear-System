#include <iostream>

#include "LinearSystem.C"

int main(int argc, char const *argv[])
{
	// initiaization
	std::vector<float> M1{8,1,0,0,0,
					      0,9,0,0,0,
					      0,2,9,1,0,
					      0,0,1,8,2,
					      0,0,0,1,10};
	squareMatrix<float> myMat1(5,M1);
	// myMat1.Show();
	// std::cout << "-----------\n";

	std::vector<float> row1{1};
	std::vector<float> row2{1};
	std::vector<float> row3{1};
	std::vector<float> row4{1};
	std::vector<float> row5{1};
	std::vector<std::vector<float>> M2{row1,row2,row3,row4,row5};
	Matrix<float> myMat2(M2);
	// myMat2.Show();
	// std::cout << "-----------\n";

	linearSystem<float> mySys(myMat1, myMat2, 20);
	Matrix<float> solution = mySys.Jacobi();
	std::cout << "-----------\n";

	solution.Show();
	std::cout << "-----------\n";


	return 0;
}
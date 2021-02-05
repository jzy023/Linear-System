#include <iostream>

#include "LinearSystem.C"

int main()
{
	// initiaization
	std::vector<double> M1{8,1,0,0,0,
					      0,9,0,0,0,
					      0,2,9,1,0,
					      0,0,1,8,2,
					      0,0,0,1,10};
	squareMatrix<double> myMat1(5,M1);
	// myMat1.Show();
	// std::cout << "-----------\n";

	std::vector<double> row1{1};
	std::vector<double> row2{1};
	std::vector<double> row3{1};
	std::vector<double> row4{1};
	std::vector<double> row5{1};
	std::vector<std::vector<double>> M2{row1,row2,row3,row4,row5};
	Matrix<double> myMat2(M2);
	// myMat2.Show();
	// std::cout << "-----------\n";

	linearSystem<double> mySys(myMat1, myMat2, 20);
	Matrix<double> solution = mySys.Jacobi();
	std::cout << "-----------\n";

	solution.Show();
	std::cout << "-----------\n";


	return 0;
}
#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <math.h>
#include <vector>
#include <type_traits>
#include <algorithm>


template<class type>
class sparseMatrix
{
	static_assert(std::is_arithmetic<type>::value, "Type must be numeric");

private:
	long unsigned int rows_;
	long unsigned int cols_;
	std::vector<std::vector<type>> ele_;
	std::vector<std::vector<type>> idx_;

	static void checkMat(const sparseMatrix<type> &m);

	void clear();

	// type inner(std::vector<type> &v1, std::vector<type> &v2){
	// 	type ans = 0;
	// 	for (int i = 0; i < v1.size(); i++){
	// 		ans += v1[i]*v2[i];
	// 	}
	// 	return ans;
	// };

	// std::vector<type> outer(std::vector<type> &v1, std::vector<type> &v2){
	// 	std::vector<type> ans(v1.size()*v2.size());
	// 	for (int i = 0; i < v1.size(); i++){
	// 		for (int j = 0; j < v2.size(); j++){
	// 			ans(i*v2.size()+j) = v1[i]*v2[j];
	// 		}
	// 	}
	// 	return ans;
	// };

public:
	// constructors & destructor
	sparseMatrix(){};
	sparseMatrix(long unsigned int rows, long unsigned int cols);
	sparseMatrix(long unsigned int rows, long unsigned int cols, std::vector<std::vector<type>> &m);
	~sparseMatrix() = default;


};

#endif
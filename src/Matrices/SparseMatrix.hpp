#ifndef SparseMATRIX_H
#define SparseMATRIX_H

#include "includes.hpp"

template<class type>
class sparseMatrix
{
	static_assert(std::is_arithmetic<type>::value, "Type must be numeric");

private:
	long unsigned rows_;
	long unsigned cols_;
    std::vector<std::tuple<int, int, double>> elements_; // (row, column, value) of non-zero elements
	std::vector<type> idx_;
    std::vector<type> ele_;

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
	sparseMatrix(std::vector<long unsigned> size);
	sparseMatrix(std::vector<long unsigned> size, std::vector<std::vector<type>> &m);
	sparseMatrix(long unsigned rows, long unsigned cols);
	sparseMatrix(long unsigned rows, long unsigned cols, std::vector<std::vector<type>> &m);
	~sparseMatrix() = default;

	// getter functions
	/* int func() const -->  cannot call any non-const member functions,
	   nor can it change any member variables.*/
	inline std::vector<long unsigned> size() const { return {rows_,cols_}; }
	inline std::vector<type>& Idx() { return idx_; }
	inline std::vector<type>& Ele() { return ele_; }
	// inline std::vector<type> Row(long unsigned i) const;
	// inline std::vector<type> Col(long unsigned i) const;
	void Show() const;


};

#endif
#ifndef SparseMATRIX_H
#define SparseMATRIX_H

#include "includes.hpp"

template<class type>
class sparseMatrix
{
	static_assert(std::is_arithmetic<type>::value, "Type must be numeric");

    // A hash function for a pair of integers
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& pair) const {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };

private:

    // Memebers
	long unsigned rows_;

	long unsigned cols_;

    mutable unsigned maxRowNoneZeros_; // max num of row for non zero items

    mutable unsigned maxColNoneZeros_; // max num of col for non zero items

    // Map to store non-zero elements with their positions
    std::unordered_map<std::pair<long unsigned, long unsigned>, type, pair_hash> eleMap_;


    // Methods
    void mapEles(std::vector<std::tuple<long unsigned, long unsigned, type>> &m);

	void clear();
	
    static void checkMat(const sparseMatrix<type> &m);

public:
	// CONSTRUCTORS 
	sparseMatrix(){};

	sparseMatrix(std::vector<long unsigned> size);

    sparseMatrix(std::vector<long unsigned> size, 
                 std::vector<std::tuple<long unsigned, long unsigned, type>> &elements);

	sparseMatrix(long unsigned rows, 
                 long unsigned cols);

    sparseMatrix(long unsigned rows, 
                 long unsigned cols, 
                 std::vector<std::tuple<long unsigned, long unsigned, type>> &elements);

    // MOVE AND COPY CONSTRUCTORS
    sparseMatrix(sparseMatrix&&) noexcept {};

    // DESTRUCTOR
	~sparseMatrix() = default;

	// GETTER functions
	inline std::vector<long unsigned> size() const;

    inline std::vector<std::tuple<long unsigned, long unsigned, type>> getElements() const;

    inline type getItem(long unsigned row, long unsigned col) const;

    // SETTER functions
    void resize(long unsigned newRow, long unsigned newCol);

	// inline std::vector<type> Row(long unsigned i) const;
	// inline std::vector<type> Col(long unsigned i) const;
	void Show() const;

};

#endif
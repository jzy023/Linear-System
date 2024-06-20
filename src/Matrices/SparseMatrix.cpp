#include "SparseMatrix.hpp"

// PRIVATE METHODS ------------------------------------------------------------
template<class type>
void sparseMatrix<type>::mapEles(std::vector<std::tuple<long unsigned, long unsigned, type>> &elements)
{
    for (const auto& elem : elements) {
        eleMap_[{std::get<0>(elem), std::get<1>(elem)}] = std::get<2>(elem);
    }
}


template<class type>
void sparseMatrix<type>::clear()
{
	std::unordered_map<std::pair<long unsigned, long unsigned>, type, pair_hash>().swap(eleMap_);
	rows_ = 0;
	cols_ = 0;
}

template<class type>
void sparseMatrix<type>::checkMat(const sparseMatrix<type> &m)
{
    if (!std::is_floating_point<type>::value) {
        throw std::domain_error("Matrix must have floating point type");
    }
    if (m.eleMap_.empty()) {
        throw std::domain_error("Matrix has no elements");
    }
    
    long unsigned maxFirstInt = std::numeric_limits<long unsigned>::min();
    long unsigned maxSecondInt = std::numeric_limits<long unsigned>::min();
    for (const auto& elem : m.eleMap_) {
        auto key = elem.first;
        long unsigned firstInt = key.first;
        long unsigned secondInt = key.second;
        if (firstInt > maxFirstInt) {
            maxFirstInt = firstInt;
        }
        if (secondInt > maxSecondInt) {
            maxSecondInt = secondInt;
        }
    }
    m.maxRowNoneZeros_ = maxFirstInt;
    m.maxColNoneZeros_ = maxSecondInt;
    if (maxFirstInt >= m.rows_ || maxSecondInt >= m.cols_) {
        throw std::domain_error("Matrix elements exceed specified dimensions");
    }
}


// CONSTRUCTORS ---------------------------------------------------------------
template<class type>
sparseMatrix<type>::sparseMatrix(std::vector<long unsigned> size)
:
rows_(size[0]),
cols_(size[1])
{
	checkMat(*this);
}

template<class type>
sparseMatrix<type>::sparseMatrix(std::vector<long unsigned> size,
                                 std::vector<std::tuple<long unsigned, long unsigned, type>> &elements)
:
rows_(size[0]),
cols_(size[1])
// eles_(elements)
{
    mapEles(elements);
    checkMat(*this);
}

template<class type>
sparseMatrix<type>::sparseMatrix(long unsigned rows, long unsigned cols)
:
rows_(rows),
cols_(cols)
{
	checkMat(*this);
}

template<class type>
sparseMatrix<type>::sparseMatrix(long unsigned rows, 
								 long unsigned cols,
								 std::vector<std::tuple<long unsigned, long unsigned, type>> &elements)
:
rows_(rows),
cols_(cols)
// eles_(elements)
{
    mapEles(elements);
	checkMat(*this);
}


// PUBLIC METHODS -------------------------------------------------------------

// GETTER functions
template<class type>
inline std::vector<long unsigned> sparseMatrix<type>::size() const
{ 
    return {rows_,cols_};
}

template<class type>
inline std::vector<std::tuple<long unsigned, long unsigned, type>> sparseMatrix<type>::getElements() const
{ 
    std::vector<std::tuple<long unsigned, long unsigned, type>> elements;
    for (const auto& [key, value] : eleMap_) {
        elements.emplace_back(key.first, key.second, value);
    }
    return elements;
}

template<class type>
inline type sparseMatrix<type>::getItem(long unsigned row, long unsigned col) const
{
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("Index out of range");
    }

    auto it = eleMap_.find({row, col});
    if (it != eleMap_.end()) {
        return it->second;
    } else {
        return type(); // Return default value for type if element not found
    }
}

// GETTER functions
template<class type>
void sparseMatrix<type>::resize(long unsigned newRow, long unsigned newCol)
{
    if ( newRow < maxRowNoneZeros_ || newCol < maxColNoneZeros_)
    {
        throw std::domain_error("Can't resize matrix to have smaller dimension:(" 
                                + std::to_string(newRow) + ", " + std::to_string(newCol) + ")");
    }
    
    rows_ = newRow;
    cols_ = newCol;
}

// UTILITIES functions
template<class type>
void sparseMatrix<type>::Show() const {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Sparse Matrix Visualization");

    float scaleX = 800.0f / cols_;
    float scaleY = 800.0f / rows_;
    float dotRadius = 5.0f; // Adjust the size of the dots

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        for (const auto& [key, value] : eleMap_) {
            sf::CircleShape dot(dotRadius);
            dot.setPosition(key.second * scaleX, key.first * scaleY);
            dot.setFillColor(sf::Color::Black);
            window.draw(dot);
        }

        window.display();
    }
}

// PRE DECLARATION ------------------------------------------------------------
template class sparseMatrix<double>;
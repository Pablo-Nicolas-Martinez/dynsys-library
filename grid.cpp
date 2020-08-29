#include "vector.hpp"
#include "grid.hpp"

/* Access to private data functions */

/* Returns the dimension of the system. Note that the grid is a collection
 * of vectors of a given length, which is the dimension of the system and
 * not actually the number of points in the grid */
int grid::dimension() {
    return pDim;
}

// Returns the number of points in the grid
int grid::length() {
    return pLength;
}

/* Returns a point of the grid. It is important for possibly more general
 * structures to be induced in the grid. */
vec& grid::operator[](int pos) {
    // check the range of the position
    return pData[i];
}

// The same concept as before, matlab style
vec& grid::operator()(int pos) {
    // Check the range of the position
    return pData[i - 1];
}

// Double bracket access
double& grid::operator[](int posvec, int posarg) {
    // Typical checks and stuff
    vec& v(const vec& pData[posvec]);
    return v[posarg];
}

// Double parenthesis access
double& grid:operator()(int posvec, int posarg) {
    vec& v(const vec& pData[posvec - 1]);
    return v(posarg);
}

// Friend functions for accessing private data

// Friend functions to access private data
int GetDimension(const grid& otherGrid) {
    return pDim;
}

int GetLength(const grid& otherGrid) {
    return pLength;
}

// Definition for the constructors and destructors

// Empty constructor
grid::grid() {
    pDim = 0;
    pLength = 0;
    pData = new vec [pLength];
}

// Copy constructor
grid::grid(const grid& otherGrid) {
    pDim = otherGrid.dimension();
    pLength = otherGrid.length();
    pData = new vec [pLength];
    for (int i = 0; i < pLength; ++i) pData[i] = otherGrid[i];
}

// Constructor specifying dimension
grid::grid(int dim) {
    pDim = dim;
    pLength = 0;
    pData = new vec [pLength];
}

// Constructor specifying dimension and length
grid::grid(int dim, int length) {
    pDim = dim;
    pLength = length;
    pData = new vec [pLength];
}

// Default destructor
grid::~grid() {
    // Specify to destroy every vector and then destroy the grand pointer
}

// Binary operations between lattices

// Sum of two lattices
grid grid::operator+(const grid& otherGrid) {
    // Check agreeement of dimensions and length of grids
    g = grid(pDim, pLength);
    for (int i = 0; i < pLength; ++i) g[i] = pData[i] + otherGrid[i];
    return g;
}

// Substraction of two lattices
grid grid::operator-(const grid& otherGrid) {
    // Check agreement of dimension and length
    g = grid(pDim, pLength);
    for (int i = 0; i < pLength; ++i) g[i] = pData[i] + otherGrid[i];
    return g;
}

// Product of a lattice by a scalar
grid grid::operator*(const double& a) {
    g = grid(pDim, pLength);
    for (int i = 0; i < pLength; ++i) g[i] = pData[i] + otherGrid[i];
    return g;
}

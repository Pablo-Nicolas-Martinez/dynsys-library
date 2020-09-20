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
    return pData[pos];
}

vec grid::operator[](int pos) const {
    // Check the range of the position
    return pData[pos];
}

// The same concept as before, matlab style
vec& grid::operator()(int pos) {
    // Check the range of the position
    return pData[pos - 1];
}

/* Double bracket access
double& grid::operator[](int posvec, int posarg) {
    // Typical checks and stuff
    vec& v(const vec& pData[posvec]);
    return v[posarg];
} */

// Double parenthesis access
double& grid::operator()(int posvec, int posarg) {
    vec& v(pData[posvec - 1]);
    return v(posarg);
}

// Access operators if we have the class declared as constant

// Returns the dimension of the system, already explained
int grid::dimension() const {
    return pDim;
}

// Returns the number of points in the grid
int grid::length() const {
    return pLength;
}

// Friend functions for accessing private data

// Friend functions to access private data
int GetDimension(const grid& otherGrid) {
    return otherGrid.pDim;
}

int GetLength(const grid& otherGrid) {
    return otherGrid.pLength;
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
    pDim = otherGrid.pDim;
    pLength = otherGrid.pLength;
    pData = new vec [pLength];
    for (int i = 0; i < pLength; ++i) pData[i] = otherGrid.pData[i];
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
    // for (int i = 0; i < pLength; i++) pData[i].~vec();
    delete[] pData;
}

// Asignation operator for the grid class
grid& grid::operator=(const grid& otherGrid) {
    if (this != &otherGrid) {
        grid tmp(otherGrid);

        // Swapping memory positions
        vec* p = tmp.pData;
        tmp.pData = pData;
        pData = p;

        /* NOTE: there is no need to worry for the memory associated to the
         * copy grid tmp, as the default destructor handles the memory
         * allocated once the block ends */
        
        // The rest of the variables
        pDim = otherGrid.pDim;
        pLength = otherGrid.pLength;
    }
    return *this;
}

// Binary operators for the class

// Sum of two lattices
grid grid::operator+(const grid& otherGrid) {
    // Check agreeement of dimensions and length of grids
    grid g(pDim, pLength);
    for (int i = 0; i < pLength; ++i) g[i] = pData[i] + otherGrid.pData[i];
    return g;
}

// Substraction of two lattices
grid grid::operator-(const grid& otherGrid) {
    // Check agreement of dimension and length
    grid g(pDim, pLength);
    for (int i = 0; i < pLength; ++i) g[i] = pData[i] - otherGrid.pData[i];
    return g;
}

// Product of a lattice by a scalar
grid grid::operator*(const double& a) {
    grid g(pDim, pLength);
    for (int i = 0; i < pLength; ++i) g[i] = pData[i]*a;
    return g;
}

// Division of a lattice by a scalar
grid grid::operator/(const double& a) {
    grid g(pDim, pLength);
    for (int i = 0; i < pLength; ++i) g[i] = pData[i]/a;
    return g;
}


// Binary operators for the class

// Sum of two lattices
grid grid::operator+(const grid& otherGrid) const {
    // Check agreeement of dimensions and length of grids
    grid g(pDim, pLength);
    for (int i = 0; i < pLength; ++i) g[i] = pData[i] + otherGrid.pData[i];
    return g;
}

// Substraction of two lattices
grid grid::operator-(const grid& otherGrid) const {
    // Check agreement of dimension and length
    grid g(pDim, pLength);
    for (int i = 0; i < pLength; ++i) g[i] = pData[i] - otherGrid.pData[i];
    return g;
}

// Product of a lattice by a scalar
grid grid::operator*(const double& a) const {
    grid g(pDim, pLength);
    for (int i = 0; i < pLength; ++i) g[i] = pData[i]*a;
    return g;
}

// Division of a lattice by a scalar
grid grid::operator/(const double& a) const {
    grid g(pDim, pLength);
    for (int i = 0; i < pLength; ++i) g[i] = pData[i]/a;
    return g;
}

#include "grid.hpp"
// #include "vector.hpp" NOTE: already included in header

Grid::Grid() : pLength(), pData() { }

Grid::Grid(const Grid& grid) : pLength(grid.pLength), pData(new Vec[pLength]) {
    for (int i = 0; i < pLength; ++i) pData[i] = grid.pData[i];
}

//NOTE: See note in hpp
// Grid::Grid(int dim) {
//     pDim = dim;
//     pLength = 0;
//     pData = new Vec [pLength];
// }

Grid::Grid(int dim, int length) : pLength(length), pData(new Vec[pLength]) { }

// Default destructor
Grid::~Grid() {
    //NOTE: About the following... delete[] already calls the destructors
    // Specify to destroy every Vector and then destroy the grand pointer
    delete[] pData;
}

//TODO: check ranges in matlab's style operators

Vec& Grid::operator()(int i) {
    return pData[i - 1];
}

const Vec& Grid::operator()(int i) const {
    return pData[i - 1];
}

double& Grid::operator()(int i, int j) {
    //NOTE: why was this here?
    //Vec& v(const Vec& pData[i]);
    //return v[j];
    return pData[i-1](j);
}

double Grid::operator()(int i, int j) const {
    return pData[i-1](j);
}

Grid& Grid::operator=(const Grid& grid) {
    if (this != &grid) {
        pLength = grid.pLength;
        for (int i = 0; i < pLength; ++i) pData[i] = grid.pData[i];
    }
    return *this;
}

// Binary operators for the class
//TODO: Check agreeement of dimensions and length of Grids in all operators
//NOTE: dimension is already checked in the vectors

Grid& Grid::operator+=(const Grid& grid) {
    for (int i = 0; i < pLength; ++i) pData[i] = pData[i] + grid.pData[i];
    return *this;
}

Grid& Grid::operator-=(const Grid& grid) {
    for (int i = 0; i < pLength; ++i) pData[i] = pData[i] - grid.pData[i];
    return *this;
}

Grid& Grid::operator*=(const double& d) {
    for (int i = 0; i < pLength; ++i) pData[i] = pData[i] * d;
    return *this;
}

Grid& Grid::operator/=(const double& d) {
    for (int i = 0; i < pLength; ++i) pData[i] = pData[i] / d;
    return *this;
}

// Norms and seminorms on Grids

Vec HoldNorm(const Grid& g, double p) {
    Vec v(g.length());
    for (int i = 0; i < g.length(); ++i) v[i] = HoldNorm(g[i], p);
    return v;
}

Vec HoldSemiNorm(const Grid& g, double p) {
    Vec v(g.length());
    for (int i = 0; i < g.length(); ++i) v[i] = HoldSemiNorm(g[i], p);
    return v;
}

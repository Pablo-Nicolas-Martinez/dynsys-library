#include "vector.hpp"
#include <cmath>

/* Basic access operators to private data */

int vec::length() {
    return pLength;
}

double& vec::operator[](int pos) {
    // Check if 0 <= i < pLength
    return pData[pos];
}

double& vec::operator()(int pos) {
    // Check if 0 < i <= pLength
    return pData[pos - 1];
}

int GetLength(const vec& otherVec) {
    return otherVec.pLength;
}

/* Constructors and destructors for the class */

// Default copy constructor for the class
vec::vec(const vec& otherVec) {
    pLength = otherVec.pLength;
    pData = new double [pLength];
    for (int i = 0; i < pLength; ++i) {
        pData[i] = otherVec.pData[i];
    }
}

// Empty initializer given the dimension
vec::vec(const int& dim) {
    pLength = dim;
    pData = new double [dim];
}

// Default destructor for the class
vec::~vec() {
    delete[] pData;
}

/* Definition of binary operators */

// Assgination operator, NOT the copy constructor
vec& vec::operator=(const vec& otherVec) {
    // Check if lengths agree
    for (int i = 0; i < pLength; ++i) pData[i] = otherVec.pData[i];
    return *this;
}

// Binary addition of vectors
vec vec::operator+(const vec& otherVec) {
    // Check if the lengths of both vectors agree
    vec v(pLength);
    for (int i = 0; i < pLength; ++i) v[i] = pData[i] + otherVec.pData[i];
    return v;
}

// Binary substraction of vectors
vec vec::operator-(const vec& otherVec) {
    // Check if lengths agree
    vec v(pLength);
    for (int i = 0; i < pLength; ++i) v[i] = pData[i] + otherVec.pData[i];
    return v;
}

// Product by a scalar
vec vec::operator*(const double& a) {
    vec v(pLength);
    for (int i = 0; i < pLength; ++i) v[i] = a*pData[i];
    return v;
}

/* Holder norms and seminorms */

// Definition of Holder norm
double vec::HoldNorm(const unsigned int& p) {
    double sum = 0;
    for (int i = 0; i < pLength; ++i) sum += pow(pData[i], p);
    return sqrt(sum); // TODO: Arreglar la raiz p-esima para el valor
}

// Definition of Holder seminorm
double vec::HoldSemiNorm(const unsigned int& p) {
    double sum = 0;
    for (int i = 1; i < pLength; ++i) sum += pow(pData[i], p);
    return sqrt(sum);
}


#include "vec.hpp"
#include <cmath>
#include <cstring>

//NOTE: I wonder whether this type of "obvious" info needs to be here.
// I assume people usually see when they are reading a constructor.
/* Constructors and destructors for the class */

// Default empty constructor for the class
//NOTE: A colon is the way to initilize when reserving the memory.
// Initilizing inside the function means the objects have been
// default initilized.
Vec::Vec() : pLength(), pData() { } //NOTE: You were reserving 0 memmory?

// Default copy constructor for the class
Vec::Vec(const Vec& vec) : pLength(vec.pLength), pData(new double[pLength]) {
    std::memcpy(pData, vec.pData, pLength * sizeof(double));
    //NOTE: Before:
    // for (int i = 0; i < pLength; ++i) pData[i] = vec.pData[i];
}

// Empty initializer given the dimension
Vec::Vec(int length) : pLength(length), pData(new double[pLength]) { }

// Default destructor for the class
Vec::~Vec() {
    delete[] pData;
}

//TODO: add checks for matlab's operators

double& Vec::operator()(int i) {
    return pData[i-1];
}

double Vec::operator()(int i) const {
    return pData[i-1];
}

// Default assignation operator
Vec& Vec::operator=(const Vec& vec) {
    //NOTE: Maybe you want to add a size check
    //NOTE: Do you know why you write this?
    if (this != &vec) {
        // Vec tmp(vec); //NOTE: Unnecessary, just delete your memmory
        // But maybe a good book says otherwise. I think this may be slower.
        delete[] pData;
        pLength = vec.pLength;
        pData = new double[pLength];
        std::memcpy(pData, vec.pData, pLength * sizeof(double));
    }
    return *this;
}

/* Definition of binary operators */
//TODO Check if the lengths of both Vectors agree in operators
// Binary addition of Vectors //NOTE: like: obvious

Vec& Vec::operator+=(const Vec& vec) {
    for (int i = 0; i < pLength; ++i) pData[i] += vec.pData[i];
    return *this;
}

Vec& Vec::operator-=(const Vec& vec) {
    for (int i = 0; i < pLength; ++i) pData[i] -= vec.pData[i];
    return *this;
}

Vec& Vec::operator*=(double d) {
    for (int i = 0; i < pLength; ++i) pData[i] *= d;
    return *this;
}

Vec& Vec::operator/=(double d) {
    for (int i = 0; i < pLength; ++i) pData[i] /= d;
    return *this;
}

/* Holder norms and seminorms */

// Definition of Holder norm
double HoldNorm(const Vec& v, double p) {
    double sum = 0;
    for (int i = 0; i < v.length(); ++i) sum += pow(v[i], p);
    return sqrt(sum);
}

double HoldSemiNorm(const Vec& v, double p) {
    double sum = 0;
    for (int i = 1; i < v.length(); ++i) sum += pow(v[i], p);
    return sqrt(sum);
}


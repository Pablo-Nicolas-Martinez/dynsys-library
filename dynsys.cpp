#include "vector.hpp"
#include "grid.hpp"
#include "dynsys.hpp"

// Function access to the private data of the class

// Evaluate the function of the system in a given point
vec DynSys::evaluate(const vec& p) {
    // Check if the dimension of the system agrees with the lenght of the vector
    return pF(p);
}

// Return the dimension of the dynamical system
int DynSys::dimension() {
    return pDim;
}

// Checks if the given point belongs to the domain of the system
bool DynSys::isDomain(const vec& p) {
    return pDomain(p);
}

// Constructors and destructors of the class

// Default copy constructor
DynSys::DynSys(const DynSys& otherSys) {
    pF = otherSys.pF; // Pointer aliasing ???
    pDim = otherSys.pDim;
    pDomain = otherSys.pDomain;
}

// Constructor with parameters specified
DynSys::DynSys(vec (*fun)(const vec& p), int dim, bool (*dom)(const vec& p)) {
    pF = fun;
    pDim = dim;
    pDomain = dom;
}

// Default destructor
DynSys::~DynSys() {
    //delete pF;
    //delete pDomain;
}

// Asignation operator for the class
DynSys& DynSys::operator=(const DynSys& otherSys) {
    if (this != &otherSys) {
        // Temporary system for the swap of pointers
        DynSys tmp(otherSys);
        
        /// Is it really necessary???

        // Swap pointers to function
        vec (*tmpf)(const vec& p) = tmp.pF;
        tmp.pF = pF;
        pF = tmpf;

        // Swap pointers to domain
        bool (*tmpdom)(const vec& p) = tmp.pDomain;
        tmp.pDomain = pDomain;
        pDomain = tmpdom;
    }
    return *this;
}

// Extension of default functions to grids of vectors

// Extension of ode function to a grid
grid DynSys::evalGrid(const grid& otherGrid) {
    // Check that the dimension of the grid agrees with that of the system
    grid g(otherGrid.dimension(), otherGrid.length());
    int length = otherGrid.length();
    for (int i = 0; i < length; ++i) g[i] = otherGrid[i];
    return g;
}

/* Extension of the domain function to a grid.
 * At the moment the implementation is over a whole grid and returns true
 * iff every point returns true. It can be changed in the future to return
 * a boolean grid asociated to the one we have now. */
bool DynSys::isDomainGrid(const grid& otherGrid) {
    // Check that dimensions agree
    int length = otherGrid.length();
    for (int i = 0; i < length; ++i) 
        if(not isDomain(otherGrid[i])) return false;
    return true;
}

// Numeric integrators
vec DynSys::RK4(const vec& initCond, double dt) {
    vec k1(evaluate(initCond));
    vec k2(evaluate(initCond + k1*(dt/2)));
    vec k3(evaluate(initCond + k2*(dt/2)));
    vec k4(evaluate(initCond + k3*dt));
    return vec(initCond + k1/6 + k2/3 + k3/3 + k4/6);
}

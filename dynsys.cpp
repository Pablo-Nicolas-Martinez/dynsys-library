#include "dynsys.hpp"

// Function access to the private data of the class

// Evaluate the function of the system in a given point
Vec DynSys::evaluate(const Vec& p) {
    // Check if the dimension of the system agrees with the length of the vector
    return pF(p);
}

// Return the dimension of the dynamical system
int DynSys::dimension() {
    return pDim;
}

// Checks if the given point belongs to the domain of the system
bool DynSys::isDomain(const Vec& p) {
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
DynSys::DynSys(Vec (*fun)(const Vec& p), int dim, bool (*dom)(const Vec& p)) {
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
        Vec (*tmpf)(const Vec& p) = tmp.pF;
        tmp.pF = pF;
        pF = tmpf;

        // Swap pointers to domain
        bool (*tmpdom)(const Vec& p) = tmp.pDomain;
        tmp.pDomain = pDomain;
        pDomain = tmpdom;
    }
    return *this;
}

// Extension of default functions to grids of vectors

// Extension of ode function to a grid
Grid DynSys::evaluate(const Grid& otherGrid) {
    // Check that the dimension of the Grid agrees with that of the system
    Grid g(otherGrid.dimension(), otherGrid.length());
    int length = otherGrid.length();
    for (int i = 0; i < length; ++i) g[i] = evaluate(otherGrid[i]);
    return g;
}

/* Extension of the domain function to a grid.
 * At the moment the implementation is over a whole grid and returns true
 * iff every point returns true. It can be changed in the future to return
 * a boolean grid asociated to the one we have now. */
bool DynSys::isDomainGrid(const Grid& otherGrid) {
    // Check that dimensions agree
    int length = otherGrid.length();
    for (int i = 0; i < length; ++i) 
        if(not isDomain(otherGrid[i])) return false;
    return true;
}

// Numeric integrators
Vec DynSys::RK4(const Vec& initCond, double dt) {
    Vec k1(evaluate(initCond));
    Vec k2(evaluate(initCond + k1*(dt/2)));
    Vec k3(evaluate(initCond + k2*(dt/2)));
    Vec k4(evaluate(initCond + k3*dt));
    return Vec(initCond + k1*(dt/6) + k2*(dt/3) + k3*(dt/3) + k4*(dt/6));
}

Grid DynSys::RK4(const Grid& initStep, double dt) {    
    Grid k1(evaluate(initStep));
    Grid k2(evaluate(initStep + k1*(dt/2)));
    Grid k3(evaluate(initStep + k2*(dt/2)));
    Grid k4(evaluate(initStep + k3*dt));
    return Grid(initStep + k1*(dt/6) + k2*(dt/3) + k3*(dt/3) + k4*(dt/6));
}

// Lagrange functions for vectors and grids

/* The following lines of code contain a possible implementation of the
 * Lagrange function, which applies the Lagrange function to each vector of
 * the grid passed as parameter. Another option is to apply a Runge-Kutta
 * method directly on the grid and compute directly the increments. Probably
 * it will not be able to return a vector, unless the norm is defined as a
 * function on the grid class which returns a vector. It would be more
 * appropriate to return a scalar grid, as the internal structure of the space
 * is preservec */

// Lagrange function of a given point in the domain
double DynSys::LagrFunction(const Vec& initCond, double tau, double dt) {
    // Check if the point belongs to the domain, if contrary throw an exception
    
    // Setting up two initial conditions for two-sided integration
    Vec posP = initCond;
    Vec negP = initCond;
    double sum = HoldSemiNorm(evaluate(initCond), 2);
    int numit = tau/dt;

    for (int i = 0; i < numit; ++i) {
        posP = RK4(posP, dt);
        negP = RK4(negP, -dt);
        sum += (HoldSemiNorm(evaluate(posP), 2) + HoldSemiNorm(evaluate(negP), 2))*dt;
    }

    return sum;
}

Vec DynSys::LagrFunction(const Grid& baseState, double tau, double dt) {
    int length = baseState.length();
    Vec v(length);
    for (int i = 0; i < length; ++i) {
        v[i] = LagrFunction(baseState[i], tau, dt);
    }
    return v;
}


#ifndef DYNSYSHEADER
#define DYNSYSHEADER

#include "vector.hpp"
#include "grid.hpp"

//NOTE: DIY
class DynSys {
    private:
        function f; // Function that defines the evolution of the system. We work with it as an autonomous system, i.e., f = f(t, x); TODO: Define two functions which can operate on grids and on points.
        int pDim; // Dimension of the system, taking into account time as a variable.
        bool function domain; // A boolean function which returns if a point is inside the specified domain

    public:
        // Access to private data from the system
        vec evaluate(const vec& pos);
        int dimension();
        bool isDomain(const vec& pos);

        // Default, copy and more constructors and default destructor
        DynSys();
        DynSys(function f, int pDim, bool function domain);
        ~DynSys();

        // Numeric integrators and Lagrange functions
        grid RungeKutta(const grid& initStep);
        grid LagrFunction(const grid& baseState);
        // Declarators from scratch and from netcdf files. Declarator from netcdf file has to implement interpolation on 
        // General destructor
}

#endif 

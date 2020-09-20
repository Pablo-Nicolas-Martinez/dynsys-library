#ifndef DYNSYSHEADER
#define DYNSYSHEADER

#include "vector.hpp"
#include "grid.hpp"

class DynSys {
    private:
        vec (*pF)(const vec& p); 
        int pDim; // Dimension of the system, taking into account time as a variable.
        bool (*pDomain)(const vec& p); 
    public:
        // Access to private data from the system
        vec evaluate(const vec& p);
        int dimension();
        bool isDomain(const vec& p);

        // Default, copy and more constructors and default destructor
        DynSys(const DynSys& otherSys);
        DynSys(vec (*f)(const vec& p), int dim, bool (*domain)(const vec& p));
        ~DynSys();
        DynSys& operator=(const DynSys& otherSys);

        // Extension of the default functions to grids
        grid evaluate(const grid& otherGrid);
        bool isDomainGrid(const grid& otherGrid);

        // Numeric integrators and Lagrange functions
        vec RK4(const vec& initCond, double dt);
        //vec RungeKutta(const vec& initCond, double dt);
        double LagrFunction(const vec& initCond, double tau, double dt);

        // Extension of the 
        grid RK4(const grid& initStep, double dt);
        vec LagrFunction(const grid& baseState, double tau, double dt);
        
        // Declarators from scratch and from netcdf files. Declarator from netcdf file has to implement interpolation on 
        // General destructor
};

#endif 

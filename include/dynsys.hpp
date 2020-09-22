#ifndef DYNSYS_DYNSYS_HPP_
#define DYNSYS_DYNSYS_HPP_

#include "vec.hpp"
#include "grid.hpp"

//NOTE: DIY
class DynSys {
    private:
        Vec (*pF)(const Vec& p); 
        int pDim; // Dimension of the system, taking into account time as a variable.
        bool (*pDomain)(const Vec& p); 

    public:
        // Access to private data from the system
        Vec evaluate(const Vec& p);
        int dimension();
        bool isDomain(const Vec& p);

        // Default, copy and more constructors and default destructor
        DynSys(const DynSys& otherSys);
        DynSys(Vec (*f)(const Vec& p), int dim, bool (*domain)(const Vec& p));
        ~DynSys();
        DynSys& operator=(const DynSys& otherSys);

        // Extension of the default functions to grids
        Grid evaluate(const Grid& otherGrid);
        bool isDomainGrid(const Grid& otherGrid);

        // Numeric integrators and Lagrange functions
        Vec RK4(const Vec& initCond, double dt);
        //Vec RungeKutta(const Vec& initCond, double dt);
        double LagrFunction(const Vec& initCond, double tau, double dt);

        // Extension of the 
        Grid RK4(const Grid& initStep, double dt);
        Vec LagrFunction(const Grid& baseState, double tau, double dt);
        
        // Declarators from scratch and from netcdf files. Declarator from netcdf file has to implement interpolation on 
        // General destructor
};

#endif // DYNSYS_DYNSYS_HPP_


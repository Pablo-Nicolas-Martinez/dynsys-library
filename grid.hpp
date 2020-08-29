#ifndef GRIDHEADER
#define GRIDHEADER

#include "vector.hpp"

class grid {
    private:
        vec* pData;
        int pDim;
        int pLength;

        // Declaration of 2D types of grids
        //bool orthogonal;
        //bool polar;

        //bool cylindrical;
    public:
        // Access to private data operators and functions
        int dimension();
        int length();
        vec& operator[](int pos);
        vec& operator()(int pos);
        double& operator[](int posvec, int posarg);
        double& operator()(int posvec, int posarg);

        // Friend functions for the dimension and length of th system
        friend int GetDimension(const grid& otherGrid);
        friend int GetLength(const grid& otherGrid);
        
        // Empty, copy, and both arguments constructors, default destructor
        grid();
        grid(const grid& otherGrid);
        grid(int dim);
        grid(int dim, length);
        ~grid();

        // Operations to push and remove the last point of a grid (dynamic memory allocation)
        
        // Define the sum of two grids of the same size for Runge Kutta integration
        grid operator+(const grid& otherGrid);
        grid operator-(const grid& otherGrid);
        grid operator*(const double& a);

        // Declarations of rectilinear grids (???)
        // Declare it on the appropriate constructors
};

#endif

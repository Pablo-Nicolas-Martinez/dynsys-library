#ifndef DYNSYS_GRID_HPP_
#define DYNSYS_GRID_HPP_

#include "vec.hpp"
//NOTE: grids allow to assign to their vectors.
// Vector assignment allows to change dimension.
// The grid may end up with a different dimension for different points.

//NOTE: Initially not labeled as todo.
// Shorter description: Transform into a template.
//TODO: type T; // To define in the future for supporting different types of variables
class Grid {
    private:
        int pLength;
        int pDim;
        Vec* pData;

        //NOTE: maybe remove?
        // Declaration of 2D types of Grids
        //bool orthogonal;
        //bool polar;

        //bool cylindrical;

    public:
        // Empty, copy, and both arguments constructors, default destructor
        Grid();
        Grid(const Grid& otherGrid);
        Grid(int dim); //NOTE: What?
        Grid(int dim, int length);
        ~Grid();

        inline int length() const { return pLength; }
        /*inline int dimension() const {
            return pLength == 0? 0 : pData[0].length();
        }*/
        inline int dimension() const { return pDim; }
        inline Vec& operator[](int i) { return pData[i]; }
        inline Vec operator[](int i) const { return pData[i]; }

        // Accessors for MatLab users that prefer 1-indexing and bound check
        Vec& operator()(int i);
        //NOTE: here in the const version we return const ref, not a value.
        const Vec& operator()(int i) const;

        double& operator()(int i, int j);
        double operator()(int i, int j) const;


        //TODO: Operations to push and remove the last point of a Grid (dynamic memory allocation) (vector?)
        
        //TODO: Define the sum of two Grids of the same size for Runge Kutta integration
        Grid& operator=(const Grid& otherGrid);
        Grid& operator+=(const Grid& otherGrid);
        Grid& operator-=(const Grid& otherGrid);
        Grid& operator*=(const double& d);
        Grid& operator/=(const double& d);

        //TODO: Declarations of rectilinear Grids (???)
        //TODO: Declare it on the appropriate constructors
};

inline Grid& operator+(Grid lhs, const Grid& rhs) { return lhs+=rhs; }
inline Grid& operator-(Grid lhs, const Grid& rhs) { return lhs-=rhs; }
inline Grid& operator*(Grid v, double d) { return v*=d; }
inline Grid& operator/(Grid v, double d) { return v/=d; }

// Vector declaration of norms and seminorms on Grids, a natural
// extension component-wise of the ones defined for Vectors

//NOTE: why unsiged?
Vec HoldNorm(unsigned int p); //NOTE: const unsigned int& -> usigned int
Vec HoldSemiNorm(unsigned int p);

#endif // DYNSYS_GRID_HPP_


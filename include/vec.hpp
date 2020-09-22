#ifndef DYNSYS_VEC_HPP_
#define DYNSYS_VEC_HPP_
//NOTE: Why was the file called vector.hpp when defines vec?

//NOTE: Interesting read: https://google.github.io/styleguide/cppguide.html#Copyable_Movable_Types
class Vec {
    private:
        int pLength;
        double* pData;

    public:
        Vec();
        Vec(int length); //NOTE: const int& -> int
        Vec(const Vec& vec); //NOTE: otherVec -> simply vec
        ~Vec();
        //TODO: Declaration of a Vector from file, sparse or full
        //NOTE: Shall this belong to the class?

        //NOTE: Made inline
        inline int length() const { return pLength; }
        //NOTE: Only a mutator and a non-mutator operators are needed
        inline double& operator[](int i) { return pData[i]; }
        inline double operator[](int i) const { return pData[i]; }

        double& operator()(int i);
        double operator()(int i) const;
        
        // Definition of the given binary operations of sum and product by a scalar
        Vec& operator=(const Vec& vec);
        Vec& operator+=(const Vec& vec);
        Vec& operator-=(const Vec& vec);
        Vec& operator*=(double a); //NOTE const double& -> double
        Vec& operator/=(double a);

};

inline Vec& operator+(Vec lhs, const Vec& rhs) { return lhs+=rhs; }
inline Vec& operator-(Vec lhs, const Vec& rhs) { return lhs-=rhs; }
inline Vec& operator*(Vec v, double d) { return v*=d; }
inline Vec& operator/(Vec v, double d) { return v/=d; }

// TODO: Possibly add euclidian norms, associated to a scalar product
//NOTE: This were appropiate as external functions
// Holder norms and seminorms
double HoldNorm(const Vec& v, double p);
double HoldSemiNorm(const Vec& v, double p);

#endif // DYNSYS_VEC_HPP_


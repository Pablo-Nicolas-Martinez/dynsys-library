#ifndef VECHEADER
#define VECHEADER

class vec {
    private:
        double* pData;
        int pLength;
    public:
        // Basic access operators
        int length();
        double& operator[](int pos);
        double& operator()(int pos);

        // Friend access operators
        friend int GetLength(const vec& otherVec);

        // Definition of the default copy constructor and initialize with dimension
        vec();
        vec(const vec& otherVec);
        vec(const int& dim);
        ~vec();
        vec& operator=(const vec& otherVec);
        // TODO: Declaration of a vector from file, sparse or full
        
        // Definition of the given binary operations of sum and product by a scalar
        vec operator+(const vec& otherVec);
        vec operator-(const vec& otherVec);
        vec operator*(const double& a);
        
        // Holder norms and seminorms
        // TODO: Possibly add euclidian norms, associated to a scalar product
        double HoldNorm(const unsigned int& p);
        double HoldSemiNorm(const unsigned int& p); // useful for the M function
        friend double HoldNorm(const vec& v, double p);
        friend double HoldSemiNorm(const vec& v, double p);
};

#endif

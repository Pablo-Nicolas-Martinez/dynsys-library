# dynsys-library

Hello there! Welcome to the Github repository where 

## Structure of the repository

This section aims to describe the internal structure of the different files in the repository. It also intends to show the different goals that every class accomplishes and the implementation of routines to fulfill them. The following picture should describe (at least in a rather simplistic way) the dependencies between the declared classes.

% Include picture

* **Vector:** This is the base class for the whole code. Its objetctive is to represent points of an affine space, which is the base space that dynamical systems will act on, and also arbitrary vectors that can act on points by translation. These reasons us to define the following set of variables for the class.
    * *Private data:* The only private data for the class is the length of the vector and the data stored. As vectors are used to represent points of an affine space, we will not allow the dimension of the vector to change once it has been declared.
    * *Access functions to private data:* These functions allow the user to read the private data and possibly change it. We have discussed that the length of a vector will not change once it has been declared, and thus functions that allocate memory dinamically are not needed. The implementation provides a function to read the length of a vector and also a friend function which fulfills the same purpose. Operators to access the data stored inside the vector are also declared. These operators can also modify the read data.
    * *Constructors and destructors:* The copy constructor is defined to allocate the necessary memory for the vector class. There is also a constructor which admits the length of the vector as an argument and allocates memory accordingly. The default destructor frees the memory reserved by the class.
    * *Algebraic operations:* As one of the objetives of the class is to provide an accurate representation of finite, real-valued vectors, the operations known for these vectors must also be declared in the class. These operations will allow us to extend them to the grid class, on which we will perform numerical integration techniques like Runge-Kutta. Only basic operations like addition, substraction and product by a scalar are needed.
    * *Norm declaration:* General Hölder norms are declared because they will be needed for the computation of the Lagrange function of a dynamical system. As with access functions to private data, both class and friend functions are provided. There is also a declaration of a seminorm which will be important because it ignores the first component of the vector. The *raison d'être* for this function will be explained inside the DynSys class.
There are some functionalities which could also be implemented in the class. Constructors from file, whether full or sparse.
* **Grid:** This class provides the implementation of a grid of points of an affine space. Technically, this class is not necessary for the development of the rest of the code, but it provides an interface to perform simultaneous numerical integration on a collection of points with a set of centralized functions.
    * *Private data:* The private data for the class is composed by the length of the grid, the dimension of the underlying space and the actual collection of points in the space. The collection of points is implemented as a pointer to the class of vectors defined before. The length variable represents the amount of points inside the grid, while the dimension is the length of the vectors stored inside the grid. Note that, as the information stored inside the grid are points of an affine space, it is natural that all of them share the same dimension. As before, we have no interest in allocating memory dynamically.
    * *Access functions to private data:* As in the vector class, we provide class and friend functions to read the length and dimension variables. Some operators for accessing vectors inside the class and particular components of said vectors are also implemented.
    * *Constructors and destructors:* As in the vector class, we implement the default copy constructor and a constructor with specified length and dimension. Both allocate the necessary memory for the class. The default destructor frees the memory previously reserved.
    * *Arithmetic operations:* The arithmetic operations defined for grids are mere extensions of the ones already declared for the vector class. The philosphy is the same as in the grid class description: these operations are not intrinsically necessary, but they provide a comfortable implementation of numerical methods on sets of points.
Todo: add additional structure to rectilinear and polar grids.
* **Dynamical system:** This class is an abstract representation of a differential equation.
    * *Private data:* The private data for this class, that is, the information that defines a differential equation is the evolution function f, which acts on a vector, the dimension of the underlying space and the domain of the equation. In this case the domain is not implemented explicitly, but is rather provided by means of a boolean function which decides if a point belongs to the domain.
    * *Access functions to private data:*
    * *Constructors and destructors:*
    * *Numerical integrators and Lagrange functions:*
To do:......

## Support and thanks

This library has been developed for the course ''Dynamical Systems and applications'', which ....

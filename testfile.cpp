#include <iostream>
#include "dynsys.hpp"
#include "wrappers.hpp"

bool DuffDomain(const Vec& p) {
    // Check that the dimension is actually 3
    return true;
}

Vec DuffFunction(const Vec& p) {
    Vec v(3);
    v[0] = 1.0;
    v[1] = p[2];
    v[2] = p[1] - p[1]*p[1]*p[1];
    return v;
}

int main() {

    // Vector class testing
    
    // Declaration testing
    Vec v(3);
    v[0] = 3;
    v[1] = 0;
    v[2] = 4;

    for (int i = 0; i < 3; ++i) std::cout << v[i] << ' ';
    std::cout << '\n';

    // Holder norms and seminorms declaration
    std::cout << "The 2-Holder norm of the Vector is " << HoldNorm(v, 2) << '\n';
    std::cout << "The 2-Holder semi-norm of the Vector is " << HoldSemiNorm(v, 2) << '\n';

    std::cout << "The length of the Vector is " << v.length() << std::endl;
    std::cout << "The length by the friend function is " << GetLength(v) << std::endl;

    Vec b(3);
    b[1] = 5;

    // Testing empty constructor, binary operations and asignation operator
    Vec u = v + b;

    for (int i = 0; i < 3; ++i) std::cout << u[i] << ' ';
    std::cout << std::endl;
    
    // Grid class testing
    Grid g(3, 3);
    std::cout << "The length of the grid is " << g.length() << std::endl;
    std::cout << "The length of the grid is " << GetLength(g) << std::endl;
    std::cout << "The dimension of the grid is " << g.dimension() << std::endl;
    std::cout << "The dimension of the grid is " << GetDimension(g) << std::endl;

    // Testing
    std::cout << "Hasta aquí llego" << std::endl;

    // Grid values assignation
    g[0] = v;
    g[1] = b;
    g[2] = u;

    // Testing
    std::cout << "Hasta aquí llego" << std::endl;

    std::cout << g.length() << std::endl;
    std::cout << g.dimension() << std::endl;

    std::cout << g[0].length() << std::endl;

    // Value outputting
    for (int i = 0; i < g.length(); ++i) {
        std::cout << "He hecho una iteración" << std::endl;
        for (int j = 0; j < g.dimension(); ++j) std::cout << g[i][j] << ' ';
        std::cout << std::endl;
    }

    // El problema está en el bucle
    // Puede que nos estemos pasando de dimensión?

    // Testing
    std::cout << "Hasta aquí llego" << std::endl;

    // More grid declaration with copy and modification
    Grid h = Grid(3, 3);

    // Testing
    std::cout << "Hasta aquí llego" << std::endl;

    Vec zero(3);
    zero[0] = 0;
    zero[1] = 0;
    zero[2] = 0;
    
    h[0] = zero;
    h[1] = zero;
    h[2] = v;

    Grid f(3, 3);
    f = (g - h)/2;

    // Testing
    std::cout << "Hasta aquí llego" << std::endl;

    // Value outputting
    for (int i = 0; i < f.length(); ++i) {
        for (int j = 0; j < f.dimension(); ++j) std::cout << f[i][j] << ' ';
        std::cout << std::endl;
    }
    
    // Testing the functions for the duffing equation
    Vec fpoint(3);
    fpoint[0] = 0;
    fpoint[1] = 1;
    fpoint[2] = 0;
    Vec disp(DuffFunction(fpoint));
    std::cout << "Does the point belong in the domain? " << DuffDomain(fpoint) << std::endl;
    std::cout << "The components of the function Vector are given by" << std::endl;
    for (int i = 0; i < 3; ++i) std::cout << disp[i] << ' ';
    std::cout << std::endl << std::endl;

    // Testing
    std::cout << "Hasta aquí llego" << std::endl;
    
    // Testing the class declaration and Runge-Kutta methods
    DynSys Duffing(DuffFunction, 3, DuffDomain);
    Vec image = Duffing.evaluate(fpoint);

    // The same as before but with the declared class
    std::cout << "Does the point belong in the domain? "
              << Duffing.isDomain(fpoint)
              << std::endl;
    std::cout << "What is the actual point in the domain?" << std::endl;
    for (int i = 0; i < 3; ++i) std::cout << fpoint[i] << ' ';
    std::cout << std::endl;
    
    std::cout << "What is the actual image of the point?" << std::endl;
    for (int i = 0; i < 3; ++i) std::cout << image[i] << ' ';
    std::cout << std::endl; 

    Vec nextiter = Duffing.RK4(fpoint, 0.1); 

    std::cout << "What is the next iterate by means of the Runge-Kutta method?" << std::endl;
    for (int i = 0; i < 3; ++i) std::cout << nextiter[i] << ' ';
    std::cout << std::endl << std::endl; 

    // Testing the action on a grid by a Runge-Kutta method

    Grid DuffGrid(3, 3);
    
    Vec p1 = fpoint;
    Vec p2(3);
    Vec p3(3);

    p2[0] = 0;
    p2[1] = 0;
    p3[0] = 0;

    p3[0] = 0;
    p3[1] = 0.5;
    p3[2] = 0.2;

    DuffGrid[0] = p1;
    DuffGrid[1] = p2;
    DuffGrid[2] = p3;

    // Printing the grid to see the actual points
    for (int i = 0; i < 3; ++i) {
        Vec temp = DuffGrid[i];
        // Printing each actual vector
        for (int j = 0; j < 3; ++j) std::cout << temp[j] << ' ';
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // Declaring the grid obtanined by a Runge-Kutta iteration
    Grid DuffNext = Duffing.RK4(DuffGrid, 0.1);

    // Printing the next grid to see if it works
    for (int i = 0; i < 3; ++i) {
        Vec temp = DuffNext[i];
        // Printing each actual vector
        for (int j = 0; j < 3; ++j) std::cout << temp[j] << ' ';
        std::cout << std::endl;
    }

    std::cout << "The Lagrange function of the fixed point is "
              << Duffing.LagrFunction(p1, 30, 0.1)
              << std::endl;

    std::cout << "The Lagrange function of the third point is "
              << Duffing.LagrFunction(p3, 30, 0.1)
              << std::endl;

    // Lagrange function of grids

}

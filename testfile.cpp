#include <iostream>
#include "vector.hpp"
#include "grid.hpp"
#include "dynsys.hpp"

bool DuffDomain(const vec& p) {
    // Check that the dimension is actually 3
    return true;
}

vec DuffFunction(const vec& p) {
    vec v(3);
    v[0] = 1.0;
    v[1] = p[2];
    v[2] = p[1] - p[1]*p[1]*p[1];
    return v;
}

int main() {

    // Vector class testing
    
    // Declaration testing
    vec v(3);
    v[0] = 3;
    v[1] = 0;
    v[2] = 4;

    for (int i = 0; i < 3; ++i) std::cout << v[i] << ' ';
    std::cout << '\n';

    // Holder norms and seminorms declaration
    std::cout << "The 2-Holder norm of the vector is " << v.HoldNorm(2) << '\n';
    std::cout << "The 2-Holder semi-norm of the vector is " << v.HoldSemiNorm(2) << '\n';

    std::cout << "The length of the vector is " << v.length() << std::endl;
    std::cout << "The length by the friend function is " << GetLength(v) << std::endl;

    vec b(3);
    b[1] = 5;

    // Testing empty constructor, binary operations and asignation operator
    vec u = v + b;

    for (int i = 0; i < 3; ++i) std::cout << u[i] << ' ';
    
    // Grid class testing
    grid g(3, 3);
    std::cout << "The length of the grid is " << g.length() << std::endl;
    std::cout << "The length of the grid is " << GetLength(g) << std::endl;
    std::cout << "The dimension of the grid is " << g.dimension() << std::endl;
    std::cout << "The dimension of the grid is " << GetDimension(g) << std::endl;

    // Grid values assignation
    g[0] = v;
    g[1] = b;
    g[2] = u;

    // Value outputting
    for (int i = 0; i < g.length(); ++i) {
        vec& v(g[i]);
        for (int j = 0; j < g.dimension(); ++j) std::cout << v[j] << ' ';
        std::cout << std::endl;
    }

    // More grid declaration with copy and modification
    grid h = grid(3, 3);
    
    h[2] = v;

    grid f = (g - h)/2;

    // Value outputting
    for (int i = 0; i < f.length(); ++i) {
        vec& v(f[i]);
        for (int j = 0; j < f.dimension(); ++j) std::cout << v[j] << ' ';
        std::cout << std::endl;
    }
    
    // Testing the functions for the duffing equation
    vec fpoint(3);
    fpoint[0] = 0;
    fpoint[1] = 1;
    fpoint[2] = 0;
    vec disp(DuffFunction(fpoint));
    std::cout << "Does the point belong in the domain? " << DuffDomain(fpoint) << std::endl;
    std::cout << "The components of the function vector are given by" << std::endl;
    for (int i = 0; i < 3; ++i) std::cout << disp[i] << ' ';
    std::cout << std::endl << std::endl;
    
    // Testing the class declaration and Runge-Kutta methods
    DynSys Duffing(DuffFunction, 3, DuffDomain);
    vec image = Duffing.evaluate(fpoint);

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

    vec nextiter = Duffing.RK4(fpoint, 0.1); 

    std::cout << "What is the next iterate by means of the Runge-Kutta method?" << std::endl;
    for (int i = 0; i < 3; ++i) std::cout << nextiter[i] << ' ';
    std::cout << std::endl << std::endl; 

    // Testing the action on a grid by a Runge-Kutta method

    grid DuffGrid(3, 3);
    
    vec p1 = fpoint;
    vec p2(3);
    vec p3(3);

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
        vec temp = DuffGrid[i];
        // Printing each actual vector
        for (int j = 0; j < 3; ++j) std::cout << temp[j] << ' ';
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // Declaring the grid obtanined by a Runge-Kutta iteration
    grid DuffNext = Duffing.RK4(DuffGrid, 0.1);

    // Printing the next grid to see if it works
    for (int i = 0; i < 3; ++i) {
        vec temp = DuffNext[i];
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

}

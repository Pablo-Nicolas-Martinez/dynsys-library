#include <iostream>
#include "vector.hpp"
#include "grid.hpp"

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
    /*
    // Grid class testing
    grid g(3, 3);
    std::cout << "The length of the grid is " << g.length() << std::endl;
    std::cout << "The length of the grid is " << length(g) << std::endl;
    std::cout << "The dimension of the grid is " << g.dimension() << std::endl;
    std::cout << "The dimension of the grid is " << dimension(g) << std::endl;

    // Grid values assignation
    g[0] = v;
    g[1] = b;
    g[2] = u;

    // Value outputting
    for (int i = 0; i < length(g); ++i) {
        vec& v(pData[i]);
        for (int j = 0; j < dimension(g); ++j) std::cout << v[j] << ' ';
        std::cout << std::endl;
    }
    */
}

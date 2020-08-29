#include <iostream>
#include "vector.hpp"

int main() {
    vec v(3);
    v[0] = 3;
    v[1] = 0;
    v[2] = 4;

    for (int i = 0; i < 3; ++i) std::cout << v[i] << ' ';
    std::cout << '\n';

    std::cout << "The 2-Holder norm of the vector is " << v.HoldNorm(2) << '\n';
    std::cout << "The 2-Holder semi-norm of the vector is " << v.HoldSemiNorm(2) << '\n';

    std::cout << "The length of the vector is " << v.length() << std::endl;
    std::cout << "The length by the friend function is " << GetLength(v) << std::endl;

    vec b(3);
    b[1] = 5;

    vec u(v + b);

    for (int i = 0; i < 3; ++i) std::cout << u[i] << ' ';
}

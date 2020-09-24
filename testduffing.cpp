#include <iostream>
#include "dynsys.hpp"

// Parameters for the system

const int numpx = 1000;
const int numpy = 1000;
const double liminfx = -1.5;
const double limsupx = 1.5;
const double liminfy = -1.5;
const double limsupy = 1.5;
const double tau = 30;
const double dt = 0.01;

Vec DuffEquation(const Vec& p) {
    Vec f(3);
    f[0] = 1;
    f[1] = p[2];
    f[2] = p[1] - p[1]*p[1]*p[1];
    return f;
}

inline bool DuffDomain(const Vec& p) { return true; }

int main() {

    // Creation of the grid of points
    Grid g(3, numpx*numpy);

    for (int i = 0; i < numpx; ++i) {
        for (int j = 0; j < numpy; ++j) {
            Vec v(3);
            v[0] = 0;
            v[1] = liminfx + i*(limsupx - liminfx)/numpx;
            v[2] = liminfy + i*(limsupy - liminfy)/numpy;
            g[j + numpy*i] = v;
        }
    }

    // Creation of the Duffing dynamical system
    DynSys Duffing(DuffEquation, 3, DuffDomain);

    Vec resul(numpx*numpy);
    resul = Duffing.LagrFunction(g, tau, dt);

    // Data output, probably a mess
    for (int i = 0; i < numpx; ++i) {
        for (int j = 0; j < numpy; ++j) std::cout << resul[j + numpy*i] << ' ';
        std::cout << std::endl;
    }

}

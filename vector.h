#ifndef VECTOR_H
#define VECTOR_H

#include <array>

struct Vector
{       double i, j, k;

        // default constructor (implicitly defined)
        Vector() = default;

        // parameterised constructor
        Vector(const double& i, const double& j, const double& k) : i(i), j(j), k(k) {}

        // copy constructor (implicitly defined)
        Vector(const Vector&) = default;

        // destructor (implicitly defined)
        ~Vector() = default;       
};

#endif // VECTOR_H
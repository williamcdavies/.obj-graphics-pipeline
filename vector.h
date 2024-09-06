#ifndef VECTOR_H
#define VECTOR_H

#include <array>

struct Vector
{       std::array<double, 3> components;

        // default constructor (implicitly defined)
        Vector() = default;

        // parameterised constructor
        Vector(const double i, const double j, const double k) : components{i, j, k} {}

        // copy constructor (implicitly defined)
        Vector(const Vector&) = default;

        // deconstructor (implicitly defined)
        ~Vector() = default;
};

#endif
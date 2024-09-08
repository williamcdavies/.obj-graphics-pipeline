#ifndef VECTOR_H
#define VECTOR_H

#include <array>

constexpr std::array<double, 3> O = {0, 0, 0};

struct Vector
{       std::array<double, 3> A;
        std::array<double, 3> B;

        // default constructor
        Vector() : A(O), B(O) {}

        // parameterised constructor
        Vector(const std::array<double, 3>& A, const std::array<double, 3>& B) : A(A), B(B) {}

        // copy constructor (implicitly defined)
        Vector(const Vector&) = default;

        // destructor (implicitly defined)
        ~Vector() = default;
};

#endif // VECTOR_H
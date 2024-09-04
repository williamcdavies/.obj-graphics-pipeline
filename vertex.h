#ifndef VERTEX_H
#define VERTEX_H

#include <array>

struct Vertex
{       std::array<double, 3> arr;

        // default constructor (implicitly defined)
        Vertex() = default;

        // parameterised constructor
        Vertex(const double x1, const double x2, const double x3) : arr{x1, x2, x3} {}

        // copy constructor (implicitly defined)
        Vertex(const Vertex&) = default;

        // deconstructor (implicitly defined)
        ~Vertex() = default;
};

#endif
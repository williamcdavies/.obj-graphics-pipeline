#ifndef VERTEX_H
#define VERTEX_H

#include <array>

struct Vertex
{       std::array<double, 3> coordinates;

        // default constructor (implicitly defined)
        Vertex() = default;

        // parameterised constructor
        Vertex(const double x, const double y, const double z) : coordinates{x, y, z} {}

        // copy constructor (implicitly defined)
        Vertex(const Vertex&) = default;

        // deconstructor (implicitly defined)
        ~Vertex() = default;
};

#endif
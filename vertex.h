#ifndef VERTEX_H
#define VERTEX_H

#include <array>
#include "vector.h"

struct Vertex : public Vector
{       // default constructor
        Vertex() : Vector() {}
        
        // parameterised constructor
        Vertex(const std::array<double, 3>& A) : Vector(O, A) {}

        // copy constructor
        Vertex(const Vertex& other) : Vector(other) {}

        // destructor (implicitly defined)
        ~Vertex() = default;
};

#endif // VERTEX_H
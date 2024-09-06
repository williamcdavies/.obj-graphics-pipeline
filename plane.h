#ifndef PLANE_H
#define PLANE_H

#include "vector.h"
#include "vertex.h"

class Plane
{       Vector normal;
        Vertex vertex;

        // default constructor
        Plane() : normal(0, 0, 1), vertex(0, 0, 0) {}

        // parameterised constructor
        Plane(const Vector& normal, const Vertex& vertex) : normal(normal), vertex(vertex) {}

        // copy constructor (implicitly defined)
        Plane(const Plane&) = default;

        // deconstructor (implicitly defined)
        ~Plane() = default;

        Vertex intersects(const Vector&) const;
};

Vertex Plane::intersects(const Vector& other) const
{       
} 

#endif
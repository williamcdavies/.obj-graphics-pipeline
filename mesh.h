#ifndef MESH_H
#define MESH_H

#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "vector.h"

struct Mesh
{       std::vector<Vector> v;
        std::vector<Vector> f;

        // default constructor (implicitly defined)
        Mesh() = default;

        // parameterised constructor
        Mesh(const std::vector<Vector>& v, const std::vector<Vector>& f) : v(v), f(f) {}

        // copy constructor (implicitly defined)
        Mesh(const Mesh&) = default;

        // destructor (implicitly defined)
        ~Mesh() = default;

        void load(std::ifstream&);
};

void Mesh::load(std::ifstream& in)
{       std::string line;
        while(std::getline(in, line))
        {       if(line.substr(0, 2) == "v ")
                {       std::istringstream iss(line.substr(2));
                        std::string istr, jstr, kstr;
                        iss >> istr >> jstr >> kstr;
                        Vector vector(stod(istr), stod(jstr), stod(kstr));
                        v.push_back(vector);
                }
                else if(line.substr(0, 2) == "f ")
                {       std::istringstream iss(line.substr(2));
                        std::string istr, jstr, kstr;
                        iss >> istr >> jstr >> kstr;
                        Vector vector(stod(istr), stod(jstr), stod(kstr));
                        f.push_back(vector);
                }
        }
}

#endif
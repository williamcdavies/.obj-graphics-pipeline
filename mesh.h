#ifndef MESH_H
#define MESH_H

#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "vertex.h"

struct Mesh
{       std::vector<Vertex> v;
        std::vector<std::array<unsigned int, 3>> f;

        // default constructor (implicitly defined)
        Mesh() = default;

        // parameterised constructor
        Mesh(const std::vector<Vertex>& v, const std::vector<std::array<unsigned int, 3>>& f) : v(v), f(f) {}

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
                        Vertex vertex;
                        for(std::size_t i = 0; i < 3; ++i)
                        {       std::string str;
                                iss >> str;
                                vertex.B.at(i) = stod(str);
                        }
                        v.push_back(vertex);
                }
                else if(line.substr(0, 2) == "f ")
                {       std::istringstream iss(line.substr(2));
                        std::array<unsigned int, 3> arr;
                        for(std::size_t i = 0; i < 3; ++i)
                        {       std::string str;
                                iss >> str;
                                arr.at(i) = stod(str);
                        }
                        f.push_back(arr);
                }
        }
}

#endif
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include "mesh.h"

double bind(const Mesh& mesh)
{       double r = 0;
        for(std::size_t i = 0; i < mesh.v.size(); ++i)
        {       const double b1 = mesh.v.at(0).B.at(1);
                const double b2 = mesh.v.at(0).B.at(2);
                const double b3 = mesh.v.at(0).B.at(3);
                const double d = sqrt(pow(b1, 2) + pow(b2, 2) + pow(b3, 2));
                d > r ? r = d : r;
        }
        return r;
}

void display(const Mesh& mesh, const double r)
{       
}

void finish(const int exit_flag)
{       endwin();
        exit(exit_flag);
}

int main(int argc, char* argv[])
{       if(!(argc > 1))
        {       std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
                exit(1);
        }

        std::ifstream in(argv[1], std::ios::in);
        if(!in) 
        {       std::cerr << "Error opening " << argv[1] << std::endl;
                exit(1);
        }

        Mesh mesh;
        try
        {       mesh.load(in);
        }
        catch(const std::exception& e)
        {       std::cerr << e.what() << '\n';
                exit(1);
        } 

        // (void) initscr();
        // (void) cbreak();
        // (void) noecho();
        // nodelay(stdscr, TRUE);
        // keypad(stdscr, TRUE);

        const double r = bind(mesh);
        int ch;
        while((ch = getch()) != KEY_F(12))
        {       display(mesh, r);
        }

        finish(0);
}
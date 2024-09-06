#include <fstream>
#include <iostream>
#include <ncurses.h>
#include "mesh.h"

double bind(const Mesh& mesh)
{       double s = 0;
        for(std::size_t i = 0; i < mesh.v.size(); ++i)
        {       const double x = mesh.v.at(0).coordinates.at(1);
                const double y = mesh.v.at(0).coordinates.at(2);
                const double z = mesh.v.at(0).coordinates.at(3);
                const double e = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
                e > s ? s = e : s;
        }
        return s;
}

void display(const Mesh& mesh, const double s)
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

        double s = bind(mesh);
        int ch;
        while((ch = getch()) != KEY_F(12))
        {       display(mesh, s);
        }

        finish(0);
}
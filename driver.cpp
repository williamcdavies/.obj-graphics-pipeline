#include <fstream>
#include <iostream>
#include <ncurses.h>
#include "mesh.h"

double calc_axis_scale(const Mesh& mesh)
{       double ma = 0;
        for(std::size_t i = 0; i < mesh.v.size(); ++i)
        {       double x1 = mesh.v.at(i).arr.at(0);
                double x2 = mesh.v.at(i).arr.at(1);
                double x3 = mesh.v.at(i).arr.at(2);
                double mi = sqrt(pow(x1, 2) + pow(x2, 2) + pow(x3, 2));
                if(mi > ma)
                {       ma = mi;
                }
        }
        return ma;
}

void display(const Mesh& mesh, const double ma)
{       
}

void finish(const int exit_flag)
{       endwin();
        exit(exit_flag);
}

int main(int argc, char *argv[])
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

        double ma = calc_axis_scale(mesh);
        int ch;
        while((ch = getch()) != KEY_F(12))
        {       display(mesh, ma);
        }

        finish(0);
}
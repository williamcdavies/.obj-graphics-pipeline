#include <fstream>
#include <iostream>
#include <ncurses.h>

void finish(const int exit_flag)
{       // endwin();
        exit(exit_flag);
}

int main(int argc, char* argv[])
{       // if(!(argc > 1))
        // {       std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        //         exit(1);
        // }

        // std::ifstream in(argv[1], std::ios::in);
        // if(!in) 
        // {       std::cerr << "Error opening " << argv[1] << std::endl;
        //         exit(1);
        // }

        // Mesh mesh;
        // try
        // {       mesh.load(in);
        // }
        // catch(const std::exception& e)
        // {       std::cerr << e.what() << '\n';
        //         exit(1);
        // }

        // (void) initscr();
        // (void) cbreak();
        // (void) noecho();
        // nodelay(stdscr, TRUE);
        // keypad(stdscr, TRUE);

        finish(0);
}
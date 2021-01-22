#include <iostream>
#include <string>

#include "gol.hxx"
#include "stream_renderer.hxx"

using namespace gol;

int main() {
    World world{
        {39, 7}, {40, 7}, {41, 7},
        {39, 8}, {41, 8},
        {39, 9}, {41, 9},
        {39, 11}, {41, 11},
        {39, 12}, {41, 12},
        {39, 13}, {40, 13}, {41, 13},
    };
    StreamRenderer renderer{ std::cout, 80u, 25u };
    GameOfLife gol{ world, renderer };

    std::cout
        << "Welcome to Game of Life!\n"
        << "Press [Enter] to progress to the next stage...\n"
        << "Enter \"quit\" to close the program...\n"
        << std::endl;

    for (;;) {
        gol.render();
        std::cout <<
            "--------------------------------------------"
            "--------------------------------------------"
            << std::endl;

        std::string input;
        std::getline(std::cin, input);
        if (input == "quit") {
            break;
        }

        gol.progress();
    }

    return 0;
}

#include <iostream>
#include <string>

#include "gol.hxx"
#include "stream_renderer.hxx"

using namespace gol;

int main() {
    World world{};
    StreamRenderer renderer{ std::cout, 80u, 25u };
    GameOfLife gol{ world, renderer };

    std::cout
        << "Welcome to Game of Life!\n"
        << "Press [Enter] to progress to the next stage...\n"
        << "Enter \"quit\" to close the program...\n"
        << std::endl;

    for (;;) {
        gol.render();
        std::cout << "--------------------------------------------" << std::endl;

        std::string input;
        std::getline(std::cin, input);
        if (input == "quit") {
            break;
        }

        gol.progress();
    }

    return 0;
}

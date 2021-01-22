#pragma once

#ifndef GOL_HXX
#define GOL_HXX

#include "world.hxx"

#include <iosfwd>

namespace gol {
    struct Renderer;

    class GameOfLife {
        World world{};
        Renderer& renderer;

    public:
        GameOfLife(Renderer& renderer);

        /**
         * Calculate the next state of the world.
         */
        void progress();

        /**
         * Render the world.
         */
        void render();
    };
}

#endif // GOL_HXX

#pragma once

#ifndef RENDERER_HXX
#define RENDERER_HXX

#include "world.hxx"

namespace gol {
    struct Renderer {
        virtual ~Renderer() = default;

        /**
         * Render the given world.
         */
        virtual void render(World const& world) = 0;
    };
}

#endif // RENDERER_HXX

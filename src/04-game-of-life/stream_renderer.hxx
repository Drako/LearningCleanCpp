#pragma once

#ifndef STREAM_RENDERER_HXX
#define STREAM_RENDERER_HXX

#include "renderer.hxx"

#include <iosfwd>

namespace gol {
    struct World;

    class StreamRenderer : public Renderer {
        std::ostream& target;
        unsigned width;
        unsigned height;

    public:
        StreamRenderer(std::ostream& target, unsigned width, unsigned height);

        /**
         * Render the given world.
         */
        void render(World const& world) override;
    };
}

#endif // STREAM_RENDERER_HXX

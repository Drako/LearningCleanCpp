#include "stream_renderer.hxx"
#include "world.hxx"

#include <cassert>
#include <ostream>

namespace gol {
    StreamRenderer::StreamRenderer(std::ostream& target, unsigned width, unsigned height)
        : target{target}
        , width{width}
        , height{height}
    {
        assert(width != 0u);
        assert(height != 0u);
    }

    void StreamRenderer::render(World const& world) {
        // TODO: implement
    }
}

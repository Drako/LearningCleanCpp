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
        std::string output((width + 1) * height, ' ');
        for (unsigned y = 0; y < height; ++y) {
            output[y * (width + 1) + width] = '\n';
        }
        for (auto const& cell : world.cells) {
            int x, y;
            std::tie(x, y) = cell;
            if (x >= 0 && x < width && y >= 0 && y < height)
                output[y * (width + 1) + x] = 'X';
        }
        target << output;
    }
}

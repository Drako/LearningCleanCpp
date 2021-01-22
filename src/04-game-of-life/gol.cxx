#include "gol.hxx"
#include "renderer.hxx"

namespace gol {
    GameOfLife::GameOfLife(Renderer& renderer)
        : renderer{renderer}
    {}

    void GameOfLife::progress() {
        // TODO: implement
    }

    void GameOfLife::render() {
        renderer.render(world);
    }
}

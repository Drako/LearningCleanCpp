#include "gol.hxx"
#include "renderer.hxx"

#include <algorithm>
#include <array>
#include <iterator>

namespace {
    using namespace gol;

    std::array<LivingCell, 8u> const neighbors{
        LivingCell{-1, -1}, LivingCell{0, -1}, LivingCell{1, -1},
        LivingCell{-1, 0}, LivingCell{1, 0},
        LivingCell{-1, 1}, LivingCell{0, 1}, LivingCell{1, 1},
    };

    LivingCell operator + (LivingCell const& lhs, LivingCell const& rhs) {
        int lx, ly, rx, ry;
        std::tie(lx, ly) = lhs;
        std::tie(rx, ry) = rhs;
        return { lx + rx, ly + ry };
    }

    std::set<LivingCell> neighbors_of(LivingCell const& cell) {
        std::set<LivingCell> results;

        for (auto const& relativeNeighbor : neighbors) {
            results.insert(cell + relativeNeighbor);
        }

        return results;
    }
}

namespace gol {
    GameOfLife::GameOfLife(World& world, Renderer& renderer)
        : world{world}
        , renderer{renderer}
    {}

    void GameOfLife::progress() {
        std::set<LivingCell> next_world;

        std::set<LivingCell> might_become_alive;
        for (auto const& cell : world.cells) {
            auto const neighbors = neighbors_of(cell);
            
            int living = 0;
            for (auto const & neighbor : neighbors) {
                if (world.cells.find(neighbor) != std::cend(world.cells)) {
                    ++living;
                }
                else {
                    might_become_alive.insert(neighbor);
                }
            }

            // Any live cell with two or three live neighbours survives.
            if (living == 2 || living == 3) {
                next_world.insert(cell);
            }
        }

        for (auto const& cell : might_become_alive) {
            auto const neighbors = neighbors_of(cell);
            auto const living = std::count_if(
                std::cbegin(neighbors),
                std::cend(neighbors),
                [this](LivingCell const& neighbor) {
                    return world.cells.find(neighbor) != std::cend(world.cells);
                }
            );

            // Any dead cell with three live neighbours becomes a live cell.
            if (living == 3) {
                next_world.insert(cell);
            }
        }

        world.cells = std::move(next_world);
    }

    void GameOfLife::render() {
        renderer.render(world);
    }
}

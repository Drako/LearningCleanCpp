#pragma once

#ifndef WORLD_HXX
#define WORLD_HXX

#include <algorithm>
#include <initializer_list>
#include <iterator>
#include <ostream>
#include <set>
#include <string>
#include <tuple>

namespace gol {
    using LivingCell = std::tuple<int, int>;
    // typedef std::tuple<int, int> LivingCell;

    struct World {
        std::set<LivingCell> cells;

        inline World(std::initializer_list<LivingCell> const& cells)
            : cells{cells}
        {}

        inline bool operator == (World const& rhs) const {
            return cells == rhs.cells;
        }
    };
}

inline std::ostream& operator <<(std::ostream& os, gol::World const& w) {
    using namespace std::literals::string_literals;

    os << "world {\n";
    std::transform(
        std::cbegin(w.cells),
        std::cend(w.cells),
        std::ostream_iterator<std::string>(os, "\n"),
        [](gol::LivingCell const& cell) {
            int x, y;
            std::tie(x, y) = cell;
            return "  {" + std::to_string(x) + ", " + std::to_string(y) + "}";
        }
    );
    return os << "}";
}

#endif // WORLD_HXX

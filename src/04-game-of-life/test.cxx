#include <gtest/gtest.h>

#include "gol.hxx"
#include "stream_renderer.hxx"

#include <sstream>

using namespace gol;

class GameOfLifeTest : public ::testing::Test {
    std::ostringstream out;

protected:
    void SetUp() override {
        out.str("");
    }

public:
    static unsigned const WIDTH = 8u;
    static unsigned const HEIGHT = 8u;

    StreamRenderer renderer{ out, WIDTH, HEIGHT };

    std::string render_result() {
        return out.str();
    }
};

TEST_F(GameOfLifeTest, emptyWorldIsRenderedCorrectly) {
    World world{};
    GameOfLife gol{ world, renderer };

    gol.render();

    char const* const empty_screen =
        "        \n"
        "        \n"
        "        \n"
        "        \n"
        "        \n"
        "        \n"
        "        \n"
        "        \n";

    EXPECT_EQ(render_result(), empty_screen);
}

TEST_F(GameOfLifeTest, singleCellIsRenderedCorrectly) {
    World world{ {3, 3} };
    GameOfLife gol{ world, renderer };

    gol.render();

    char const* const empty_screen =
        "        \n"
        "        \n"
        "        \n"
        "   X    \n"
        "        \n"
        "        \n"
        "        \n"
        "        \n";

    EXPECT_EQ(render_result(), empty_screen);
}

TEST_F(GameOfLifeTest, emptyWorldStaysEmpty) {
    World world{};
    GameOfLife gol{ world, renderer };

    gol.progress();

    World const empty{};
    EXPECT_EQ(world, empty);
}

TEST_F(GameOfLifeTest, singleCellDies) {
    World world{ {1, 1} };
    GameOfLife gol{ world, renderer };

    gol.progress();

    World const empty{};
    EXPECT_EQ(world, empty);
}

TEST_F(GameOfLifeTest, twoNeighborsDie) {
    World world{ {1, 1}, {1, 2} };
    GameOfLife gol{ world, renderer };

    gol.progress();

    World const empty{};
    EXPECT_EQ(world, empty);
}

TEST_F(GameOfLifeTest, threeNeighborsGiveBirth) {
    World world{ {1, 1}, {1, 2}, {2, 1} };
    GameOfLife gol{ world, renderer };

    gol.progress();

    World const expected{ {1, 1}, {1, 2}, {2, 1}, {2, 2} };
    EXPECT_EQ(world, expected);
}

TEST_F(GameOfLifeTest, fourNeighborsSurvive) {
    World world{ {1, 1}, {1, 2}, {2, 1}, {2, 2} };
    GameOfLife gol{ world, renderer };

    gol.progress();

    World const expected{ {1, 1}, {1, 2}, {2, 1}, {2, 2} };
    EXPECT_EQ(world, expected);
}

#include <gtest/gtest.h>

#include "shop.hxx"

#include <array>

struct GildedRoseTest : ::testing::Test {
    static Item updateItem(Item const& original, int days = 1)
    {
        Shop shop{ {original} };
        for (int n = 0; n < days; ++n) {
            shop.updateQuality();
        }
        return shop.getItems().front();
    }
};

TEST_F(GildedRoseTest, legendaryItemsNeverChange) {
    Item const sulfuras{ "Sulfuras, Hand of Ragnaros", 0, 80 };
    Item const updated = updateItem(sulfuras);
    EXPECT_EQ(sulfuras, updated);
}

TEST_F(GildedRoseTest, itemsDegrade) {
    Item const shoe{ "Shoe", 10, 10 };
    Item const expected{ "Shoe", 9, 9 };
    Item const updated = updateItem(shoe);
    EXPECT_EQ(expected, updated);
}

TEST_F(GildedRoseTest, itemsDegradeTwiceAsFastAfterSellIn) {
    Item const shoe{ "Shoe", 0, 10 };
    Item const expected{ "Shoe", -1, 8 };
    Item const updated = updateItem(shoe);
    EXPECT_EQ(expected, updated);
}

TEST_F(GildedRoseTest, itemCannotGetWorseThan0) {
    Item const shoe{ "Shoe", 10, 10 };
    Item const expected{ "Shoe", -10, 0 };
    Item const updated = updateItem(shoe, 20);
    EXPECT_EQ(expected, updated);
}

TEST_F(GildedRoseTest, agedBrieGetsBetter) {
    Item const brie{ "Aged Brie", 10, 10 };
    Item const expected{ "Aged Brie", 9, 11 };
    Item const updated = updateItem(brie);
    EXPECT_EQ(expected, updated);
}

TEST_F(GildedRoseTest, agedBrieGetsBetterTwiceAsFastAfterSellIn) {
    Item const brie{ "Aged Brie", 0, 10 };
    Item const expected{ "Aged Brie", -1, 12 };
    Item const updated = updateItem(brie);
    EXPECT_EQ(expected, updated);
}

TEST_F(GildedRoseTest, agedBrieCannotGetBetterThan50) {
    Item const brie{ "Aged Brie", 3, 10 };
    Item const expected{ "Aged Brie", -27, 50 };
    Item const updated = updateItem(brie, 30);
    EXPECT_EQ(expected, updated);
}

TEST_F(GildedRoseTest, backStagePass) {
    auto const name = "Backstage passes to a TAFKAL80ETC concert";
    std::array<Item, 17u> const stages{
        Item{name, 15, 20},
        Item{name, 14, 21},
        Item{name, 13, 22},
        Item{name, 12, 23},
        Item{name, 11, 24},
        Item{name, 10, 25},
        Item{name, 9, 27},
        Item{name, 8, 29},
        Item{name, 7, 31},
        Item{name, 6, 33},
        Item{name, 5, 35},
        Item{name, 4, 38},
        Item{name, 3, 41},
        Item{name, 2, 44},
        Item{name, 1, 47},
        Item{name, 0, 50},
        Item{name, -1, 0},
    };

    Shop shop{ {stages[0]} };
    for (auto const& stage : stages) {
        EXPECT_EQ(stage, shop.getItems().front());
        shop.updateQuality();
    }
}

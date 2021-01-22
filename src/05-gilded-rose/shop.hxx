#pragma once

#ifndef SHOP_HXX
#define SHOP_HXX

#include "item.hxx"

#include <vector>

class Shop final {
    std::vector<Item> items;

public:
    explicit Shop(std::vector<Item> items);

    std::vector<Item> const& getItems() const;

    void updateQuality();

private:
    static bool isLegendary(Item const& item);
    static bool isAged(Item const& item);
    static bool isBackstagePass(Item const& item);

    static int qualityDirection(Item const& item);
    static int qualityFactor(Item const& item);

    static int clampQuality(int quality);
};

#endif // SHOP_HXX

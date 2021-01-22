#include "shop.hxx"

Shop::Shop(std::vector<Item> items)
    : items{ std::move(items) }
{}

std::vector<Item> const& Shop::getItems() const {
    return items;
}

void Shop::updateQuality() {
    for (auto& item : items) {
        if (isLegendary(item)) {
            continue;
        }

        --item.sellIn;

        item.quality = clampQuality(
            item.quality + qualityDirection(item) * qualityFactor(item)
        );
    }
}

bool Shop::isLegendary(Item const& item) {
    return item.name == "Sulfuras, Hand of Ragnaros";
}

bool Shop::isAged(Item const& item) {
    return item.name == "Aged Brie";
}

bool Shop::isBackstagePass(Item const& item) {
    return item.name == "Backstage passes to a TAFKAL80ETC concert";
}

int Shop::qualityDirection(Item const& item) {
    if (isAged(item) || isBackstagePass(item)) {
        return 1;
    }
    else {
        return -1;
    }
}

int Shop::qualityFactor(Item const& item) {
    if (isBackstagePass(item)) {
        if (item.sellIn < 0) {
            return -50;
        }
        else if (item.sellIn < 5) {
            return 3;
        }
        else if (item.sellIn < 10) {
            return 2;
        }
    }
    else if (item.sellIn < 0) {
        return 2;
    }
    
    return 1;
}

int Shop::clampQuality(int const quality) {
    return
        quality < 0 ? 0 :
        quality > 50 ? 50 :
        quality;
}

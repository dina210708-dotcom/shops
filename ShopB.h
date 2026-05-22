#pragma once
#include "Shop.h"

class ShopB : public Shop {
public:
    ShopB() : Shop("SmartHome") {
        insertProduct(Product("Робот-пилосос RoboRock", 13200, 1, 0.15));
        insertProduct(Product("Зволожувач повітря Xiaomi", 2100, 1, 0.10));
        insertProduct(Product("Розумна лампа Yeelight", 650, 1, 0.0));
    }
};

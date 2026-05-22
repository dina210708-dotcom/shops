#pragma once
#include "Shop.h"

class ShopA : public Shop {
public:
    ShopA() : Shop("CyberHub") {
        insertProduct(Product("Відеокарта RTX 4060", 14500, 1, 0.05));
        insertProduct(Product("Процесор Intel i5", 8200, 1, 0.12));
        insertProduct(Product("Монітор 27' ASUS", 9500, 1, 0.08));
    }
};

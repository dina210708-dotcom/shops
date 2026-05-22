#pragma once
#include <string>

class Product {
private:
    std::string title;
    double cost;
    int units;
    double priceDrop;

public:
    Product() : title(""), cost(0.0), units(1), priceDrop(0.0) {}
    Product(std::string t, double c, int u, double d) : title(t), cost(c), units(u), priceDrop(d) {}

    std::string getTitle() const { return title; }
    double getCost() const { return cost; }
    int getUnits() const { return units; }
    double getPriceDrop() const { return priceDrop; }
    void setUnits(int u) { units = u; }
};

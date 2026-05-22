#pragma once
#include "Product.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

class Shop {
protected:
    std::string shopName;
    Product catalog[15];
    int itemCount = 0;

public:
    Shop(std::string name) : shopName(name) {}

    std::string getShopName() const { return shopName; }

    void insertProduct(const Product& prod) {
        if (itemCount < 15) {
            catalog[itemCount++] = prod;
        }
    }

    void displayCatalog() {
        std::cout << "\n--- Асортимент маркету: " << shopName << " ---\n";
        for (int i = 0; i < itemCount; i++) {
            std::cout << " [" << i + 1 << "] " << catalog[i].getTitle()
                      << " | Ціна: " << catalog[i].getCost() << " UAH"
                      << " (Знижка: " << catalog[i].getPriceDrop() * 100 << "%)\n";
        }
    }

    Product selectItem() {
        int idx, qty;
        std::cout << "Введіть номер товару: ";
        std::cin >> idx;
        while (idx < 1 || idx > itemCount) {
            std::cout << "Невірний номер. Повторіть спробу: ";
            std::cin >> idx;
        }
        Product selected = catalog[idx - 1];

        std::cout << "Вкажіть необхідну кількість: ";
        std::cin >> qty;
        while (qty <= 0) {
            std::cout << "Кількість має бути більшою за 0: ";
            std::cin >> qty;
        }
        selected.setUnits(qty);
        return selected;
    }

    void generateBill(const Product& prod) {
        static int billId = 1;
        std::string path = "receipts/receipt_" + std::to_string(billId++) + ".txt";

        std::ofstream out(path);
        double discountAmount = prod.getCost() * prod.getPriceDrop();
        double netPrice = prod.getCost() - discountAmount;
        double totalSum = netPrice * prod.getUnits();

        out << "===============================\n";
        out << " МАРКЕТ: " << shopName << "\n";
        out << "===============================\n";
        out << "Найменування: " << prod.getTitle() << "\n";
        out << "Базова ціна:  " << prod.getCost() << " грн\n";
        out << "Знижка:       " << discountAmount << " грн\n";
        out << "Ціна зі зн.:  " << netPrice << " грн\n";
        out << "Кількість:    " << prod.getUnits() << " шт.\n";
        out << "-------------------------------\n";
        out << "ЗАГАЛЬНА СУМА: " << totalSum << " грн\n";
        out << "===============================\n";
        out.close();

        std::cout << "=> Документ збережено: " << path << std::endl;

        // Синхронізація з Git репозиторієм
        std::string addCmd = "git add " + path;
        std::string commitCmd = "git commit -m \"auto: generated receipt #" + std::to_string(billId - 1) + "\"";
        
        std::system(addCmd.c_str());
        std::system(commitCmd.c_str());
        std::system("git push");
    }
};

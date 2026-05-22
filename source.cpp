#include <iostream>
#include <cstdlib> // для system()
#include "ShopA.h"
#include "ShopB.h"

int main() {
   
    std::system("mkdir -p receipts");

    std::cout << "======================================\n";
    std::cout << "   СИСТЕМА АВТОМАТИЗАЦІЇ ПРОДАЖІВ   \n";
    std::cout << "======================================\n";

    ShopA cyberHub;
    ShopB smartHome;

    while (true) {
        std::cout << "\n[ МЕНЮ ВИБОРУ ПЛОЩАДКИ ]\n";
        std::cout << "1 — Перейти до CyberHub\n";
        std::cout << "2 — Перейти до SmartHome\n";
        std::cout << "0 — Завершити роботу\n";
        std::cout << "Ваш вибір: ";
        
        int userChoice; 
        std::cin >> userChoice;
        
        if (userChoice == 0) break;

        Shop* activeShop = nullptr;
        if (userChoice == 1) {
            activeShop = &cyberHub;
        } else if (userChoice == 2) {
            activeShop = &smartHome;
        } else {
            std::cout << "Некоректний ввід. Спробуйте знову.\n";
            continue;
        }

        activeShop->displayCatalog();
        Product orderedItem = activeShop->selectItem();
        activeShop->generateBill(orderedItem);
    }

    std::cout << "\nПрограму завершено. Гарного дня!\n";
    return 0;
}

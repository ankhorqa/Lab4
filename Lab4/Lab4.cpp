#include <iostream>
#include <memory>
#include <string>

class Inventory {
private:
    std::unique_ptr<std::string[]> items; 
    int capacity;
    int size;

public:
    Inventory(int cap = 10)
        : capacity(cap), size(0), items(std::make_unique<std::string[]>(cap)) {}

    void addItem(const std::string& item) {
        if (size < capacity) {
            items[size++] = item;
        } else {
            std::cout << "Инвентарь заполнен!" << std::endl;
        }
    }

    void displayInventory() const {
        std::cout << "Инвентарь:\n";
        if (size == 0) {
            std::cout << "(пусто)\n";
            return;
        }
        for (int i = 0; i < size; ++i) {
            std::cout << "- " << items[i] << "\n";
        }
    }
};

int main() {
    Inventory playerInventory;

    playerInventory.addItem("Меч");
    playerInventory.addItem("Щит");
    playerInventory.addItem("Зелье восстановления ХП");

    playerInventory.displayInventory();

    return 0;
}

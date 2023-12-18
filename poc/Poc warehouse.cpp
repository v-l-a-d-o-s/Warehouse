#include <iostream>
#include <vector>

// Простий клас для товару на складі
class Product {
public:
    std::string name;
    int quantity;

    Product(const std::string& n, int q) : name(n), quantity(q) {}
};

// Клас, який моделює склад
class Warehouse {
private:
    std::vector<Product> products;

public:
    void addProduct(const std::string& name, int quantity) {
        products.emplace_back(name, quantity);
    }

    void displayProducts() {
        for (const auto& product : products) {
            std::cout << "Product: " << product.name << ", Quantity: " << product.quantity << std::endl;
        }
    }
};

int main() {
    Warehouse warehouse;

    // Додавання товарів на склад
    warehouse.addProduct("Item 1", 10);
    warehouse.addProduct("Item 2", 20);

    // Виведення товарів на складі
    std::cout << "Products in the warehouse:" << std::endl;
    warehouse.displayProducts();

    return 0;
}

#include "trading/order.hpp"

#include <exception>
#include <iostream>

int main() {
    try {
        const trading::Order order{
            10,
            72'500.0,
            trading::Side::buy
        };

        std::cout << "quantity: " << order.quantity() << '\n';
        std::cout << "price: " << order.price() << '\n';
        std::cout << "notional: " << order.notional() << '\n';
    } catch (const std::exception& error) {
        std::cerr << "error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
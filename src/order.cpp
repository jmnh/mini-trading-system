#include "trading/order.hpp"

#include <stdexcept>

namespace trading {

Order::Order(const int quantity, const double price, const Side side)
    : quantity_(quantity), price_(price), side_(side) {
    if (quantity <= 0) {
        throw std::invalid_argument("quantity must be positive");
    }

    if (price <= 0.0) {
        throw std::invalid_argument("price must be positive");
    }
}

int Order::quantity() const {
    return quantity_;
}

double Order::price() const {
    return price_;
}

Side Order::side() const {
    return side_;
}

double Order::notional() const {
    return static_cast<double>(quantity_) * price_;
}

}  // namespace trading
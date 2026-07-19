#pragma once

namespace trading {

enum class Side {
    buy,
    sell
};

class Order {
public:
    Order(int quantity, double price, Side side);

    [[nodiscard]] int quantity() const;
    [[nodiscard]] double price() const;
    [[nodiscard]] Side side() const;
    [[nodiscard]] double notional() const;

private:
    int quantity_;
    double price_;
    Side side_;
};

}  // namespace trading
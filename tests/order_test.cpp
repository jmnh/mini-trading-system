#include "trading/order.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(OrderTest, CalculatesNotional) {
    const trading::Order order{
        10,
        72'500.0,
        trading::Side::buy
    };

    EXPECT_DOUBLE_EQ(order.notional(), 725'000.0);
}

TEST(OrderTest, RejectsNonPositiveQuantity) {
    EXPECT_THROW(
        trading::Order(0, 72'500.0, trading::Side::buy),
        std::invalid_argument
    );
}

TEST(OrderTest, RejectsNonPositivePrice) {
    EXPECT_THROW(
        trading::Order(10, 0.0, trading::Side::buy),
        std::invalid_argument
    );
}
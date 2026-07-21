#include "trading/order.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(OrderTest, CalculatesNotional) {
    const trading::Order order{
        1001,
        10,
        72'500.0,
        trading::Side::buy
    };

    EXPECT_EQ(order.order_id(), 1001);
    EXPECT_DOUBLE_EQ(order.notional(), 75'000.0);
    EXPECT_EQ(order.side_string(), "BUY");
}

TEST(OrderTest, ConvertsSellSideToString) {
    const trading::Order order{
        1002,
        5,
        73'000.0,
        trading::Side::sell
    };

    EXPECT_EQ(order.side_string(), "SELL");
}

TEST(OrderTest, RejectsNonPositiveQuantity) {
    EXPECT_THROW(
        trading::Order(1001, 0, 72'500.0, trading::Side::buy),
        std::invalid_argument
    );
}

TEST(OrderTest, RejectsNonPositivePrice) {
    EXPECT_THROW(
        trading::Order(1001, 10, 0.0, trading::Side::buy),
        std::invalid_argument
    );
}

TEST(OrderTest, RejectsZeroQuantity) {
    EXPECT_THROW(
        trading::Order(
            1001,
            0,
            72500.0,
            trading::Side::buy
        ),
        std::invalid_argument
    );
}

TEST(OrderTest, RejectsNegativeQuantity) {
    EXPECT_THROW(
        trading::Order(
            1001,
            -1,
            72500.0,
            trading::Side::buy
        ),
        std::invalid_argument
    );
}

TEST(OrderTest, RejectsZeroPrice) {
    EXPECT_THROW(
        trading::Order(
            1001,
            0,
            0.0,
            trading::Side::buy
        ),
        std::invalid_argument
    );
}

TEST(OrderTest, RejectsNegativePrice) {
    EXPECT_THROW(
        trading::Order(
            1001,
            0,
            -10.0,
            trading::Side::buy
        ),
        std::invalid_argument
    );
}
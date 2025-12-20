#include <gtest/gtest.h>

#include "../impl/dayOne.h"

// ./run_tests.sh

TEST(DayOneTest, ReturnsZeroByDefault) {
    EXPECT_EQ(dayOne(), 0);
}

TEST(DayOneTest, ProcessL_WrapsAroundCorrectly) {
    int value = 10;
    EXPECT_EQ(processL(value, 15), 95);
    value = 5;
    EXPECT_EQ(processL(value, 3), 2);
}

TEST(DayOneTest, ProcessL_StopsAtZero) {
    int value = 50;
    EXPECT_EQ(processL(value, 50), 0);
}

TEST(DayOneTest, ProcessL_WrapsWithGreaterValues) {
    int value = 50;
    EXPECT_EQ(processL(value, 236), 14);
}

TEST(DayOneTest, ProcessR_WrapsAroundCorrectly) {
    int value = 95;
    EXPECT_EQ(processR(value, 10), 5);
    value = 20;
    EXPECT_EQ(processR(value, 15), 35);
}

TEST(DayOneTest, ProcessR_StopsAtNinetyNine) {
    int value = 50;
    EXPECT_EQ(processR(value, 49), 99);
}

TEST(DayOneTest, ProcessR_WrapsWithGreaterValues) {
    int value = 80;
    EXPECT_EQ(processR(value, 250), 30);
}

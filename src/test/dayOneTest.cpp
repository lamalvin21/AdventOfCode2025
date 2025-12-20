#include <gtest/gtest.h>

#include "../dayOne/dayOne.h"

// ./run_tests.sh

TEST(DayOneTest, ReturnsZeroByDefault) {
    EXPECT_EQ(dayOne(), 0);
}

TEST(DayOneTest, ProcessL_WrapsAroundCorrectly) {
    int value = 10;
    EXPECT_EQ(processL(value, 15).first, 95);
    value = 5;
    EXPECT_EQ(processL(value, 3).first, 2);
}

TEST(DayOneTest, ProcessL_StopsAtZero) {
    int value = 50;
    EXPECT_EQ(processL(value, 50).first, 0);
}

TEST(DayOneTest, ProcessL_WrapsWithGreaterValues) {
    int value = 50;
    EXPECT_EQ(processL(value, 236).first, 14);
}

TEST(DayOneTest, ProcessR_WrapsAroundCorrectly) {
    int value = 95;
    EXPECT_EQ(processR(value, 10).first, 5);
    value = 20;
    EXPECT_EQ(processR(value, 15).first, 35);
}

TEST(DayOneTest, ProcessR_StopsAtNinetyNine) {
    int value = 50;
    EXPECT_EQ(processR(value, 49).first, 99);
}

TEST(DayOneTest, ProcessR_WrapsWithGreaterValues) {
    int value = 80;
    EXPECT_EQ(processR(value, 250).first, 30);
}

TEST(DayOneTest, Crossings_Counts_For_Large_LeftMoves) {
    int value = 50;
    auto res1 = processL(value, 68);
    EXPECT_EQ(res1.first, 82);
    EXPECT_EQ(res1.second, 1);

    auto res2 = processL(value, 500);
    EXPECT_EQ(res2.first, 50);
    EXPECT_EQ(res2.second, 5);
}

TEST(DayOneTest, Crossings_Counts_For_Large_RightMoves) {
    int value = 50;
    auto res1 = processR(value, 236);
    EXPECT_EQ(res1.first, 86);
    EXPECT_EQ(res1.second, 2);

    value = 80;
    auto res2 = processR(value, 250);
    EXPECT_EQ(res2.first, 30);
    EXPECT_EQ(res2.second, 3);
}

TEST(DayOneTest, Crossings_From_Zero) {
    int value = 0;
    auto res1 = processL(value, 150);
    EXPECT_EQ(res1.second, 1);
    auto res2 = processR(value, 250);
    EXPECT_EQ(res2.second, 2);
}

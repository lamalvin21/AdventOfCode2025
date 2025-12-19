#include <gtest/gtest.h>

#include "../impl/dayOne.h"

// ./run_tests.sh

TEST(DayOneTest, ReturnsZeroByDefault) {
    EXPECT_EQ(dayOne(), 0);
}


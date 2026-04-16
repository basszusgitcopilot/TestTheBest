#include "MathUtils.h"
#include <gtest/gtest.h>

TEST(TestTheBestLib, factorial) {
    ASSERT_EQ(1, factorial(0));
    ASSERT_EQ(1, factorial(1));
    ASSERT_EQ(2, factorial(2));
    ASSERT_EQ(6, factorial(3));
}
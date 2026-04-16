#include "MathUtils.h"
#include <gtest/gtest.h>

TEST(TestTheBestLib, testFactorial) {
    ASSERT_EQ(1, factorial(0));
    ASSERT_EQ(1, factorial(1));
    ASSERT_EQ(2, factorial(2));
    ASSERT_EQ(6, factorial(3));
}

auto checkCrossProduct(Vector3D v1, Vector3D v2, Vector3D expected) -> bool {
    auto cp = crossProduct(v1, v2);
    return expected.x == cp.x && expected.y == cp.y && expected.z == cp.z;
}

TEST(TestTheBestLib, testCrossProduct) {
    ASSERT_TRUE(checkCrossProduct({-1, 0, 2}, {3, 1, 1}, {-2, 7, -1}));
    ASSERT_TRUE(checkCrossProduct({-1, 4, 5}, {1, 1, 1}, {-1, 6, -5}));
}
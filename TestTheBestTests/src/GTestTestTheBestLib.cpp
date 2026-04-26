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

TEST(TestTheBestLib, testDotProduct) {
    ASSERT_EQ(dotProduct3D({1, 5, 0}, {3, 7, 0}), 38);
    ASSERT_EQ(dotProduct3D({4, 0, 1}, {3, 6, 1}), 13);
}

TEST(TestTheBestLib, testAngleBetweenVectors) { ASSERT_EQ(numberToString(angleBetweenVectors({1, 5, 0}, {3, 7, 0}) * 180 / M_PI, 2), "11.89"); }

auto checkLineLineIntersection2D(Line2D l1, Line2D l2, Vector2D expected) -> bool {
    auto lli = lineLineIntersection2D(l1, l2);
    return expected.x == lli.x && expected.y == lli.y;
}

TEST(TestTheBestLib, testLineLineIntersection2D) { ASSERT_TRUE(checkLineLineIntersection2D({{1, 0}, {4, 6}}, {{0, 6}, {9, 0}}, {3, 4})); }

auto checkLinePlaneIntersection(Line3D l, Plane p, Vector3D expected) -> bool {
    auto lpi = linePlaneIntersection(l, p);
    return expected.x == lpi.x && expected.y == lpi.y && expected.z == lpi.z;
}

TEST(TestTheBestLib, testLinePlaneIntersection) {
    ASSERT_TRUE(checkLinePlaneIntersection({{2, -2, 0}, {3, -2, 1}}, {{1, 3, 1}, {0, 0, 0}, {-1, 2, 1}}, {1, -2, -1}));
}

TEST(TestTheBestLib, testAreVectorsParallel2D) {
    ASSERT_TRUE(areVectorsParallel2D({1, 2}, {2, 4}));
    ASSERT_TRUE(areVectorsParallel2D({-1, 2}, {2, -4}));
    ASSERT_TRUE(areVectorsParallel2D({-1, -2}, {2, 4}));
    ASSERT_TRUE(areVectorsParallel2D({-1, -2}, {-2, -4}));
}

TEST(TestTheBestLib, testAreLinesParallel2D) { ASSERT_TRUE(areLinesParallel2D({{0, 0}, {1, 1}}, {{1, 0}, {2, 1}})); }

TEST(TestTheBestLib, testIsCoordinateOnLine2D) { ASSERT_TRUE(isCoordinateOnLine2D({1, 1}, {{-1, -1}, {5, 5}})); }

TEST(TestTheBestLib, testAreTheSameLines) { ASSERT_TRUE(areTheSameLines({{0, 0}, {1, 1}}, {{-1, -1}, {2, 2}})); }

TEST(TestTheBestLib, testIsCoordinateOnPlane) { ASSERT_TRUE(isCoordinateOnPlane({1, -2, -1}, {{1, 3, 1}, {0, 0, 0}, {-1, 2, 1}})); }

TEST(TestTheBestLib, testBinomDistExpectedValue) { ASSERT_EQ(expectedValueBinomialDistribution(100, 0.4), 40); }

TEST(TestTheBestLib, testBinomDistStandardDeviation) { ASSERT_EQ(standardDeviationBinomialDistribution(100, 0.5), 5); }

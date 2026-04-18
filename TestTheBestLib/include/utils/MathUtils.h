#pragma once

#include <cmath>
#include <iomanip>
#include <numbers>
#include <random>
#include <sstream>

struct Vector2D {
    double x = 0;
    double y = 0;
    auto operator-(const Vector2D &other) const -> Vector2D;
};

struct Vector3D {
    double x = 0;
    double y = 0;
    double z = 0;
    auto operator-(const Vector3D &other) const -> Vector3D;
};

struct Line2D {
    Line2D() = default;
    Line2D(Vector2D _a, Vector2D _b);
    Vector2D a;
    Vector2D b;
};

template <class T> auto createRandomNumber(T min, T max) -> T {
    std::random_device randomDevice;
    std::default_random_engine randomEngine(randomDevice());

    std::uniform_int_distribution<T> uniformDist(min, max);
    return uniformDist(randomEngine);
}

template <class T> auto numberToString(T number, uint8_t precision = 0) -> std::string {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << number;
    return stream.str();
}

auto factorial(uint64_t a) -> uint64_t;
auto bincoeff(uint64_t n, uint64_t k) -> uint64_t;
auto vectorLength3D(Vector3D v1) -> double;
auto dotProduct2D(Vector2D v1, Vector2D v2) -> double;
auto dotProduct3D(Vector3D v1, Vector3D v2) -> double;
auto crossProduct(Vector3D v1, Vector3D v2) -> Vector3D;
auto angleBetweenVectors(Vector3D v1, Vector3D v2) -> double;
auto lineLineIntersection2D(Line2D l1, Line2D l2) -> Vector2D;
#include "MathUtils.h"

auto Vector2D::operator-(const Vector2D &other) const -> Vector2D { return {x - other.x, y - other.y}; }

auto Vector3D::operator-(const Vector3D &other) const -> Vector3D { return {x - other.x, y - other.y, z - other.z}; }

Line2D::Line2D(Vector2D _a, Vector2D _b) : a{_a}, b{_b} {};

Line3D::Line3D(Vector3D _a, Vector3D _b) : a{_a}, b{_b} {};

Plane::Plane(Vector3D _a, Vector3D _b, Vector3D _c) : a{_a}, b{_b}, c{_c} {};

auto factorial(uint64_t a) -> uint64_t {
    uint64_t result = 1;
    for (; a >= 2; a--) {
        result *= a;
    }
    return result;
}

auto bincoeff(uint64_t n, uint64_t k) -> uint64_t {
    if (k > n) {
        return 0;
    }

    uint64_t res = 1;

    for (uint64_t i = n; i > n - k; --i) {
        res *= i;
    }
    for (uint64_t i = k; i > 1; --i) {
        res /= i;
    }
    return res;
}

auto vectorLength3D(Vector3D v) -> double { return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }

auto dotProduct2D(Vector2D v1, Vector2D v2) -> double { return v1.x * v2.x + v1.y * v2.y; }

auto dotProduct3D(Vector3D v1, Vector3D v2) -> double { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }

auto crossProduct(Vector3D v1, Vector3D v2) -> Vector3D {
    return Vector3D{.x = v1.y * v2.z - v1.z * v2.y, .y = v1.z * v2.x - v1.x * v2.z, .z = v1.x * v2.y - v1.y * v2.x};
}

auto angleBetweenVectors(Vector3D v1, Vector3D v2) -> double { return std::acos(dotProduct3D(v1, v2) / vectorLength3D(v1) / vectorLength3D(v2)); }
auto lineLineIntersection2D(Line2D l1, Line2D l2) -> Vector2D {
    auto m = l1.b - l1.a;
    auto n = l2.b - l2.a;
    double i = (l2.a.y - l2.a.x * n.y / n.x - l1.a.y + l1.a.x * n.y / n.x) / (m.y - m.x * n.y / n.x);
    double s1 = l1.a.x + i * m.x;
    double s2 = l1.a.y + i * m.y;
    return Vector2D{s1, s2};
}

auto linePlaneIntersection(Line3D l, Plane p) -> Vector3D {
    Vector3D pab = p.b - p.a;
    Vector3D pac = p.c - p.a;
    Vector3D n = crossProduct(pab, pac);

    Vector3D lab = l.b - l.a;

    double t = (n.x * (p.a.x - l.a.x) + n.y * (p.a.y - l.a.y) + n.z * (p.a.z - l.a.z)) / (n.x * lab.x + n.y * lab.y + n.z * lab.z);
    return Vector3D{.x = l.a.x + lab.x * t, .y = l.a.y + lab.y * t, .z = l.a.z + lab.z * t};
}
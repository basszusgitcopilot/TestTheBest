#include "MathUtils.h"

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

    for (int i = n; i > n - k; --i) {
        res *= i;
    }
    for (int i = k; i > 1; --i) {
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
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

auto vectorLength(double a1, double a2, double a3) -> double { return std::sqrt(a1 * a1 + a2 * a2 + a3 * a3); }
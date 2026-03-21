#pragma once

#include <cmath>
#include <iomanip>
#include <numbers>
#include <random>
#include <sstream>

template <class T> auto createRandomNumber(T min, T max) -> T {
    std::random_device randomDevice;
    std::default_random_engine randomEngine(randomDevice());

    std::uniform_int_distribution<T> uniformDist(min, max);
    return uniformDist(randomEngine);
}

template <class T> auto numberToString(T number, uint8_t precision) -> std::string {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << number;
    return stream.str();
}
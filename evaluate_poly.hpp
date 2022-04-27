#include <iostream>
#include <vector>
#include <math.h>
#include <stdexcept>

#pragma once

template<typename T, size_t N>
class Polynomial {
    T coef[N];
public:
    constexpr Polynomial(const T c[N]) : coef() {
        for (size_t i = 0; i < N; ++i) {
            coef[i] = c[i];
        }
    }

    constexpr const T operator[](size_t i) const {
        if (i < N) {
            return coef[i];
        } else {
            return 0;
        }
    }
};

template<typename T, size_t N>
std::ostream& operator<<(std::ostream& os, const Polynomial<T, N>& p) {   
    for (int i = N - 1; i >= 0; --i) {
        if (p[i] == 0) {
            continue;
        }

        if (p[i] > 0) {
            os << " + ";
        } else {
            os << " - ";
        }
        
        os << std::abs(p[i]) << "*x^" << i;
    }

    os << '\n';

    return os;
}

template<typename T, size_t N>
constexpr T evaluate(T x, const Polynomial<T, N>& p) {
    T res = 0;
    T pow_x = 1;

    for (size_t i = 0; i < N; ++i) {
        res += p[i] * pow_x;
        pow_x *= x;
    }

    return res;
}
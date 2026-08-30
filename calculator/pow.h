#pragma once

#include "rational.h"
#include <cmath>

template<class Number>
Number IntegerPow(Number l_op, Number r_op) {
    Number res = 1;
    while (r_op > 0) {
        if (r_op & 1) {
            res *= l_op;
        }
        r_op >>= 1;
        l_op *= l_op;
    }
    return res;
}

inline Rational Pow(Rational lhs, Rational rhs) {
    if (rhs.GetDenominator() != 1) {
        std::abort();
    }
    auto pow = rhs.GetNumerator();
    if (pow >= 0) {
        return {IntegerPow(lhs.GetNumerator(), pow), IntegerPow(lhs.GetDenominator(), pow)};
    } else {
        return {IntegerPow(lhs.GetDenominator(), -pow), IntegerPow(lhs.GetNumerator(), -pow)};
    }
}

template<class Number>
Number TemplatePow(Number lhs, Number rhs){return std::pow(lhs,rhs);}

template<>
Rational TemplatePow(Rational lhs, Rational rhs){
    return Pow(lhs, rhs);
}

template<>
int64_t TemplatePow(int64_t lhs, int64_t rhs){
    return IntegerPow(lhs,rhs);
}

template<>
double TemplatePow(double lhs, double rhs){
    return std::pow(lhs,rhs);
}
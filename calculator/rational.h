#pragma once

#include <iostream>
#include <numeric>
#include <cstdint>

class Rational{
public:
    Rational() = default;

    Rational(int64_t numerator, int64_t denominator){
        if(denominator==0){
            numerator_ = numerator;
        }
        else if(denominator<0){
            numerator_ = -1*numerator;
            denominator_ = -1*denominator;
        }
        else{
            numerator_ = numerator;
            denominator_ = denominator;
        }
        Reduction();
    }

    Rational(int64_t numerator):
        numerator_{numerator}
    {}

    Rational Inv() const{
        if(numerator_<0){
            return Rational(-1 * denominator_, -1 * numerator_);
        }
        return Rational(denominator_, numerator_);
    }

    int64_t GetNumerator() const{
        return numerator_;
    }

    int64_t GetDenominator() const{
        return denominator_;
    }

    auto operator<=>(const Rational& r) const{
        int64_t a = GetNumerator() * r.GetDenominator();
        int64_t b = GetDenominator() * r.GetNumerator();
        return a<=>b;
    }

    bool operator==(const Rational& r) const{
        return (GetNumerator()==r.GetNumerator())&&(GetDenominator()==r.GetDenominator());
    }

    Rational& operator+=(const Rational& r){
        int64_t a = GetNumerator() * r.GetDenominator();
        int64_t b = GetDenominator() * r.GetNumerator();
        int64_t c = GetDenominator()*r.GetDenominator();
        numerator_ = a + b;
        denominator_ = c;
        Reduction();
        return *this;
    }

    Rational& operator-=(const Rational& r){
        int64_t a = GetNumerator() * r.GetDenominator();
        int64_t b = GetDenominator() * r.GetNumerator();
        int64_t c = GetDenominator()*r.GetDenominator();
        numerator_ = a - b;
        denominator_ = c;
        Reduction();
        return *this;
    }

    Rational& operator*=(const Rational& r){
        int64_t a = GetNumerator() * r.GetNumerator();
        int64_t b = GetDenominator()*r.GetDenominator();
        numerator_ = a;
        denominator_ = b;
        Reduction();
        return *this;
    }

    Rational& operator/=(const Rational& r){
        int64_t a = GetNumerator() * r.GetDenominator();
        int64_t b = GetDenominator() * r.GetNumerator();
        numerator_ = a;
        denominator_ = b;
        Reduction();
        return *this;
    }

    Rational operator+(const Rational& r) const{
        Rational result = *this;
        result+=r;
        return result;
    }

    Rational operator-(const Rational& r) const{
        Rational result = *this;
        result-=r;
        return result;
    }

    Rational operator/(const Rational& r) const{
        Rational result = *this;
        result/=r;
        return result;
    }

    Rational operator*(const Rational& r) const{
        Rational result = *this;
        result*=r;
        return result;
    }

    Rational operator+() const{
        return *this;
    }

    Rational operator-() const{
        return Rational{-1 * GetNumerator(), GetDenominator()};
    }

    void Reduction() {
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        const int64_t divisor = std::gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }

    friend std::istream& operator>>(std::istream& is, Rational& r);
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
private:
    int64_t numerator_ = 0;
    int64_t denominator_ = 1;
};

inline std::istream& operator>>(std::istream& is, Rational& r){
    int n = 0;
    int d = 0;
    char ch =' ';
    is >> std::ws >> n;
    if(is.fail()){
        return is;
    }
    is >> ch;
    if(is.fail()){
        is.clear();
        r = Rational(n, 1);
        return is;
    }
    else if(ch == '/'){
        is >> d;
        if(d==0){
            is.setstate(std::ios::failbit);
            return is;
        }
    }
    else{
        is.unget();
        r = Rational{n,1};
        return is;
    }
    r = Rational{n,d};
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Rational& r){
    if(r.denominator_ == 1){
        os << r.numerator_;
        return os;
    }
    os << r.numerator_ << " / " << r.denominator_;
    return os;
}
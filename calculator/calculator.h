
#pragma once

#include <string>
#include <optional>
#include "rational.h"
#include "pow.h"

using Error = std::string;

// Реализация шаблонного калькулятора.

template<typename Number>
class Calculator{
public:
    bool GetHasMem() const{
        return mem_.has_value();
    }
    void Set(Number n){
        current_num_ = n;
    }
    Number GetNumber() const{
        return current_num_;
    }
    std::optional<Error> Add(Number n){
        current_num_+=n;
        return std::nullopt;
    }
    std::optional<Error> Sub(Number n){
        current_num_-=n;
        return std::nullopt;
    }
    std::optional<Error> Div(Number n){
        if constexpr(std::is_same_v<Number, int> || std::is_same_v<Number, uint8_t> ||
                      std::is_same_v<Number, size_t> || std::is_same_v<Number, int64_t>){
            if(n==0){
                return "Division by zero";
            }
            else{
                current_num_/=n;
                return std::nullopt;
            }
        }
        else if constexpr(std::is_same_v<Number, Rational>){
            if(n.GetNumerator()==0){
                return "Division by zero";
            }
            else{
                current_num_/=n;
                return std::nullopt;
            }
        }
        else{
            current_num_= current_num_/n;
            return std::nullopt;
        }

    }
    std::optional<Error> Mul(Number n){
        current_num_*=n;
        return std::nullopt;
    }
    std::optional<Error> Pow(Number n){
        if constexpr (std::is_same_v<Number, Rational>){
            if(current_num_.GetNumerator() == 0 && n.GetNumerator() == 0){
                return "Zero power to zero";
            }
            if(n.GetDenominator()!=1){
                return "Fractional power is not supported";
            }
            else{
                current_num_ = TemplatePow(current_num_, n);
                return std::nullopt;
            }
        }
        else if constexpr(std::is_same_v<Number, int> || std::is_same_v<Number, uint8_t> ||
                             std::is_same_v<Number, size_t> || std::is_same_v<Number, int64_t>){
            if(current_num_ == 0 && n == 0){
                return "Zero power to zero";
            }
            if(n < 0){
                return "Integer negative power";
            }
            else{
                current_num_ = TemplatePow(current_num_, n);
                return std::nullopt;
            }
        }
        else{
            if(n==0 && current_num_==0){
                return "Zero power to zero";
            }
            current_num_=TemplatePow(current_num_,n);
            return std::nullopt;
        }
    }
    void Save(){
        mem_ = current_num_;
    }
    void Load(){
        if(GetHasMem()){
            current_num_ = mem_.value();
        }
    }
private:
    Number current_num_;
    std::optional<Number> mem_ = std::nullopt;
};
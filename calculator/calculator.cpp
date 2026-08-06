#include "calculator.h"
#include <cmath>

void Calculator::Set(Number n){
    current_num_=n;
}

Number Calculator::GetNumber() const{
    return current_num_;
}

void Calculator::Add(Number n){
    current_num_+=n;
}
void Calculator::Sub(Number n){
    current_num_-=n;
}
void Calculator::Div(Number n){
    current_num_/=n;
}
void Calculator::Mul(Number n){
    current_num_*=n;
}
void Calculator::Pow(Number n){
    current_num_=std::pow(current_num_,n);
}

void Calculator::Save(){
    mem_=current_num_;
    mem_empty_=false;
}

void Calculator::Load(){
    current_num_=mem_;
}

bool Calculator::HasMem() const{
    return !mem_empty_;
}

std::string Calculator::GetNumberRepr() const{
    return std::to_string(current_num_);
}
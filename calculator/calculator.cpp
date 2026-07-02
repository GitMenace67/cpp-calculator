#include <iostream>
#include <cmath>
#include <string>

#include "calculator.h"


bool ReadNumber(Number& result) {
    if (std::cin >> result) {
        return true;
    }
    std::cerr << "Error: Numeric operand expected" << std::endl;
    return false;
}

bool RunCalculatorCycle() {
    Number total = 0; 
    Number current_num = 0; 
    Number memory=0;
    Number power=0; 
    bool memory_initialized = false; 
    std::string oper;

    if (!ReadNumber(total)) {
        return false;
    }
    std::cin >> oper;

    while (true) {
        if (oper == "+") {
            if (!ReadNumber(current_num)) {
                return false;
            }
            total += current_num;
        }
        else if (oper == "-") {
            if (!ReadNumber(current_num)) {
                return false;
            }
            total -= current_num;
        }
        else if (oper == "*") {
            if (!ReadNumber(current_num)) {
                return false;
            }
            total *= current_num;
        }
        else if (oper == "/") {
            if (!ReadNumber(current_num)) {
                return false;
            }
            total /= current_num;
        }
        else if (oper == "**") {
            if (!ReadNumber(power)) {
                return false;
            }
            total = std::pow(total, power);
        }
        else if (oper == "=") {
            std::cout << total << std::endl;
        }
        else if (oper == "q") {
            return true;
        }
        else if (oper == "s") {
            memory = total;
            memory_initialized = true;
        }
        else if (oper == "l") {
            if (memory_initialized) {
                total = memory;
            }
            else {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
        }
        else if (oper == ":") {
            if (!ReadNumber(current_num)) {
                return false;
            }
            total = current_num;
        }
        else if (oper == "c") {
            total = 0;
        }
        else {
            std::cerr << "Error: Unknown token " << oper << std::endl;
            return false;
        }
        std::cin >> oper;
    }
    return true;


}
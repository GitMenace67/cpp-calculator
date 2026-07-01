#include <iostream>
#include <cmath>
#include <string>

#include "calculator.h"


bool ReadNumber(Number& result) {
    if (std::cin >> result) {
        return true;
    }
    else {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
}

bool RunCalculatorCycle() {
    Number total = 0; //ответ на вычисляемое выражение
    Number current_num = 0; //новое число, вводимое пользователем в выражение
    Number memory;
    Number power; //вспомогательная переменная для возведения в степень
    bool memory_initialized = false; // для проверки наличия значения в памяти
    bool checked = true;
    std::string oper; //выполняемая операция

    if (!ReadNumber(total)) {
        return false;
    }
    std::cin >> oper;

    while (checked) {
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
                std::cerr << "Error: Memory is empty";
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
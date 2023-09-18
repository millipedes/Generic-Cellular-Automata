#include "cell/cell.h"
#include <iostream>

bool cell::compare_cell_index(const cell_index& b) {
    if(std::holds_alternative<std::array<int, 2>>(_index)
        && std::holds_alternative<std::array<int, 2>>(b)) {
        return std::get<std::array<int, 2>>(_index) == std::get<std::array<int, 2>>(b);
    } else if(std::holds_alternative<double>(_index)
        && std::holds_alternative<double>(b)) {
        return std::get<double>(_index) == std::get<double>(b);
    }
    return false;
}

bool cell::compare_cell_value(const cell_value& b) {
    if(std::holds_alternative<bool>(_value) && std::holds_alternative<bool>(b)) {
        return std::get<bool>(_value) == std::get<bool>(b);
    } else if(std::holds_alternative<qualitative_value>(_value)
        && std::holds_alternative<qualitative_value>(b)) {
        return std::get<qualitative_value>(_value) == std::get<qualitative_value>(b);
    } else if(std::holds_alternative<double>(_value)
        && std::holds_alternative<double>(b)) {
        return std::get<double>(_value) == std::get<double>(b);
    }
    return false;
}

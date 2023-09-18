#pragma once

#include <array>
#include <variant>

typedef enum {
} qualitative_value;

using cell_index = std::variant<std::array<int, 2>, double>;
using cell_value = std::variant<bool, qualitative_value, double>;

class cell {
  public:
    cell() = default;
    cell(const cell_value& value, const cell_index& index)
      : _value(value), _index(index) {};
    cell(const cell& src) : _value(src._value), _index(src._index) {};
    cell& operator=(const cell& src) {
      if(this != &src) {
        _value = src._value;
        _index = src._index;
      }
      return *this;
    }
    cell(cell&& src) noexcept : _value(std::move(src._value)),
                                _index(std::move(src._index)) {}

    bool compare_cell_index(const cell_index& b);
    bool compare_cell_value(const cell_value& b);

    bool operator==(const cell& src) {
      return (compare_cell_value(src._value) && compare_cell_index(src._index));
    }
    bool operator!=(const cell& src) { return !(*this == src); }

    cell_value value() { return _value; }
    bool& binary_cell_value() { return std::get<bool>(_value); }
    qualitative_value& qualitative_cell_value()
      { return std::get<qualitative_value>(_value); }
    double& quantitative_cell_value() { return std::get<double>(_value); }
    cell_index index() { return _index; }
    std::array<int, 2> index_cartesian()
      { return std::get<std::array<int, 2>>(_index); }
    double index_polar() { return std::get<double>(_index); }

  private:
    cell_value _value;
    cell_index _index;
};

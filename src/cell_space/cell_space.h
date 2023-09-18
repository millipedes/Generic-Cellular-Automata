#pragma once

#include <array>
#include <functional>
#include <iostream>
#include <variant>
#include <vector>

#include "cell/cell.h"

class cell_space {
  using cell_val = std::variant<std::vector<std::vector<cell>>,
                                  std::vector<cell>>;
  public:
    cell_space(const cell_val& cells, const cell_index& bounds,
               const std::function<int(int)>& timestep_function,
               const std::function<void(cell_space*, cell&)>& trans_function)
      : _cells(cells),
        _bounds(bounds),
        _timestep_function(timestep_function),
        _trans_function(trans_function),
        _generation(0) {}
    cell_space(const cell_space& src)
      : _cells(src._cells),
        _bounds(src._bounds),
        _timestep_function(src._timestep_function),
        _trans_function(src._trans_function),
        _generation(src._generation) {}
    cell_space& operator=(const cell_space& src) {
        if (this != &src) {
            _cells = src._cells;
            _bounds = src._bounds;
            _timestep_function = src._timestep_function;
            _trans_function = src._trans_function;
            _generation = src._generation;
        }
        return *this;
    }
    cell_space(cell_space&& src) noexcept
      : _cells(std::move(src._cells)),
        _bounds(std::move(src._bounds)),
        _timestep_function(std::move(src._timestep_function)),
        _trans_function(std::move(src._trans_function)),
        _generation(std::move(src._generation)) {}

    std::vector<std::vector<cell>>& cartesian_cells()
      { return std::get<std::vector<std::vector<cell>>>(_cells); }
    std::vector<cell>& polar_cells()
      { return std::get<std::vector<cell>>(_cells); }

    std::array<int, 2> cartesian_bound()
      { return std::get<std::array<int, 2>>(_bounds); }
    double polar_bounds() { return std::get<double>(_bounds); }

    void advance_generation(void);
    void print_cells(void);


  private:
    cell_val _cells;
    cell_index _bounds;
    std::function<int(int)> _timestep_function;
    std::function<void(cell_space*, cell&)> _trans_function;
    int _generation;
};

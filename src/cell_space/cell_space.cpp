#include "cell_space.h"

void cell_space::advance_generation(void) {
  _generation = _timestep_function(_generation);
  if(std::holds_alternative<std::vector<cell>>(_cells)) {
    auto& cells = std::get<std::vector<cell>>(_cells);
    std::for_each(cells.begin(), cells.end(), [this](cell& c) {
        _trans_function(this, c);
    });
  } else if(std::holds_alternative<std::vector<std::vector<cell>>>(_cells)) {
    auto& cells = std::get<std::vector<std::vector<cell>>>(_cells);
    std::for_each(cells.begin(), cells.end(), [this](std::vector<cell>& row) {
          std::for_each(row.begin(), row.end(), [this](cell& c) {
                _trans_function(this, c);
              });
        });
  }
}

void cell_space::print_cells(void) {
  if(std::holds_alternative<std::vector<cell>>(_cells)) {
    // TODO find reasonable way to iterate over polar cells
  } else if(std::holds_alternative<std::vector<std::vector<cell>>>(_cells)) {
    auto& bounds = std::get<std::array<int, 2>>(_bounds);
    auto& cells = std::get<std::vector<std::vector<cell>>>(_cells);
    std::cout << "=========" << std::endl;
    for(int i = 0; i < bounds[0]; i++) {
      for(int j = 0; j < bounds[1]; j++) {
        std::cout << cells[i][j].binary_cell_value() << " ";
      }
      std::cout << std::endl;
    }
    std::cout << "=========" << std::endl;
  }
}

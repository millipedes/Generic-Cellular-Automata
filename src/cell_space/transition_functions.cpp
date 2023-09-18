#include "transition_functions.h"
#include <iostream>

namespace transition_functions {

bool is_valid_index(int i, int j, int i_inc, int j_inc,
    std::array<int, 2> bounds) {
  if(i + i_inc < 0 || i + i_inc >= bounds[0]
      || j + j_inc < 0 || j + j_inc >= bounds[1]) {
    return false;
  }
  return true;
}

void conway(cell_space * the_cell_space, cell& update_cell) {
  auto update_cell_index = update_cell.index_cartesian();
  auto& update_cell_value = update_cell.binary_cell_value();

  auto& cells = the_cell_space->cartesian_cells();
  auto bounds = the_cell_space->cartesian_bound();

  int living_neighbor_count = 0;

  for(int i = -1; i < 2; i++) {
    for(int j = -1; j < 2; j++) {
      if(is_valid_index(update_cell_index[0], update_cell_index[1], i, j, bounds)) {
        if(cells[update_cell_index[0] + i][update_cell_index[1] + j].binary_cell_value() == true
            && cells[update_cell_index[0] + i][update_cell_index[1] + j] != update_cell) {
          living_neighbor_count++;
        }
      }
    }
  }

  std::cout << living_neighbor_count << std::endl;

  if(update_cell_value == true) {
    if(living_neighbor_count < 2 || living_neighbor_count > 3) {
      std::cout << update_cell_value << " FALSE " << living_neighbor_count << std::endl;
      update_cell_value = false;
    }
  } else {
    if(living_neighbor_count == 3) {
      std::cout << "TRUE " << living_neighbor_count << std::endl;
      update_cell_value = true;
    }
  }
}

}

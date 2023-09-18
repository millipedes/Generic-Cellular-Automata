#include "cell_space/timestep_functions.h"
#include "cell_space/transition_functions.h"
#include "file_io/file_io.h"

int main(void) {
  auto cells = read_conway_file("test.conway");
  auto space = cell_space(cells, std::array<int, 2>({5, 5}), timestep_functions::add_one, transition_functions::conway);
  space.print_cells();
  space.advance_generation();
  space.print_cells();
  return 0;
}

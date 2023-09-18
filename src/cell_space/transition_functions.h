#pragma once

#include "cell_space/cell_space.h"

namespace transition_functions {
  void conway(cell_space * the_cell_space, cell& update_cell);
}

#include "file_io.h"

std::vector<std::vector<cell>> read_conway_file(std::string file_name) {
  std::ifstream input_file(file_name);

  if(!input_file.is_open()) {
    std::cerr << "[READ_CONWAY_FILE]: Unable to open " << file_name << std::endl;
    return {};
  }

  int rows = 0;
  int cols = 0;
  std::vector<std::vector<cell>> cells = {};
  cells.push_back({});

  while(!input_file.eof()) {
    auto c = input_file.get();
    if(c == '1') {
      cells[cols].push_back(cell(true, std::array<int, 2>({cols, rows})));
    } else if(c == '0') {
      cells[cols].push_back(cell(false, std::array<int, 2>({cols, rows})));
    } else if(c == '\n') {
      cols++;
      cells.push_back({});
    }
  }

  input_file.close();
  return cells;
}

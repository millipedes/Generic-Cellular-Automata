#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "cell/cell.h"

std::vector<std::vector<cell>> read_conway_file(std::string file_name);

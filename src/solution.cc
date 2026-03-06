#include "solution.hpp"

#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

#include "item.hpp"

std::vector<Item> LoadShoppingItemsFromFile(const std::string& filename) {
  std::vector<Item> shopping_items;
  std::ifstream ifs{filename};
  if (!ifs.is_open()) {
    throw std::invalid_argument("can't open!!!");
  }

  while (ifs.good()) {
    std::string name;
    int quant = 0;
    double pri = 0.0;
    ifs >> name;
    if (ifs.fail()) {
      ifs.clear();
      ifs.ignore(name.length(), ' ');
    }
    ifs >> quant;
    if (ifs.fail()) {
      ifs.clear();
      ifs.ignore(2, ' ');
    }
    ifs >> pri;
    if (ifs.fail()) {
      ifs.clear();
      ifs.ignore(4, ' ');
    }
    Item it = {name, quant, pri};
    shopping_items.push_back(it);
  }
  return shopping_items;
}
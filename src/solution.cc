#include "solution.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "item.hpp"

std::vector<Item> LoadShoppingItemsFromFile(const std::string& filename) {
  std::vector<Item> shopping_items;
  std::ifstream ifs{filename};
  if (!ifs.is_open()) {
    throw std::invalid_argument("invalid!!!");
  }
  if (ifs.tellg() < 1) {
    throw std::invalid_argument("invalid!!!");
  }

  std::string file_headers;
  std::getline(ifs, file_headers);

  while (ifs.good()) {
    std::string name;
    int quant = 0;
    double pri = 0.0;
    char redox = ' ';
    try {
      std::cin >> name >> redox >> quant >> redox >> pri;
    } catch (...) {
      throw std::invalid_argument("invalid!!!");
    }
    if (ifs.fail()) {
      throw std::invalid_argument("invlaid!!");
    }
    Item it = {name, quant, pri};
    shopping_items.push_back(it);
  }
  return shopping_items;
}
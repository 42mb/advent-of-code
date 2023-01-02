#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <ranges>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void day6_1() {
  std::fstream file;
  file.open("input_day6.prod", std::ios::in);
  if (file.is_open()) {
    std::string line;

    while (getline(file, line)) {
      bool isfirst = true;
      std::unordered_set<char> unique;

      for (int i = 0; isfirst && i < line.size() - 4; ++i) {
        unique.insert(line.begin() + i, line.begin() + i + 4);

        if (unique.size() == 4) {
          std::cout << i + 4 << "\n";
          isfirst = false;
        }
        unique.clear();
      }
    }
  }
}

void day6_2() {

  std::fstream file;
  file.open("input_day6.prod", std::ios::in);
  if (file.is_open()) {
    std::string line;

    while (getline(file, line)) {
      bool isfirst = true;
      std::unordered_set<char> unique;

      for (int i = 0; isfirst && i < line.size() - 14; ++i) {
        unique.insert(line.begin() + i, line.begin() + i + 14);

        if (unique.size() == 14) {
          std::cout << i + 14 << "\n";
          isfirst = false;
        }
        unique.clear();
      }
    }
  }
}

int main() {

  std::cout << "day1: " << '\n';
  day6_1();
  std::cout << "\n";
  std::cout << "day2: " << '\n';
  day6_2();
}
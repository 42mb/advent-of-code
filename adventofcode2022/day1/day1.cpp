#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

void day1_1() {
  int max_calories{};
  std::fstream file;
  file.open("input_day1p1.txt", std::ios::in);
  if (file.is_open()) {
    std::string line;
    int calories{};
    while (getline(file, line)) {
      // std::cout<<line<<"\n";
      if (!line.empty()) {
        calories += std::stoi(line);
      } else {
        max_calories = std::max(max_calories, calories);
        calories = 0;
      }
    }
  }
  std::cout << max_calories << std::endl;
}

void day1_2() {
  std::vector<int> max_calories(3, 0);

  std::fstream file;
  file.open("input_day1p1.txt", std::ios::in);
  if (file.is_open()) {
    std::string line;
    int calories{};
    while (getline(file, line)) {
      // std::cout << line << "\n";
      if (!line.empty()) {
        calories += std::stoi(line);
      } else {
        max_calories.push_back(calories);
        // todo better use std::array<int, 3> ->compare if larger than array[2]
        // -> if(true)swap -> resort
        std::sort(max_calories.rbegin(), max_calories.rend());
        // std::ranges::sort(max_calories, std::ranges::greater());
        max_calories.pop_back();
        calories = 0;
      }
    }
  }
  int maxsum{};
  for (auto &x : max_calories) {
    // std::cout << x << "\n";
    maxsum += x;
  }
  std::cout << maxsum << "\n\n";
}

int main() {

  std::cout << "day1: " << '\n';
  day1_1();
  std::cout << "\n";
  std::cout << "day2: " << '\n';
  day1_2();
}
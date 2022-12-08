#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

void day4_1() {
  int counter_result{};
  std::fstream file;
  file.open("inputfiles/input_day4.prod", std::ios::in);
  if (file.is_open()) {
    std::string line;
    std::string left, right;
    int lb_left, lb_right, ub_left, ub_right; // upper-lowerbound

    while (getline(file, line)) { // alternativ: (file,line, ',')
      int comma = line.find(',');
      left = line.substr(0, comma);
      right = line.substr(comma + 1);
      // std::cout << left << " " << right << '\n';

      lb_left = stoi(left.substr(0, left.find('-')));
      ub_left = stoi(left.substr(left.find('-') + 1));
      lb_right = stoi(right.substr(0, right.find('-')));
      ub_right = stoi(right.substr(right.find('-') + 1));

      // std::cout << lb_left << " " << ub_left << "   " << lb_right << " "
      //           << ub_right << std::endl;

      if ((lb_left >= lb_right && ub_left <= ub_right) ||
          (lb_right >= lb_left && ub_right <= ub_left)) {

        counter_result++;
      }
    }
  }
  std::cout << counter_result;
}

void day4_2() {
  int counter_result{};
  std::fstream file;
  file.open("inputfiles/input_day4.prod", std::ios::in);
  if (file.is_open()) {
    std::string line;
    std::string left, right;
    int lb_left, lb_right, ub_left, ub_right; // upper-lowerbound
    while (getline(file, line)) {
      int comma = line.find(',');
      left = line.substr(0, comma);
      right = line.substr(comma + 1, line.size());
      // std::cout << left << " " << right << '\n';

      lb_left = stoi(left.substr(0, left.find('-')));
      ub_left = stoi(left.substr(left.find('-') + 1));
      lb_right = stoi(right.substr(0, right.find('-')));
      ub_right = stoi(right.substr(right.find('-') + 1));

      // std::cout << lb_left << " " << ub_left << "   " << lb_right << " "
      //           << ub_right << std::endl;

      if (ub_left >= lb_right && ub_right >= lb_left) {
        counter_result++;
      }
    }
    std::cout << "\n"
              << counter_result << "\n"
              << "\n";
  }
}
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <unordered_map>
#include <vector>

void day25_1() {

  std::fstream file;
  const int base = 5;
  long long tmp_nmb{};
  long long result{};
  std::string result_str{};
  file.open("input_day25.prod", std::ios::in);
  if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
      if (!line.empty()) {
        int len = line.length();
        for (int i = 0; i < len; ++i) {
          tmp_nmb = std::pow(base, i);
          //   std::cout << tmp_nmb;
          if (line[len - 1 - i] == '1') {
            tmp_nmb *= 1;
          }
          if (line[len - 1 - i] == '2') {
            tmp_nmb *= 2;
          }
          if (line[len - 1 - i] == '=') {
            tmp_nmb *= -2;
          }
          if (line[len - 1 - i] == '-') {
            tmp_nmb *= -1;
          }
          if (line[len - 1 - i] == '0') {
            tmp_nmb *= 0;
          }
          result += tmp_nmb;
        }
      }
    }
  } else {
    std::cout << "fileclosed";
  }
  std::cout << '\n'
            << '\n'
            << "dez result: " << result << '\n'
            << '\n'
            << '\n'
            << '\n';

  long long k{};
  while (std::abs(result) > (std::pow(base, k))) {
    k++;
  }
  long long tmp_result{};
  long long smallest = result;

  while (k >= 0) {
    long long startingnmb = std::pow(base, k);
    std::vector<std::pair<long long, char>> calcs = {};
    calcs.push_back(std::make_pair(startingnmb * 2, '2'));
    calcs.push_back(std::make_pair(startingnmb, '1'));
    calcs.push_back(std::make_pair(0, '0'));
    calcs.push_back(std::make_pair(startingnmb * -1, '-'));
    calcs.push_back(std::make_pair(startingnmb * -2, '='));
    char min{};

    for (int i = 0; i < 5; ++i) {
      if (std::abs(result - calcs[i].first) <= smallest) {
        min = calcs[i].second;
        smallest = std::abs(result - calcs[i].first);
        tmp_result = result - calcs[i].first;
      }
    }
    result = tmp_result;
    result_str.push_back(min);
    k--;
    // calcs.clear();
  }

  std::cout << "\n\n" << result_str.substr(1);
}

int main() {

  std::cout << "day1: " << '\n';
  day25_1();
  std::cout << "\n";
  // std::cout << "day2: " << '\n';
  // day25_2();
}
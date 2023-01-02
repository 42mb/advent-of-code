#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
typedef boost::tokenizer<boost::char_separator<char>> tokenizer;

void day18_1() {
  std::unordered_map<std::string, int> grid;
  std::fstream file;
  file.open("input_day18.prod", std::ios::in);
  if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
      if (!line.empty()) {
        // std::cout << line << '\n';
        grid[line]++;
      }
    }
  }
  for (auto &i : grid) {
    std::string coordinatestring = i.first;
    boost::char_separator<char> sep(",");
    tokenizer tokens(coordinatestring, sep);
    std::vector<int> tmp;
    BOOST_FOREACH (std::string const &token, tokens) {
      // std::cout << "<" << token << "> " << "\n";
      tmp.push_back(std::stoi(token));
    }
    // check all neighbors of coordinate to have neighbores;
    std::vector<int> possible_neighbors;
    int k = 1;
    for (int t = 0; t < 2; ++t) {
      possible_neighbors.push_back(tmp[0] + k);
      possible_neighbors.push_back(tmp[1]);
      possible_neighbors.push_back(tmp[2]);

      possible_neighbors.push_back(tmp[0]);
      possible_neighbors.push_back(tmp[1] + k);
      possible_neighbors.push_back(tmp[2]);

      possible_neighbors.push_back(tmp[0]);
      possible_neighbors.push_back(tmp[1]);
      possible_neighbors.push_back(tmp[2] + k);
      k = -1;
    }
    std::string tmp_compare{};
    for (int p = 0; p < 18; p += 3) { // queue pop front with a vector
      for (int j = p; j < p + 3; ++j) {
        tmp_compare += std::to_string(possible_neighbors[j]);
        tmp_compare += ",";
      }
      tmp_compare = tmp_compare.substr(0, tmp_compare.length() - 1);
      if (grid.count(tmp_compare) >
          0) { // c20 feature contains would be better so I dont have to
               // initiate the map input with 1 and sub 1 at the calculation
        grid[i.first]++;
      }
      tmp_compare = "";
    }
  }
  // for (auto &x : grid) {
  //   std::cout << x.first[0] << " " << x.first[1] << " " << x.first[2] << " "
  //             << x.second << '\n';
  int result{};
  int cnt{};
  for (auto &x : grid) {
    cnt++;
    result += x.second - 1;
    // std::cout << x.first << " has value " << x.second << std::endl;
  }
  result = 6 * cnt - result;
  std::cout << result;
}

int main() {

  std::cout << "day1: " << '\n';
  day18_1();
  std::cout << "\n";
  // std::cout << "day2: " << '\n';
  // day18_2();
}
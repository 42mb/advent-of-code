#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void day10_1() {
  std::string instruction{};
  int data{}, cycle{}, register_cpu{1}, sum{};

  std::fstream file;
  file.open("input_day10.prod", std::ios::in);
  if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
      instruction = line.substr(0, 4);
      if (line.length() > 4) {
        data = stoi(line.substr(5));
      } else {
        data = 0;
      }

      if (instruction == "noop") {
        cycle++;
      }
      if (instruction == "addx") {
        for (int i = 0; i < 2; ++i) {
          cycle++;
        }
        int tmp_cycle = cycle - 1;
        if (tmp_cycle == 20 || (tmp_cycle - 20) % 40 == 0) {
          sum += tmp_cycle * register_cpu;
        }
      }

      if (cycle == 20 || (cycle - 20) % 40 == 0) {
        sum += cycle * register_cpu;
      }
      register_cpu += data;
    }
  }
  std::cout << sum << '\n';
}

void paint_sprite(std::string &pictureline, int cycle, int register_cpu) {
  if (cycle % 40 == register_cpu - 1) {
    pictureline[register_cpu - 1] = '#';
  }
  if (cycle % 40 == register_cpu) {
    pictureline[register_cpu] = '#';
  }

  if (cycle % 40 == register_cpu + 1) {
    pictureline[register_cpu + 1] = '#';
  }
}

void day10_2() {
  std::string instruction{};
  int data{}, cycle{}, register_cpu{1}, sum{};
  std::vector<std::string> picture;
  std::string pictureline = "........................................";
  picture.push_back(pictureline);

  std::fstream file;
  file.open("input_day10.test", std::ios::in);
  if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
      instruction = line.substr(0, 4);
      if (line.length() > 4) {
        data = stoi(line.substr(5));
      } else {
        data = 0;
      }

      if (instruction == "noop") {
        cycle++;
      }
      if (instruction == "addx") {
        for (int i = 0; i < 2; ++i) {
          cycle++;
          int tmp_cycle = cycle - 1;
          if (tmp_cycle % 40 == 0) {
            picture.push_back(pictureline);
          }
        }

        if (cycle % 40 == 0) {
          picture.push_back(pictureline);
        }
      }
      register_cpu += data;

      paint_sprite(pictureline, cycle, register_cpu);
    }
  }
  // std::cout << sum << '\n';
  for (auto &x : picture) {
    std::cout << x << '\n';
  }
}
int main() {

  std::cout << "day1: " << '\n';
  day10_1();
  std::cout << "\n";
  // std::cout << "day2: " << '\n';
  // day1_2(); //WIP
}
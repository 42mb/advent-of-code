#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void day10_1() {
  std::string instruction{};
  int data{}, cycle{}, register_cpu{1}, sum{};

  std::fstream file;
  file.open("inputfiles/input_day10.prod", std::ios::in);
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

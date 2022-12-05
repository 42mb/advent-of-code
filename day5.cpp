#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <ranges>
#include <stack>
#include <string>
#include <vector>

/////////////////////////////////////////
/////////////////   WIP    //////////////
/////////////////////////////////////////

// // Try to determine the amount of stacks needed and
// // automaticly create and fill them within an vector<deque< >>
// // viable for different inputs (eg. amount of stacks)

// void day5_0() {

//   std::fstream file;
//   std::string container;
//   int stack_number{0}, move{}, from{}, to{};

//   // read out stack_number
//   file.open("inputfiles/input_day5.test", std::ios::in);
//   if (file.is_open()) {
//     std::string line;
//     while (getline(file, line)) {
//       // std::cout << line << '\n';
//       if (std::isdigit(line[1])) {
//         stack_number = static_cast<int>(line[size(line) - 2]) - 48;
//         break;
//       }
//     }
//   }
//   std::vector<std::deque<std::string>> stacks;

//   //   for (int i = 0; i < stack_number; ++i) {
//   //     auto p = new std::deque<char>;
//   //     stacks.push_back(*p);
//   //   }

//   for (int i = 0; i < stack_number; ++i) {
//     stacks.push_back(std::deque<std::string>());
//   }

//   file.close();
//   file.open("inputfiles/input_day5.test", std::ios::in);
//   if (file.is_open()) {
//     std::string line;
//     while (getline(file, line)) {
//       for (int i = 0, k = 1; i < stack_number; ++i, k += 4) {
//         stacks[i].emplace_front(line[k]);
//         std::cout << "blub";
//       }
//     }
//   }
// }

void day5_1() {

  std::vector<std::deque<std::string>> stacks;
  // debug test,  !!! result loop <3 umschreiben!!
  // stacks.push_back(std::deque<std::string>{"Z", "N"});
  // stacks.push_back(std::deque<std::string>{"M", "C", "D"});
  // stacks.push_back(std::deque<std::string>{"P"});

  stacks.push_back(std::deque<std::string>{"F", "C", "J", "P", "H", "T", "W"});
  stacks.push_back(
      std::deque<std::string>{"G", "R", "V", "F", "Z", "J", "B", "H"});
  stacks.push_back(std::deque<std::string>{"H", "P", "T", "R"});
  stacks.push_back(std::deque<std::string>{"Z", "S", "N", "P", "H", "T"});
  stacks.push_back(
      std::deque<std::string>{"N", "V", "F", "Z", "H", "J", "C", "D"});
  stacks.push_back(std::deque<std::string>{"P", "M", "G", "F", "W", "D", "Z"});
  stacks.push_back(
      std::deque<std::string>{"M", "V", "Z", "W", "S", "J", "D", "P"});
  stacks.push_back(std::deque<std::string>{"N", "D", "S"});
  stacks.push_back(std::deque<std::string>{"D", "Z", "S", "F", "M"});

  int move{}, from{}, to{};
  std::fstream file;
  file.open("inputfiles/input_day5.test", std::ios::in);
  if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
      // std::cout << line << std::endl;
      if (line[0] == 'm') {

        to = static_cast<int>(line[size(line) - 1]) - 48 - 1;
        // -1 for length offset                 ^
        //   -48 for char conv (better use -'0')       ^
        // -1 for array offset                             ^
        from = static_cast<int>(line[size(line) - 6]) - 48 - 1;
        if (std::isdigit(line[6])) {
          move = static_cast<int>(line[6]) - 48 +
                 10 * (static_cast<int>(line[5]) - 48);
        } else {
          move = static_cast<int>(line[5]) - 48;
        }

        // std::cout << "   " << move << "\t" << from << "\t" << to << "\n\n";
        for (int i = 0; i < move; ++i) {
          // alternative, same result
          //   stacks[to].insert(stacks[to].end(), stacks[from].back());
          //   stacks[from].pop_back();

          std::string s = stacks[from].back();
          stacks[to].emplace_back(stacks[from].back());
          stacks[from].pop_back();
        }
      }
    }
  }
  std::string result{""};
  for (int i = 0; i < 9; ++i) {

    result += stacks[i].back();

    std::cout << stacks[i].back();
  }
  std::cout << "\n";
  std::cout << result;
}

// void day5_2() {}
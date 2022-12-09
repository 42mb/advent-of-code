#include <fstream>
#include <iostream>
#include <map>
#include <unordered_map>
struct position {

  int x = 1000;
  int y = 1000;

  void move(char dir) {
    if (dir == 'R') {
      x++;
    }
    if (dir == 'L') {
      x--;
    }
    if (dir == 'U') {
      y++;
    }
    if (dir == 'D') {
      y--;
    }
  }

} head, tail;

void follow(char travel_direction) {
  if (std::abs(head.x - tail.x) >= 2 || std::abs(head.y - tail.y) >= 2) {
    if (head.x != tail.x && head.y != tail.y) { // case diagonal
      if (travel_direction == 'L') {
        tail.x = head.x + 1;
        tail.y = head.y;
      }
      if (travel_direction == 'R') {
        tail.x = head.x - 1;
        tail.y = head.y;
      }
      if (travel_direction == 'U') {
        tail.y = head.y - 1;
        tail.x = head.x;
      }
      if (travel_direction == 'D') {
        tail.y = head.y + 1;
        tail.x = head.x;
      }
    } else {
      tail.move(travel_direction);
    }
  }
}

void day9_1() {
  std::unordered_map<std::string, int> past_visits;
  past_visits["10001000"]++;
  char travel_direction{};
  int travel_distance{};
  std::ifstream file("inputfiles/input_day9.prod");
  while (file >> travel_direction, file >> travel_distance) {
    // std::cout << travel_direction << " " << travel_distance << '\n';
    for (int i = 0; i < travel_distance; ++i) {
      head.move(travel_direction);
      follow(travel_direction);
      past_visits[std::to_string(tail.x) + std::to_string(tail.y)]++;
    }
  }

  std::cout << past_visits.size() << '\n';
}
// day9_2(){}
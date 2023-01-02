#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>

void day2_1() {
  std::ifstream file("input_day2.txt");
  std::string player1{};
  std::string player_enemy{};
  int score{};

  struct {
    const std::string rock = "X";
    const std::string paper = "Y";
    const std::string scissor = "Z";
  } player;

  struct {
    const std::string rock = "A";
    const std::string paper = "B";
    const std::string scissor = "C";
  } enemy;

  enum struct points {
    draw = 3,
    win = 6,
    lose = 0,
    forRock = 1,
    forPaper = 2,
    forScissor = 3
  };

  while (file >> player_enemy, file >> player1) {
    // std::cout << player_enemy << " " << player1 << "\n";

    if (player1 == player.rock) {
      score += static_cast<int>(points::forRock);
      if (player_enemy == enemy.rock) {
        score += static_cast<int>(points::draw);
      }
      if (player_enemy == enemy.paper) {
        score += static_cast<int>(points::lose);
      }
      if (player_enemy == enemy.scissor) {
        score += static_cast<int>(points::win);
      }
    }

    if (player1 == "Y") {
      score += 2;
      if (player_enemy == "A") {
        score += 6;
      }
      if (player_enemy == "B") {
        score += 3;
      }
      if (player_enemy == "C") {
        score += 0;
      }
    }

    if (player1 == "Z") {
      score += 3;
      if (player_enemy == "A") {
        score += 0;
      }
      if (player_enemy == "B") {
        score += 6;
      }
      if (player_enemy == "C") {
        score += 3;
      }
    }
  }
  std::cout << score;
}

void day2_2() {
  std::ifstream file("input_day2.txt");
  std::string player1{};
  std::string player_enemy{};
  int score{};

  std::string win = "Z";
  std::string draw = "Y";
  std::string lose = "X";
  std::string rock = "A";
  std::string paper = "B";
  std::string scissor = "C";

  enum struct score {
    win = 6,
    lose = 0,
    draw = 3

  };

  while (file >> player_enemy, file >> player1) {
    if (player1 == lose) {
      score += static_cast<int>(score::lose);
      if (player_enemy == rock) {
        score += 3;
      }
      if (player_enemy == paper) {
        score += 1;
      }
      if (player_enemy == scissor) {
        score += 2;
      }
    }
    if (player1 == draw) {
      score += static_cast<int>(score::draw);
      if (player_enemy == rock) {
        score += 1;
      }
      if (player_enemy == paper) {
        score += 2;
      }
      if (player_enemy == scissor) {
        score += 3;
      }
    }
    if (player1 == win) {
      score += static_cast<int>(score::win);
      if (player_enemy == rock) {
        score += 2;
      }
      if (player_enemy == paper) {
        score += 3;
      }
      if (player_enemy == scissor) {
        score += 1;
      }
    }
  }
  std::cout << score << "\n";
}

int main() {

  std::cout << "day1: " << '\n';
  day2_1();
  std::cout << "\n\n";
  std::cout << "day2: " << '\n';
  day2_2();
}
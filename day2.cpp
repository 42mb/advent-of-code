#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>

void day2_1() {
  std::ifstream file("inputfiles/input_day2.txt");
  std::string player1{};
  std::string player_enemy{};
  int score{};

  while (file >> player_enemy, file >> player1) {
    // std::cout << player_enemy << " " << player1 << "\n";

    if (player1 == "X") {
      score += 1;
      if (player_enemy == "A") {
        score += 3;
      }
      if (player_enemy == "B") {
        score += 0;
      }
      if (player_enemy == "C") {
        score += 6;
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

  while (file >> player_enemy, file >> player1) {
    if (player1 == lose) {
      score += 0;
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
      score += 3;
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
      score += 6;
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
  std::cout << "\n" << score << "\n";
}
#include <array>
#include <fstream>
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> matrix;

bool calc_visibilityd1(int col, int row, int max_height, int max_width,
                       matrix &d2vec) {

  int min_height{}, min_width{}, treehouse_height = d2vec[row][col];
  int largest_tree_leftside = -1, largest_tree_rightside = -1,
      largest_tree_upwards = -1, largest_tree_downwards = -1;

  for (int i = 0; i < col; ++i) {
    largest_tree_leftside = std::max(d2vec[row][i], largest_tree_leftside);
  }
  for (int i = col + 1; i < max_width; ++i) {
    largest_tree_rightside = std::max(d2vec[row][i], largest_tree_rightside);
  }
  for (int i = 0; i < row; ++i) {
    largest_tree_upwards = std::max(d2vec[i][col], largest_tree_upwards);
  }
  for (int i = row + 1; i < max_height; ++i) {
    largest_tree_downwards = std::max(d2vec[i][col], largest_tree_downwards);
  }

  // std::cout << largest_tree_leftside << "  " << largest_tree_rightside<< "  "
  //           << largest_tree_upwards << "  " << largest_tree_downwards << "  "
  //           << '\n';

  if (not(largest_tree_leftside >= treehouse_height &&
          largest_tree_rightside >= treehouse_height &&
          largest_tree_upwards >= treehouse_height &&
          largest_tree_downwards >= treehouse_height)) {
    // std::cout << "false" << '\n';
    return true;
  } else {
    // std::cout << "true" << '\n';
    return false;
  }
}

int day8_1() {
  //
  std::ifstream file("input_day8.prod");
  matrix d2vec;
  std::string line{};
  int are_visible{};
  int height{}, width{};

  while (file >> line) {
    width = line.size();
    std::vector<int> v;
    for (int i = 0; i < line.size(); ++i) {
      v.push_back(static_cast<int>(line[i]) - '0');
    }
    d2vec.push_back(v);

    ++height;
  }
  are_visible = 2 * height + 2 * width - 4;

  for (int row = 1; row < width - 1; ++row) {
    for (int col = 1; col < height - 1; ++col) {

      if (calc_visibilityd1(col, row, width, height, d2vec)) {
        are_visible++;
      }
    }
  }

  //   std::cout << "" << '\n';
  //   std::cout << "" << '\n';

  //   // output for debug
  //   for (std::vector<int> row : d2vec) {
  //     for (int val : row) {
  //       std::cout << val << " ";
  //     }
  //     std::cout << std::endl;
  //   }
  //   std::cout << "width: " << width << '\t' << "height: " << height << '\n';

  // std::cout << '\n' << "visible: " << '\n' << are_visible << '\n';
  std::cout << are_visible << '\n';
}

int calc_scenic_view(int col, int row, int max_height, int max_width,
                     matrix &d2vec) {

  int min_height{}, min_width{};
  int point_value = d2vec[row][col];
  int view_distance_leftside{1}, view_distance_rightside{1},
      view_distance_upwards{1}, view_distance_downwards{1};

  for (int i = col - 1; i > 0; --i) {
    if (d2vec[row][i] < point_value) {
      view_distance_leftside++;
    } else {
      break;
    }
  }
  for (int i = col + 1; i < max_width - 1; ++i) {
    if (d2vec[row][i] < point_value) {
      view_distance_rightside++;
    } else {
      break;
    }
  }
  for (int i = row - 1; i > 0; --i) {
    if (d2vec[i][col] < point_value) {
      view_distance_upwards++;
    } else {
      break;
    }
  }
  for (int i = row + 1; i < max_height - 1; ++i) {
    if (d2vec[i][col] < point_value) {
      view_distance_downwards++;
    } else {
      break;
    }
  }

  // std::cout << view_distance_leftside << "  " << view_distance_rightside << "
  // "<< view_distance_upwards << "  " << view_distance_downwards << "  " <<
  // '\n';

  return view_distance_downwards * view_distance_leftside *
         view_distance_rightside * view_distance_upwards;
}

int day8_2() {
  //
  int scenic_score = -1;
  std::ifstream file("input_day8.prod");
  matrix d2vec;
  std::string line{};
  int height{}, width{};
  // input into 2d vector
  while (file >> line) {
    width = line.size();
    std::vector<int> v;
    for (int i = 0; i < line.size(); ++i) {
      v.push_back(static_cast<int>(line[i]) - '0');
    }
    d2vec.push_back(v);

    ++height;
  }

  // calculation scenic score
  for (int row = 1; row < width - 1; ++row) {
    for (int col = 1; col < height - 1; ++col) {

      scenic_score = std::max(calc_scenic_view(col, row, width, height, d2vec),
                              scenic_score);
    }
  }

  // std::cout << "width: " << width << '\t' << "height: " << height << '\n';
  // std::cout << '\n' << "scenicscore: " << '\n' << scenic_score << '\n';
  std::cout << scenic_score << '\n';
}

int main() {

  std::cout << "day1: " << '\n';
  day8_1();
  std::cout << "\n";
  std::cout << "day2: " << '\n';
  day8_2();
}
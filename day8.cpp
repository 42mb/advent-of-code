#include <array>
#include <fstream>
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> matrix;

bool calc_visibilityd1(int col, int row, int max_height, int max_width,
                       matrix &d2vec) {

  int min_height{}, min_width{}, point_value = d2vec[row][col];
  int max_val_l = -1, max_val_r = -1, max_val_u = -1, max_val_d = -1;

  for (int i = 0; i < col; ++i) {
    max_val_l = std::max(d2vec[row][i], max_val_l);
  }
  for (int i = col + 1; i < max_width; ++i) {
    max_val_r = std::max(d2vec[row][i], max_val_r);
  }
  for (int i = 0; i < row; ++i) {
    max_val_u = std::max(d2vec[i][col], max_val_u);
  }
  for (int i = row + 1; i < max_height; ++i) {
    max_val_d = std::max(d2vec[i][col], max_val_d);
  }

  //   std::cout << max_val_l << "  " << max_val_r << "  " << max_val_u << "  "
  //             << max_val_d << "  " << '\n';

  if (max_val_l >= point_value && max_val_r >= point_value &&
      max_val_u >= point_value && max_val_d >= point_value) {
    // std::cout << "false" << '\n';
    return false;
  } else {
    // std::cout << "true" << '\n';
    return true;
  }
}

int day8_1() {
  //
  std::ifstream file("inputfiles/input_day8.prod");
  matrix d2vec;
  std::string line{};
  int are_visible{};
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
  std::cout << '\n' << "visible: " << '\n' << are_visible << '\n';
}

int calc_scenic_view(int col, int row, int max_height, int max_width,
                     matrix &d2vec) {

  int min_height{}, min_width{};
  int point_value = d2vec[row][col];
  int view_distance_l{1}, view_distance_r{1}, view_distance_u{1},
      view_distance_d{1};

  for (int i = col - 1; i > 0; --i) {
    if (d2vec[row][i] < point_value) {
      view_distance_l++;
    } else {
      break;
    }
  }
  for (int i = col + 1; i < max_width - 1; ++i) {
    if (d2vec[row][i] < point_value) {
      view_distance_r++;
    } else {
      break;
    }
  }
  for (int i = row - 1; i > 0; --i) {
    if (d2vec[i][col] < point_value) {
      view_distance_u++;
    } else {
      break;
    }
  }
  for (int i = row + 1; i < max_height - 1; ++i) {

    if (d2vec[i][col] < point_value) {
      view_distance_d++;
    } else {
      break;
    }
  }

  // std::cout << view_distance_l << "  " << view_distance_r << "  "<<
  // view_distance_u << "  " << view_distance_d << "  " << '\n';

  return view_distance_d * view_distance_l * view_distance_r * view_distance_u;
}

int day8_2() {
  //
  int scenic_score = -1;
  std::ifstream file("inputfiles/input_day8.prod");
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

  // calculation
  for (int row = 1; row < width - 1; ++row) {
    for (int col = 1; col < height - 1; ++col) {

      scenic_score = std::max(calc_scenic_view(col, row, width, height, d2vec),
                              scenic_score);
    }
  }

  std::cout << "width: " << width << '\t' << "height: " << height << '\n';
  std::cout << '\n' << "scenicscore: " << '\n' << scenic_score << '\n';
}
#include <deque>
#include <iostream>
#include <vector>

std::vector<int> GetTheMinOnVector(std::vector<int>& summ, int length,
                                   int size) {
  std::vector<int> res(0);
  std::deque<int> help_deque;
  for (int tmp = 0; tmp < size; ++tmp) {
    if (tmp >= length && help_deque.front() == tmp - length) {
      help_deque.pop_front();
    }
    while (!help_deque.empty() && summ[help_deque.back()] >= summ[tmp]) {
      help_deque.pop_back();
    }
    help_deque.push_back(tmp);
    if (tmp >= length - 1) {
      res.push_back(summ[help_deque.front()]);
    }
  }
  return res;
}

std::vector<std::vector<int>> GetMinOnPlane(std::vector<std::vector<int>> matrix, int hight, int width, int length, int clength) {
  std::cin >> hight >> width  >> length >> clength;
  std::vector<int> column(hight, 0);
  std::vector<std::vector<int>> matrix(width, column);
  for (int tmpx = 0; tmpx < hight; ++tmpx) {
    for (int tmpy = 0; tmpy < width; ++tmpy) {
      std::cin >> matrix[tmpy][tmpx];
    }
  }
  std::vector<int> elementary_string(1, 0);
  std::vector<std::vector<int>> min_in_columns(width, elementary_string);
  for (int tmp = 0; tmp < width; ++tmp) {
    min_in_columns[tmp] = GetTheMinOnVector(matrix[tmp], clength, hight);
  }
  for (int tmp = 0; tmp < hight - clength + 1; ++tmp) {
    std::vector<int> help_vec(width, 0);
    for (int tmpx = 0; tmpx < width; ++tmpx) {
      help_vec[tmpx] = min_in_columns[tmpx][tmp];
    }
    auto ans = GetTheMinOnVector(help_vec, length, width);
    for (auto elem : ans) {
      std::cout << elem << " ";
    }
    std::cout << '\n';
  }
}

int main() {
  int size = 0;
  int length = 0;
  int hight = 0;
  int width = 0;
  int clength = 0;
  std::cin >> hight >> width  >> length >> clength;
  size = hight;
  std::vector<int> column(hight, 0);
  std::vector<std::vector<int>> matrix(width, column);
  for (int tmpx = 0; tmpx < hight; ++tmpx) {
    for (int tmpy = 0; tmpy < width; ++tmpy) {
      std::cin >> matrix[tmpy][tmpx];
    }
  }
  std::vector<int> elementary_string(1, 0);
  std::vector<std::vector<int>> min_in_columns(width, elementary_string);
  for (int tmp = 0; tmp < width; ++tmp) {
    min_in_columns[tmp] = GetTheMinOnVector(matrix[tmp], clength, hight);
  }
  for (int tmp = 0; tmp < hight - clength + 1; ++tmp) {
    std::vector<int> help_vec(width, 0);
    for (int tmpx = 0; tmpx < width; ++tmpx) {
      help_vec[tmpx] = min_in_columns[tmpx][tmp];
    }
    auto ans = GetTheMinOnVector(help_vec, length, width);
    for (auto elem : ans) {
      std::cout << elem << " ";
    }
    std::cout << '\n';
  }
}



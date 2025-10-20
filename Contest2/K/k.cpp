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

int main() {
  int size = 0;
  int length = 0;
  std::cin >> size >> length;
  std::vector<int> column(size, 0);
  std::vector<std::vector<int>> matrix(size, column);
  std::vector<std::vector<int>> reversed_matrix(size, column);
  for (int tmpx = 0; tmpx < size; ++tmpx) {
    for (int tmpy = 0; tmpy < size; ++tmpy) {
      std::cin >> matrix[tmpy][tmpx];
      reversed_matrix[tmpx][tmpy] = matrix[tmpy][tmpx];
    }
  }
  std::vector<int> elementary_string(1, 0);
  std::vector<std::vector<int>> min_in_columns(size, elementary_string);
  std::vector<std::vector<int>> min_in_strings(size, elementary_string);
  for (int tmp = 0; tmp < size; ++tmp) {
    min_in_columns[tmp] = GetTheMinOnVector(matrix[tmp], length, size);
    min_in_strings[tmp] = GetTheMinOnVector(reversed_matrix[tmp], length, size);
  }
  for (int tmp = 0; tmp < size - length + 1; ++tmp) {
    std::vector<int> help_vec(size, 0);
    for (int tmpx = 0; tmpx < size; ++tmpx) {
      help_vec[tmpx] = min_in_columns[tmpx][tmp];
    }
    auto ans = GetTheMinOnVector(help_vec, length, size);
    for (auto elem : ans) {
      std::cout << elem << " ";
    }
    std::cout << '\n';
  }
}

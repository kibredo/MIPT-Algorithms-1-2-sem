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

std::vector<std::vector<int>> GetMinOnPlane(std::vector<std::vector<int>> matrix, int hight, int width, int length, int hlength) {
  std::vector<std::vector<int>> the_ans(hight - hlength + 1);
  std::vector<int> elementary_string(1, 0);
  std::vector<std::vector<int>> min_in_columns(width, elementary_string);
  for (int tmp = 0; tmp < width; ++tmp) {
    min_in_columns[tmp] = GetTheMinOnVector(matrix[tmp], hlength, hight);
  }
  for (int tmp = 0; tmp < hight - hlength + 1; ++tmp) {
    std::vector<int> help_vec(width, 0);
    for (int tmpx = 0; tmpx < width; ++tmpx) {
      help_vec[tmpx] = min_in_columns[tmpx][tmp];
    }
    auto ans = GetTheMinOnVector(help_vec, length, width);
    for (auto elem : ans) {
      std::cout << elem << " ";
    }
    the_ans[tmp] = ans;
    std::cout << '\n';
  }
  return the_ans;
}
int main() {
  int the_x = 0;
  int the_y = 0;
  int the_z = 0;
  std::cin >> the_x >> the_y >> the_z;
  int width = 0;
  int hight = 0;
  int len = 0;
  std::cin >> len >> width >> hight;
  std::vector<int> one_string(the_y, 0);
  std::vector<std::vector<int>> one_plane(the_z, one_string);
  std::vector<std::vector<std::vector<int>>> space(the_x, one_plane);
  for (int tmpx = 0; tmpx < the_x; ++tmpx) {
    for (int tmpy = 0; tmpy < the_y; ++tmpy) {
      for (int tmpz = 0; tmpz < the_z; ++tmpz) {
        std::cin >> space[tmpx][tmpz][tmpy];
      }
    }
  }
  std::vector<std::vector<std::vector<int>>> extra_space(the_x);
  for (int tmp = 0; tmp < the_x; ++tmp) {
    extra_space[tmp] = GetMinOnPlane(space[tmp], the_y, the_z, width, hight);
  }
  int test = 0;
  test = 1;
}


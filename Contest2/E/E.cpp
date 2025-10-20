#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> GetMerge(
    std::vector<std::pair<int, int>> left_part,
    std::vector<std::pair<int, int>> right_part) {
  std::vector<std::pair<int, int>> ans;
  int left_index = 0;
  int right_index = 0;
  while (left_index < (int)left_part.size() &&
         right_index < (int)right_part.size()) {
    if (left_part[left_index] <= right_part[right_index]) {
      ans.push_back(left_part[left_index++]);
    } else {
      ans.push_back(right_part[right_index++]);
    }
  }
  while (left_index < (int)left_part.size()) {
    ans.push_back(left_part[left_index]);
    ++left_index;
  }
  while (right_index < (int)right_part.size()) {
    ans.push_back(right_part[right_index]);
    ++right_index;
  }
  return ans;
}

std::vector<std::pair<int, int>> MergeSort(
    std::vector<std::pair<int, int>> vec) {
  if (vec.size() <= 1) {
    return vec;
  }
  std::vector<std::pair<int, int>> left;
  std::vector<std::pair<int, int>> right;
  int midpoit = vec.size() / 2;
  for (int tmp = 0; tmp < midpoit; tmp++) {
    left.push_back(vec[tmp]);
  }
  for (int tmp = midpoit; tmp < (int)vec.size(); tmp++) {
    right.push_back(vec[tmp]);
  }
  return GetMerge(MergeSort(left), MergeSort(right));
}

int main() {
  int num = 0;
  std::cin >> num;
  std::vector<std::pair<int, int>> vec(num);
  int tmp = 0;
  while (tmp < num) {
    std::cin >> vec[tmp].first;
    vec[tmp].second = tmp;
    ++tmp;
  }
  std::vector<std::pair<int, int>> ans = MergeSort(vec);
  vec.resize(0);
  std::vector<int> output(num, 0);
  for (int tmp = 0; tmp < num; ++tmp) {
    output[ans[tmp].second] = tmp;
  }
  for (auto elem : output) {
    std::cout << elem << " ";
  }
}

#include <iostream>
#include <vector>
std::vector<int> GetMerge(std::vector<int> left_part,
                          std::vector<int> right_part, int& inv_count) {
  std::vector<int> ans;
  int left_index = 0;
  int right_index = 0;
  while (left_index < (int)left_part.size() &&
         right_index < (int)right_part.size()) {
    if (left_part[left_index] <= right_part[right_index]) {
      ans.push_back(left_part[left_index++]);
    } else {
      ans.push_back(right_part[right_index++]);
      inv_count += (left_part.size() - left_index);
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
std::vector<int> MergeSort(std::vector<int> vec, int& inv_count) {
  if (vec.size() <= 1) {
    return vec;
  }
  std::vector<int> left;
  std::vector<int> right;
  int midpoit = vec.size() / 2;
  for (int tmp = 0; tmp < midpoit; tmp++) {
    left.push_back(vec[tmp]);
  }
  for (int tmp = midpoit; tmp < (int)vec.size(); tmp++) {
    right.push_back(vec[tmp]);
  }
  return GetMerge(MergeSort(left, inv_count), MergeSort(right, inv_count),
                  inv_count);
}
int main() {
  int num = 0;
  std::cin >> num;
  std::vector<int> vec(num, 0);
  int inv_count = 0;
  int tmp = 0;
  while (tmp < num) {
    std::cin >> vec[tmp];
    ++tmp;
  }
  std::vector<int> ans = MergeSort(vec, inv_count);
  std::cout << inv_count;
}

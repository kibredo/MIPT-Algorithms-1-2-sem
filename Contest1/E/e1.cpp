#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
int main() {
  int num = 0;
  std::cin >> num;
  std::vector<int> vec(0);
  std::vector<int> rhs(0);
  std::vector<int> lhs(0);
  std::set<int> sett;
  int temp = 0;
  int left = 0;
  int right = 0;
  for (int tmp = 0; tmp < num; ++tmp) {
    std::cin >> left >> right;
    lhs.push_back(left);
    rhs.push_back(right);
    sett.insert(left);
    sett.insert(right);
  }
  std::sort(lhs.begin(), lhs.end());
  std::sort(rhs.begin(), rhs.end());
  lhs.push_back(-1);
  rhs.push_back(-1);
  int rindex = 0;
  int lindex = 0;
  int beg = 0;
  int end = 0;
  bool wasend = false;
  std::vector<std::pair<int, int>> ans;
  for (auto elem : sett) {
    if (lhs[lindex] == elem && elem != rhs[rindex]) {
      if (temp == 0) {
        beg = elem;
      }
      while (lhs[lindex] == elem) {
        ++lindex;
        ++temp;
      }
    }
    if (lhs[lindex] != elem && elem == rhs[rindex]) {
      while (rhs[rindex] == elem) {
        if (temp == 1) {
          end = elem;
          wasend = true;
        }
        ++rindex;
        --temp;
      }
    }
    if (lhs[lindex] == elem && rhs[rindex] == elem) {
      while (lhs[lindex] == elem) {
        ++lindex;
        ++temp;
      }
      while (rhs[rindex] == elem) {
        if (temp == 1) {
          end = elem;
          wasend = true;
        }
        ++rindex;
        --temp;
      }
    }
    if (wasend) {
      wasend = false;
      ans.push_back(std::make_pair(beg, end));
    }
  }
  for (auto elem : ans) {
    std::cout << elem.first << " " << elem.second << std::endl;
  }
  return 0;
}

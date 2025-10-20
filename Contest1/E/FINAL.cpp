#include <iostream>
#include <set>
#include <vector>
int main() {
  int num = 0;
  std::cin >> num;
  std::vector<int> vec(0);
  std::multiset<int> rhs;
  std::multiset<int> lhs;
  std::set<int> sett;
  int temp = 0;
  int left = 0;
  int right = 0;
  for (int tmp = 0; tmp < num; ++tmp) {
    std::cin >> left >> right;
    sett.insert(left);
    sett.insert(right);
    rhs.insert(right);
    lhs.insert(left);
  }
  lhs.insert(*sett.rbegin() + 1);
  auto rindex = rhs.begin();
  rhs.insert(*sett.rbegin() + 1);
  auto lindex = lhs.begin();
  int beg = 0;
  int end = 0;
  bool wasend = false;
  std::vector<std::pair<int, int>> ans;
  int kans = 0;
  for (auto elem : sett) {
    while (*lindex == elem) {
      if (temp == 0) {
        beg = elem;
      }
      ++lindex;
      ++temp;
    }
    while (elem == *rindex) {
      if (temp == 1) {
        end = elem;
        wasend = true;
      }
      ++rindex;
      --temp;
    }
    if (wasend) {
      wasend = false;
      ans.push_back(std::make_pair(beg, end));
      ++kans;
    }
  }
  std::cout << kans << std::endl;
  for (auto elem : ans) {
    std::cout << elem.first << " " << elem.second << std::endl;
  }
  return 0;
}

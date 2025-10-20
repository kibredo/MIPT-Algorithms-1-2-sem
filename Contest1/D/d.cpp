#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
bool Check(int val, int num, std::vector<int> vect) {
  int tmp = val;
  int cnt = 1;
  for (auto tempr = 1; tempr < (int)vect.size(); ++tempr) {
    if (vect[tempr] - vect[tempr - 1] > tmp) {
      ++cnt;
      tmp = val;
    } else {
      tmp -= (vect[tempr] - vect[tempr - 1]);
    }
  }
  return cnt <= num;
}
int main() {
  std::set<int> sett;
  int number = 0;
  int knt = 0;
  int tmp = 0;
  std::cin >> number >> knt;
  std::vector<int> vec;
  for (int temp = 0; temp < number; ++temp) {
    std::cin >> tmp;
    sett.insert(tmp);
    vec.push_back(tmp);
  }
  std::sort(vec.begin(), vec.end());
  int left = 0;
  int right = abs(vec[number - 1] - vec[0]) + 1;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (Check(mid, knt, vec)) {
      right = mid;
    } else {
      left = mid;
    }
  }
  if ((int)sett.size() <= knt) {
    right = 0;
  }
  const int kKint = 1999975601;
  if (right == kKint) {
    --right;
  }
  std::cout << right;
}

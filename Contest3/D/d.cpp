#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
  std::vector<std::pair<int, int>> vec;
  int first = 0;
  int second = 0;
  int size = 0;
  std::cin >> size;
  std::set<int> magic;
  for (int tmp = 0; tmp < size; ++tmp) {
    std::cin >> first >> second;
    magic.insert(first);
    vec.push_back({first, second});
  }
  std::sort(vec.begin(), vec.end());
  int iter = 0;
  int another_iter = 0;
  int reminder = 0;
  for (auto elem : magic) {
    while (vec[iter].second == elem) {
      
    }
    while (vec[iter].first == elem) {

    }
  }
}

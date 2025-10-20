#include <iostream>
#include <set>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::multiset<int> help_vec;
  std::vector<int> vec;
  int quant = 0;
  std::cin >> quant;
  int tmp = 0;
  for (int ktmp = 0; ktmp < quant; ++ktmp) {
    std::cin >> tmp;
    vec.push_back(tmp);
    help_vec.insert(tmp);
  }
  for (int tmp = 0; tmp < quant; ++tmp) {
    auto iter = help_vec.find(vec[tmp]);
    std::cout << (int)help_vec.size() - std::distance(iter, help_vec.end()) << " ";
    help_vec.erase(iter);
  }
}
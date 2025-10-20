#include <cmath>
#include <iostream>
#include <set>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  unsigned long long num;
  unsigned long long ansn;
  std::cin >> num;
  std::cin >> ansn;
  unsigned long long elem;
  unsigned long long first;
  unsigned long long second;
  std::cin >> elem;
  std::cin >> first;
  std::cin >> second;
  std::multiset<unsigned long long> ans;
  unsigned long long var = elem;
  const unsigned long long kModulo = std::pow(2, 30);
  for (int tmp = 0; tmp < num; ++tmp) {
    var = first * var + second;
    var %= kModulo;
    ans.insert(var);
    if ((int)ans.size() > ansn) {
      auto iter = ans.end();
      --iter;
      ans.erase(iter);
    }
  }
  for (auto elem : ans) {
    std::cout << elem << " ";
  }
  return 0;
}

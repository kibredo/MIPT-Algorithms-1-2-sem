#include <iostream>
#include <unordered_map>
#include <vector>
const int kMod = 1'000'000'000 + 7;

void DoTheThing(const std::vector<int>& vec) {
  int size = vec.size();
  std::vector<long long> the_dp(size + 1, 0);
  the_dp[0] = 1;
  std::unordered_map<long long, long long> last;
  for (int tmp = 1; tmp <= size; ++tmp) {
    the_dp[tmp] = 2 * the_dp[tmp - 1];
    the_dp[tmp] %= kMod;
    auto iter = last.find(vec[tmp - 1]);
    if (iter != last.end()) {
      long long ind = iter->second;
      the_dp[tmp] -= the_dp[ind - 1];
      the_dp[tmp] %= kMod;
    }
    last[vec[tmp - 1]] = tmp;
    the_dp[tmp] %= kMod;
  }
  the_dp[size] %= kMod;
  if (the_dp[size] <= 0) {
    std::cout << the_dp[size] + kMod - 1;
    return;
  }
  std::cout << the_dp[size] - 1;
}

int main() {
  int size = 0;
  std::cin >> size;
  std::vector<int> vec(size, 0);
  for (int tmp = 0; tmp < size; ++tmp) {
    std::cin >> vec[tmp];
  }
  DoTheThing(vec);
}

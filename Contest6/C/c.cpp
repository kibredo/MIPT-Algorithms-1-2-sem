#include <iostream>
#include <vector>

int main() {
  long long the_n = 0;
  long long the_k = 0;
  std::cin >> the_n >> the_k;
  if (the_n == 1) {
    std::cout << 0;
  } else if (the_k == 0) {
    std::cout << -1;
  } else {
    std::vector<std::vector<long long>> dp(
        2, std::vector<long long>(the_k + 1, 0));
    long long summ = 2;
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[1][0] = 1;
    long long ans = 1;
    while (summ < the_n) {
      summ = 1;
      for (int tmp = 1; tmp <= the_k; ++tmp) {
        dp[ans % 2][tmp] = dp[(ans + 1) % 2][tmp - 1] + dp[(ans + 1) % 2][tmp];
        summ += dp[ans % 2][tmp];
      }
      ++ans;
    }
    std::cout << ans;
  }
}
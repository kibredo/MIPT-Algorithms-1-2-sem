#include <iostream>
#include <vector>

int main() {
  int the_n = 0;
  std::cin >> the_n;
  std::vector<std::vector<int>> dp(the_n + 1, std::vector<int>(the_n + 1, 0));
  for (int the_i = 1; the_i <= the_n; ++the_i) {
    dp[the_i][the_i] = 1;
  }
  for (int the_i = 1; the_i <= the_n; ++the_i) {
    for (int the_j = 1; the_j <= the_i; ++the_j) {
      int the_k = 1;
      while (the_k <= the_j / 2) {
        dp[the_i][the_j] += dp[the_i - the_j][the_k];
        ++the_k;
      }
    }
  }
  long long ans = 0;
  for (int the_i = 1; the_i <= the_n; ++the_i) {
    ans += dp[the_n][the_i];
  }
  std::cout << ans;
}
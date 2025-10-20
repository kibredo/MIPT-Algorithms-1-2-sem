#include <iostream>
#include <stack>
#include <vector>
const long long kMaxLog = 77;

void DoTheThing(long long size, std::vector<std::vector<long long>>& the_y,
                std::vector<long long>& city) {
  for (long long tmp = 1; tmp <= size; ++tmp) {
    std::cin >> city[tmp];
    city[tmp + size] = city[tmp];
  }
  for (long long itmp = 1; itmp <= 2 * size; ++itmp) {
    for (long long jtmp = std::max(itmp - size + 1, (long long)1); jtmp < itmp;
         ++jtmp) {
      if (city[itmp] % city[jtmp] == 0) {
        the_y[itmp].push_back(jtmp);
      }
    }
  }
}

int main() {
  std::stack<long long> ans;
  long long max_len = 0;
  long long max_ind = 1;
  long long size = 0;
  std::cin >> size;
  std::vector<long long> city(2 * size + 2, 0);
  std::vector<std::vector<long long>> the_y(2 * size + 1);
  DoTheThing(size, the_y, city);
  std::vector<std::vector<long long>> dp(
      kMaxLog, std::vector<long long>(2 * size + 1, 0));
  for (long long itmp = 1; itmp <= size; ++itmp) {
    dp[1][itmp] = itmp;
  }
  for (long long itmp = 1; itmp <= 2 * size; ++itmp) {
    for (long long len = 2; len < kMaxLog; ++len) {
      for (auto y : the_y[itmp]) {
        if (dp[len - 1][y] >= itmp - size + 1) {
          dp[len][itmp] = std::max(dp[len][itmp], dp[len - 1][y]);
        }
      }
      if (dp[len][itmp] > 0 && len >= max_len) {
        max_len = len;
        max_ind = itmp;
      }
    }
  }
  std::cout << std::max(max_len, (long long)1) << std::endl;
  while (max_len > 1) {
    bool check = true;
    for (long long y : the_y[max_ind]) {
      if (check && dp[max_len - 1][y] == dp[max_len][max_ind]) {
        ans.push(max_ind);
        max_ind = y;
        --max_len;
        check = false;
      }
    }
  }
  std::cout << max_ind << " ";
  while (!ans.empty()) {
    std::cout << (ans.top() == size ? size : ans.top() % size) << " ";
    ans.pop();
  }
}

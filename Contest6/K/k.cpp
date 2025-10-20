#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> DoTheThing(int total_weight,
                                         const std::vector<int>& wt,
                                         const std::vector<int>& val,
                                         int total_size) {
  std::vector<std::vector<int>> the_dp(total_size + 1,
                                       std::vector<int>(total_weight + 1));
  for (int tmp = 0; tmp <= total_size; tmp++) {
    for (int temp_weight = 0; temp_weight <= total_weight; temp_weight++) {
      if (tmp == 0 || temp_weight == 0) {
        the_dp[tmp][temp_weight] = 0;
      } else if (wt[tmp - 1] <= temp_weight) {
        the_dp[tmp][temp_weight] =
            std::max(val[tmp - 1] + the_dp[tmp - 1][temp_weight - wt[tmp - 1]],
                     the_dp[tmp - 1][temp_weight]);
      } else {
        the_dp[tmp][temp_weight] = the_dp[tmp - 1][temp_weight];
      }
    }
  }
  return the_dp;
}

int main() {
  int total_weight = 0;
  int total_size = 0;
  std::cin >> total_size;
  std::cin >> total_weight;
  std::vector<int> val(total_size);
  std::vector<int> wt(total_size);
  for (int tmp = 0; tmp < total_size; ++tmp) {
    std::cin >> wt[tmp];
  }
  for (int tmp = 0; tmp < total_size; ++tmp) {
    std::cin >> val[tmp];
  }
  std::vector<int> final_ans(0);
  auto ans = DoTheThing(total_weight, wt, val, total_size);
  for (int tmp = total_size; tmp > 0; --tmp) {
    if (ans[tmp][total_weight] != ans[tmp - 1][total_weight]) {
      final_ans.push_back(tmp);
      total_weight -= wt[tmp - 1];
    }
  }
  std::reverse(final_ans.begin(), final_ans.end());
  for (auto element : final_ans) {
    std::cout << element << " ";
  }
}

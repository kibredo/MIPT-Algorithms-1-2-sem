#include <iostream>
#include <stack>
#include <vector>

int DoTheThing(const std::vector<int>& vec, int value) {
  int left_one = 0;
  int right_one = (int)vec.size() - 1;
  while (right_one - left_one > 1) {
    int mid = (right_one + left_one) / 2;
    if (vec[mid] > value) {
      right_one = mid;
    } else {
      left_one = mid;
    }
  }
  if (value >= vec[vec.size() - 1]) {
    return right_one;
  }
  return left_one;
}

int main() {
  int size = 0;
  const int kPow = 2147483647;
  std::cin >> size;
  std::vector<int> vec(size, 0);
  for (int tmp = 0; tmp < size; ++tmp) {
    std::cin >> vec[tmp];
    vec[tmp] *= -1;
  }
  std::vector<int> dp(size + 1, kPow);
  std::vector<int> val_dp(size + 1, kPow);
  dp[0] = -1;
  val_dp[0] = -1 * kPow;
  int current_pos = 0;
  std::vector<int> ind(size + 1, -1);
  for (int tmp = 0; tmp < size; ++tmp) {
    current_pos = DoTheThing(val_dp, vec[tmp]);
    dp[current_pos + 1] = tmp;
    val_dp[current_pos + 1] = vec[tmp];
    ind[tmp] = dp[current_pos];
  }
  int ans = 0;
  for (int tmp = 1; tmp <= size; ++tmp) {
    if (val_dp[tmp] != kPow) {
      ++ans;
    }
  }
  std::cout << ans << std::endl;
  auto curr = dp[ans];
  std::stack<int> stack_overflow;
  while (ind[curr] >= 0) {
    stack_overflow.push(curr + 1);
    curr = ind[curr];
  }
  stack_overflow.push(curr + 1);
  while (!stack_overflow.empty()) {
    std::cout << stack_overflow.top() << std::endl;
    stack_overflow.pop();
  }
}

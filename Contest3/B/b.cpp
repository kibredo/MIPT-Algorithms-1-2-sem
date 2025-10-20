#include <cmath>
#include <iostream>
#include <vector>

void Update(std::vector<long long>& vec, long long vertex, std::pair<long long, long long> border, long long pos, long long value) {
  long long left_end = border.first;
  long long right_end = border.second;
  if (left_end == right_end) {
    vec[vertex] = value * vec[vertex] / std::abs(vec[vertex]);
    return;
  }
  long long mid_end = (left_end + right_end) / 2;
  if (pos <= mid_end) {
    Update(vec, 2 * vertex, {left_end, mid_end}, pos, value);
  } else {
    Update(vec, 2 * vertex + 1, {mid_end + 1, right_end}, pos, value);
  }
  vec[vertex] = vec[2 * vertex] + vec[2 * vertex + 1];
}

long long GetSum(std::vector<long long>& vec, long long vertex, long long left_end, long long right_end, std::pair<long long, long long> border) {
  long long left = border.first;
  long long right = border.second;
  if (left_end == left && right_end == right) {
    return vec[vertex];
  }
  long long ans = 0;
  long long mid_end = (left_end + right_end) / 2;
  if (left <= mid_end) {
    ans += GetSum(vec, 2 * vertex, left_end, mid_end,
                  {left, std::min(right, mid_end)});
  }
  if (right > mid_end) {
    ans += GetSum(vec, 2 * vertex + 1, mid_end + 1, right_end,
                  {std::max(left, mid_end + 1), right});
  }
  return ans;
}
void ConstructStUtil(std::vector<long long>& tree, const std::vector<long long>& arr, long long& size) {
  for (long long tmp = 0; tmp < (long long)arr.size(); ++tmp) {
    tree[tmp + size] = pow(-1, tmp) * arr[tmp];
  }
}
void ExtraBuilder(std::vector<long long>& tree, long long& cnt) {
  for (long long tmp = cnt; tmp < 2 * cnt; ++tmp) {
    tree[tmp] = tree[2 * tmp] + tree[2 * tmp + 1];
  }
  cnt /= 2;
  if (cnt == 0) {
    return;
  }
  ExtraBuilder(tree, cnt);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  long long size = 0;
  std::cin >> size;
  std::vector<long long> arr(size, 0);
  long long cnt = 1;
  while (cnt < size) {
    cnt *= 2;
  }
  long long cntsize = cnt;
  std::vector<long long> tree(2 * cnt, 0);
  for (long long tmp = 0; tmp < size; ++tmp) {
    std::cin >> arr[tmp];
  }
  ConstructStUtil(tree, arr, cnt);
  cnt /= 2;
  ExtraBuilder(tree, cnt);
  long long quant = 0;
  long long chk = 0;
  std::cin >> quant;
  for (long long tmp = 0; tmp < quant; ++tmp) {
    std::cin >> chk;
    if (chk == 0) {
      long long index = 0;
      long long val = 0;
      std::cin >> index >> val;
      Update(tree, 1, {0, cntsize - 1}, index - 1, val);
    } else {
      long long left = 0;
      long long right = 0;
      std::cin >> left >> right;
      long long one = pow(-1, left + 1);
      std::cout << GetSum(tree, 1, 0, cntsize - 1, {left - 1, right - 1}) * one << std::endl;
    }
  }
}
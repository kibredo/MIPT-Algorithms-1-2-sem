#include <cmath>
#include <iostream>
#include <vector>

void Update(std::vector<int>& vec, int vertex, std::pair<int, int> border, int pos, int value) {
  int left_end = border.first;
  int right_end = border.second;
  if (left_end == right_end) {
    vec[vertex] = value * vec[vertex];
    return;
  }
  int mid_end = (left_end + right_end) / 2;
  if (pos <= mid_end) {
    Update(vec, 2 * vertex, {left_end, mid_end}, pos, value);
  } else {
    Update(vec, 2 * vertex + 1, {mid_end + 1, right_end}, pos, value);
  }
  vec[vertex] = std::min(vec[2 * vertex], vec[2 * vertex + 1]);
}

int GetMin(std::vector<int>& vec, int vertex, int left_end, int right_end, std::pair<int, int> border) {
  int left = border.first;
  int right = border.second;
  if (left_end == left && right_end == right) {
    return vec[vertex];
  }
  int ans = 0;
  int mid_end = (left_end + right_end) / 2;
  if (left <= mid_end) {
    ans = GetMin(vec, 2 * vertex, left_end, mid_end, {left, std::min(right, mid_end)});
  }
  if (right > mid_end) {
    ans = GetMin(vec, 2 * vertex + 1, mid_end + 1, right_end, {std::max(left, mid_end + 1), right});
  }
  return ans;
}
void ConstructStUtil(std::vector<int>& tree, const std::vector<int>& arr, int& size) {
  for (int tmp = 0; tmp < (int)arr.size(); ++tmp) {
    tree[tmp + size] = arr[tmp];
  }
}
void ExtraBuilder(std::vector<int>& tree, int& cnt) {
  for (int tmp = cnt; tmp < 2 * cnt; ++tmp) {
    tree[tmp] = std::min(tree[2 * tmp], tree[2 * tmp + 1]);
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
  int size = 0;
  std::cin >> size;
  std::vector<int> arr(size, 0);
  int cnt = 1;
  while (cnt < size) {
    cnt *= 2;
  }
  int cntsize = cnt;
  std::vector<int> tree(2 * cnt, 2e9);
  for (int tmp = 0; tmp < size; ++tmp) {
    std::cin >> arr[tmp];
  }
  ConstructStUtil(tree, arr, cnt);
  cnt /= 2;
  ExtraBuilder(tree, cnt);
  int quant = 0;
  int chk = 0;
  std::cin >> quant;
  for (int tmp = 0; tmp < quant; ++tmp) {
    int left = 0;
    int right = 0;
    std::cin >> left >> right;
    std::cout << GetMin(tree, 1, 0, cntsize - 1, {left - 1, right - 1}) << std::endl;
  }
}

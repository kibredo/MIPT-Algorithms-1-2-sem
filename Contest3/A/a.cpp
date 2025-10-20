#include <cmath>
#include <iostream>
#include <string>
#include <vector>

const long long kMAX = 1'000'000'000;

struct DynamicTree {
  long long tl;
  long long tr;
  long long sum = 0;
  long long cap = 0;
  DynamicTree* leftone = nullptr;
  DynamicTree* rightone = nullptr;
  DynamicTree() = default;
  DynamicTree(long long left, long long right) : tl(left), tr(right) {}
  void GetNewSpace() {
    if (leftone == nullptr && tl + 1 < tr) {
      long long tm = (tl + tr) / 2;
      leftone = new DynamicTree(tl, tm);
      rightone = new DynamicTree(tm, tr);
    }
  }
  void GetSummedUp(long long pos, long long val) {
    GetNewSpace();
    sum += val;
    if (leftone != nullptr) {
      if (pos < leftone->tr) {
        leftone->GetSummedUp(pos, val);
      } else {
        rightone->GetSummedUp(pos, val);
      }
    }
  }
  long long GetSum(long long left, long long right) {
    if (tl >= left && tr <= right) {
      return sum;
    }
    if (std::max(tl, left) >= std::min(tr, right)) {
      return 0;
    }
    GetNewSpace();
    return leftone->GetSum(left, right) + rightone->GetSum(left, right);
  }
  ~DynamicTree() {
    delete leftone;
    delete rightone;
  }
};
int main() {
  long long total_tests;
  std::cin >> total_tests;
  DynamicTree tree(0, kMAX);
  long long cap = 1;
  while (cap < total_tests) {
    cap *= 2;
  }
  tree.cap = cap;
  for (int tmp = 0; tmp < total_tests; ++tmp) {
    std::string input;
    std::cin >> input;
    if (input == "?") {
      long long user;
      std::cin >> user;
      std::cout << tree.GetSum(0, user + 1);
      std::cout << std::endl;
    } else {
      long long innnn;
      std::cin >> innnn;
      tree.GetSummedUp(innnn, innnn);
    }
  }
}

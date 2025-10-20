#include <iostream>
#include <vector>
const long long kMod = 1'000'000'009;

struct Triple {
  long long the_x;
  long long the_y;
  long long the_k;
  Triple(long long first, long long second, long third)
      : the_x(first), the_y(second), the_k(third) {}
};

std::vector<std::vector<long long>> GetM(
    const std::vector<std::vector<long long>>& the_a,
    const std::vector<std::vector<long long>>& the_b) {
  std::vector<std::vector<long long>> the_ans(2, std::vector<long long>(2));
  for (int tmp = 0; tmp < 2; tmp++) {
    for (int xtmp = 0; xtmp < 2; xtmp++) {
      the_ans[tmp][xtmp] = ((the_a[tmp][0] * the_b[0][xtmp]) +
                            (the_a[tmp][1] * the_b[1][xtmp])) %
                           kMod;
    }
  }
  return the_ans;
}
std::vector<std::vector<long long>> GetPowered(
    std::vector<std::vector<long long>> base, long long exponent) {
  std::vector<std::vector<long long>> the_ans = {{1, 1}, {0, 1}};
  while (exponent > 0) {
    if (exponent % 2 == 1) {
      the_ans = GetM(the_ans, base);
    }
    base = GetM(base, base);
    exponent /= 2;
  }
  return the_ans;
}

long long Fib(long long exp) {
  std::vector<std::vector<long long>> fib_m = {{1, 1}, {1, 0}};
  std::vector<std::vector<long long>> the_ans = GetPowered(fib_m, exp);
  long long ans = the_ans[0][1] % kMod;
  if (ans < 0) {
    ans += kMod;
  }
  return ans;
}

void DoTheThing(const std::vector<Triple>& the_s, long long the_c) {
  long long ans = 0;
  for (int tmp = 0; tmp != (int)the_s.size(); ++tmp) {
    if (the_s[tmp].the_y >= the_s[tmp].the_x + the_c) {
      long long delta = (the_s[tmp].the_y - the_s[tmp].the_x - the_c);
      long long temp = Fib(delta);
      temp *= the_s[tmp].the_k;
      temp %= kMod;
      ans += temp;
      ans %= kMod;
    }
  }
  std::cout << ans << '\n';
}

int main() {
  std::vector<Triple> the_s;
  long long size = 0;
  long long the_q = 0;
  std::cin >> size >> the_q;
  long long the_x = 0;
  long long the_y = 0;
  long long the_k = 0;
  for (int tmp = 0; tmp < size; ++tmp) {
    std::cin >> the_x;
    std::cin >> the_y;
    std::cin >> the_k;
    the_s.push_back(Triple(the_x, the_y, the_k % kMod));
  }
  long long the_c = 0;
  for (int tmp = 0; tmp < the_q; ++tmp) {
    std::cin >> the_c;
    DoTheThing(the_s, the_c);
  }
}

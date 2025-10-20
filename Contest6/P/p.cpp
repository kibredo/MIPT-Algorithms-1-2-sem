#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
const long long kMod = 1'000'000'007;

std::vector<int> GetConverted(const std::vector<char>& vec) {
  std::vector<int> ans(vec.size(), 0);
  for (int tmp = 0; tmp < (int)vec.size(); ++tmp) {
    if (vec[tmp] == '+') {
      ans[tmp] = 1;
    } else if (vec[tmp] == '.') {
      ans[tmp] = 2;
    }
  }
  return ans;
}

bool IsValid(std::vector<int>& vec, int mask, int the_n) {
  for (int tmp = 0; tmp < the_n; ++tmp) {
    if (((mask >> tmp) & 1) != vec[tmp] && vec[tmp] != 2) {
      return false;
    }
  }
  return true;
}

int GetRestored(int mask, int fbit, int the_n) {
  std::vector<int> bit(the_n, 0);
  bit[0] = fbit;
  for (int tmp = 1; tmp < the_n; ++tmp) {
    if (((mask >> tmp) & 1) == bit[tmp - 1] &&
        ((mask >> (tmp - 1)) & 1) == bit[tmp - 1]) {
      return -1;
    }
    if (((mask >> tmp) & 1) == bit[tmp - 1] ||
        ((mask >> (tmp - 1)) & 1) == bit[tmp - 1]) {
      bit[tmp] = 1 - bit[tmp - 1];
      continue;
    }
    bit[tmp] = bit[tmp - 1];
  }
  int ans = 0;
  int pow = 0;
  for (auto el : bit) {
    if (el == 1) {
      ans += std::pow(2, pow);
    }
    ++pow;
  }
  return ans;
}

void GetInput(int the_n, std::vector<std::vector<char>>& cvec,
              std::string& str) {
  for (int tmp = 0; tmp < the_n; ++tmp) {
    std::cin >> str;
    for (auto el : str) {
      cvec[tmp].push_back(el);
    }
  }
}

int main() {
  int the_m;
  int the_n;
  std::cin >> the_n >> the_m;
  std::string str;
  std::vector<std::vector<char>> cvec(the_n, std::vector<char>(0));
  std::vector<std::vector<int>> vec(the_m, std::vector<int>(0));
  std::vector<std::vector<char>> xvec(the_m, std::vector<char>(the_n));
  GetInput(the_n, cvec, str);
  for (int xtmp = 0; xtmp < the_n; ++xtmp) {
    for (int tmp = 0; tmp < the_m; ++tmp) {
      xvec[tmp][xtmp] = cvec[xtmp][tmp];
    }
  }
  for (int tmp = 0; tmp < the_m; ++tmp) {
    vec[tmp] = GetConverted(xvec[tmp]);
  }
  std::vector<std::vector<int>> dp(the_m,
                                   std::vector<int>(std::pow(2, the_n), 0));
  for (int mask = 0; mask < (1 << the_n); ++mask) {
    if (IsValid(vec[0], mask, the_n)) {
      dp[0][mask] += 1;
    }
  }
  for (int xtmp = 1; xtmp < the_m; ++xtmp) {
    for (int mask = 0; mask < (1 << the_n); ++mask) {
      if (IsValid(vec[xtmp], mask, the_n)) {
        int prevmask1 = GetRestored(mask, 0, the_n);
        int prevmask2 = GetRestored(mask, 1, the_n);
        if (prevmask1 != -1 && IsValid(vec[xtmp - 1], prevmask1, the_n)) {
          dp[xtmp][mask] += dp[xtmp - 1][prevmask1];
        }
        if (prevmask2 != -1 && IsValid(vec[xtmp - 1], prevmask2, the_n)) {
          dp[xtmp][mask] += dp[xtmp - 1][prevmask2];
        }
        dp[xtmp][mask] %= kMod;
      }
    }
  }
  int ans = 0;
  for (auto el : dp[the_m - 1]) {
    ans += el;
    ans %= kMod;
  }
  std::cout << ans << std::endl;
}

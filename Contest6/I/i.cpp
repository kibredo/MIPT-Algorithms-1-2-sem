#include <algorithm>
#include <iostream>
#include <vector>

void LCIS(std::vector<int>& the_cj, std::vector<int>& the_dj) {
  int the_n = the_cj.size();
  int the_m = the_dj.size();
  std::vector<std::vector<int>> the_dp(the_n + 1,
                                       std::vector<int>(the_m + 1, 0));
  std::vector<int> prev(the_m + 1, 0);

  for (int cj_tmp = 1; cj_tmp <= the_n; ++cj_tmp) {
    int ind = 0;
    int best = 0;
    for (int dj_tmp = 1; dj_tmp <= the_m; ++dj_tmp) {
      the_dp[cj_tmp][dj_tmp] = the_dp[cj_tmp - 1][dj_tmp];
      if (the_cj[cj_tmp - 1] == the_dj[dj_tmp - 1] &&
          the_dp[cj_tmp - 1][dj_tmp] < best + 1) {
        the_dp[cj_tmp][dj_tmp] = best + 1;
        prev[dj_tmp] = ind;
      }
      if (the_cj[cj_tmp - 1] > the_dj[dj_tmp - 1] &&
          the_dp[cj_tmp - 1][dj_tmp] > best) {
        best = the_dp[cj_tmp - 1][dj_tmp];
        ind = dj_tmp;
      }
    }
  }
  int the_max = the_dp[1][1];
  for (int cj_tmp = 1; cj_tmp <= the_n; ++cj_tmp) {
    for (int dj_tmp = 1; dj_tmp <= the_m; ++dj_tmp) {
      the_max = std::max(the_max, the_dp[cj_tmp][dj_tmp]);
    }
  }
  std::cout << the_max;
}

int main() {
  int the_n = 0;
  int the_m = 0;
  std::cin >> the_n >> the_m;
  std::vector<int> the_cj(the_n, 0);
  std::vector<int> the_dj(the_m, 0);
  for (int cj_tmp = 0; cj_tmp < the_n; ++cj_tmp) {
    std::cin >> the_cj[cj_tmp];
  }
  for (int dj_tmp = 0; dj_tmp < the_m; ++dj_tmp) {
    std::cin >> the_dj[dj_tmp];
  }
  LCIS(the_cj, the_dj);
}

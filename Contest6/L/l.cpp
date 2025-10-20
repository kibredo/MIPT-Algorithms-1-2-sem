#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
  int the_n = 0;
  int the_g = 0;
  int the_k = 0;
  std::cin >> the_n >> the_g >> the_k;
  std::vector<std::vector<int>> vec(3, std::vector<int>(the_n));
  std::set<int> the_s;
  for (int tmp = 0; tmp < the_n; ++tmp) {
    std::cin >> vec[0][tmp] >> vec[1][tmp] >> vec[2][tmp];
    the_s.insert(vec[2][tmp]);
  }
  std::vector<int> the_w;
  for (auto el : the_s) {
    the_w.push_back(el);
  }
  for (auto& el : vec[2]) {
    el = std::lower_bound(the_w.begin(), the_w.end(), el) - the_w.begin();
  }
  std::vector<std::vector<int>> vec_of_k(the_s.size());
  std::vector<std::vector<int>> vec_of_v(the_s.size());
  std::vector<std::vector<int>> vec_of_g(the_s.size());
  for (int tmp = 0; tmp < the_n; tmp++) {
    vec_of_k[vec[2][tmp]].push_back(vec[0][tmp]);
    vec_of_v[vec[2][tmp]].push_back(vec[1][tmp]);
    vec_of_g[vec[2][tmp]].push_back(0);
  }
  std::vector<std::vector<int>> dp(the_w.size() + 1,
                                   std::vector<int>(the_k + 1));
  for (int gtmp = 1; gtmp <= (int)the_w.size(); ++gtmp) {
    for (int ktmp = 1; ktmp <= the_k; ++ktmp) {
      int help_tmp = dp[gtmp - 1][ktmp];
      for (int tmp = 0; tmp < the_n; tmp++) {
        if (ktmp >= vec_of_k[gtmp - 1][tmp]) {
          help_tmp =
              std::max(help_tmp, dp[gtmp - 1][ktmp - vec_of_k[gtmp - 1][tmp]] +
                                     vec_of_v[gtmp - 1][tmp]);
        }
      }
      dp[gtmp][ktmp] = help_tmp;
    }
  }
  int result = -1;
  for (int tmp = 1; tmp < (int)dp[the_s.size()].size(); ++tmp) {
    if (dp[the_s.size()][tmp] > result) {
      result = dp[the_s.size()][tmp];
    }
  }
  std::cout << result;
}

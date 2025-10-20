#include <algorithm>
#include <iostream>
#include <vector>

int DoTheThing(std::vector<int>& gangster_prev, std::vector<int>& city,
               int& street_size, int& gangster_distance) {
  int max_street = 0;
  std::vector<int> gangster_dp(street_size, 1);
  std::vector<bool> is_increasing(street_size, false);
  for (int street_number = 1; street_number < street_size; ++street_number) {
    for (int tmp = 0; tmp < street_number; ++tmp) {
      if ((is_increasing[tmp] && city[street_number] < city[tmp]) ||
          ((!is_increasing[tmp] && city[street_number] > city[tmp]) &&
           gangster_dp[street_number] < gangster_dp[tmp] + 1)) {
        gangster_dp[street_number] = gangster_dp[tmp] + 1;
        gangster_prev[street_number] = tmp;
        is_increasing[street_number] = !is_increasing[tmp];
        if (gangster_dp[street_number] > gangster_distance) {
          gangster_distance = gangster_dp[street_number];
          max_street = street_number;
        }
      }
    }
  }
  return max_street;
}

void DoTheFinalThing(int current_index, std::vector<int>& city,
                     std::vector<int>& gangster_prev) {
  std::vector<int> gangster_ans;
  while (current_index != -1) {
    gangster_ans.push_back(city[current_index]);
    current_index = gangster_prev[current_index];
  }
  std::reverse(gangster_ans.begin(), gangster_ans.end());
  for (int elem : gangster_ans) {
    std::cout << elem << " ";
  }
}

int main() {
  int street_size = 0;
  int gangster_distance_1 = 1;
  int gangster_distance_2 = 1;
  std::cin >> street_size;
  std::vector<int> city(street_size);
  for (int gangster_tmp = 0; gangster_tmp < street_size; ++gangster_tmp) {
    std::cin >> city[gangster_tmp];
  }
  std::vector<int> gangster_prev_1(street_size, -1);
  std::vector<int> gangster_prev_2(street_size, -1);
  int current_index1 =
      DoTheThing(gangster_prev_1, city, street_size, gangster_distance_1);
  for (int tmp = 0; tmp < street_size; ++tmp) {
    city[tmp] *= -1;
  }
  int current_index2 =
      DoTheThing(gangster_prev_2, city, street_size, gangster_distance_2);
  for (int tmp = 0; tmp < street_size; ++tmp) {
    city[tmp] *= -1;
  }
  std::cout << std::max(gangster_distance_1, gangster_distance_2) << std::endl;
  (gangster_distance_1 > gangster_distance_2)
      ? DoTheFinalThing(current_index1, city, gangster_prev_1)
      : DoTheFinalThing(current_index2, city, gangster_prev_2);
}

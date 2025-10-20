#include <deque>
#include <iostream>
#include <vector>
int main() {
  int number_of_potions = 0;
  std::cin >> number_of_potions;
  std::vector<int> potions(number_of_potions + 2);
  potions[0] = -1;
  potions[number_of_potions + 1] = -1;
  for (int tmp = 1; tmp <= number_of_potions; ++tmp) {
    std::cin >> potions[tmp];
  }
  std::vector<int> min_right_element(number_of_potions + 2);
  std::deque<int> temp_stack;
  temp_stack.push_back(0);
  for (int tmp = 1; tmp <= number_of_potions + 1; ++tmp) {
    while (potions[temp_stack.back()] > potions[tmp]) {
      min_right_element[temp_stack.back()] = tmp;
      temp_stack.pop_back();
    }
    temp_stack.push_back(tmp);
  }
  temp_stack.resize(0);
  std::vector<int> left_elements(number_of_potions + 2);
  temp_stack.push_back(number_of_potions + 1);
  for (int tmp = number_of_potions; tmp >= 0; --tmp) {
    while (potions[tmp] < potions[temp_stack.back()]) {
      left_elements[temp_stack.back()] = tmp;
      temp_stack.pop_back();
    }
    temp_stack.push_back(tmp);
  }
  long long result = 0;
  for (int tmp = 1; tmp <= number_of_potions; ++tmp) {
    long long local_max_ans = potions[tmp];
    local_max_ans *= (min_right_element[tmp] - left_elements[tmp] - 1);
    if (local_max_ans > result) {
      result = local_max_ans;
    }
  }
  std::cout << result;
  return 0;
}

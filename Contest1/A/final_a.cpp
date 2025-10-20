#include <iostream>
#include <vector>
int main() {
  int number_of_elements;
  std::cin >> number_of_elements;
  const int kInf = 2000000000;
  std::vector<int> power(number_of_elements + 1);
  std::vector<int> lowest_left(number_of_elements + 1);
  std::vector<int> lowest_right(number_of_elements + 1);
  lowest_left[0] = kInf;
  for (int temp = 1; temp != number_of_elements + 1; ++temp) {
    std::cin >> power[temp];
    lowest_left[temp] = std::min(lowest_left[temp - 1], power[temp]);
  }
  lowest_right[number_of_elements] = power[number_of_elements];
  for (int temp = number_of_elements - 1; temp > 0; --temp) {
    lowest_right[temp] = std::min(lowest_right[temp + 1], power[temp]);
  }
  int number_of_requests;
  std::cin >> number_of_requests;
  int left_bound;
  int right_bound;
  while (--number_of_requests >= 0) {
    std::cin >> left_bound >> right_bound;
    std::cout << std::min(lowest_right[right_bound], lowest_left[left_bound]);
    std::cout << std::endl;
  }
  return 0;
}

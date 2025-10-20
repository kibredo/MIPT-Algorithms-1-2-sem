#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

void GetValues(std::vector<double>& loudness, std::vector<double>& prefix, int num) {
  double tmp;
  for (int temp = 0; temp < num; ++temp) {
    std::cin >> tmp;
    loudness[temp] = log(tmp);
    prefix[temp + 1] = prefix[temp] + log(tmp);
  }
}

void PrintAnswer(std::vector<double>& prefix, int quantity) {
  int right = 0;
  int left = 0;
  const int kConst = 8;
  for (int temp = 0; temp < quantity; ++temp) {
    std::cin >> left >>  right;
    ++left;
    ++right;
    std::cout << std::setprecision(kConst)
              << exp((prefix[right] - prefix[left - 1]) / (1 - left + right))
              << std::endl;
  }
}

int main() {
  int number_of_elements = 0;
  std::cin >> number_of_elements;
  std::vector<double> loudness(number_of_elements, 0);
  std::vector<double> prefix(number_of_elements + 1, 0);
  GetValues(loudness, prefix, number_of_elements);
  int quantity = 0;
  std::cin >> quantity;
  PrintAnswer(prefix, quantity);
  return 0;
}

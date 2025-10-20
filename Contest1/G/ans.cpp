#include <iostream>
#include <vector>

int main() {
  int amount;
  std::cin >> amount;
  std::vector<int64_t> numbers(amount + 1);
  for (int i = 1; i <= amount; ++i) {
    std::cin >> numbers[i];
  }
  const int kByte = 8;
  const int kChar = 256;
  std::vector<int> count(kChar, 0);
  for (int iter = 0; iter < kByte; ++iter) {
    for (int i = 1; i <= amount; ++i) {
      int byte = *((unsigned char*)&numbers[i] + iter);
      count[byte]++;
    }
    for (int i = 1; i < kChar; ++i) {
      count[i] += count[i - 1];
    }
    std::vector<int64_t> current(amount + 1, 0);
    for (int i = amount; i >= 1; --i) {
      int byte = *((unsigned char*)&numbers[i] + iter);
      current[count[byte]--] = numbers[i];
    }
    std::swap(numbers, current);
    count.assign(kChar, 0);
  }
  for (int i = 1; i < amount + 1; ++i) {
    std::cout << numbers[i] << '\n';
  }
}

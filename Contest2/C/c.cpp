#include <deque>
#include <iostream>
void FixDifference(std::deque<int>& first, std::deque<int>& second) {
  if (second.size() > first.size()) {
    while (!second.empty() && first.size() < second.size()) {
      first.push_back(second.front());
      second.pop_front();
    }
  } else {
    while (!first.empty() && first.size() > second.size() + 1) {
      second.push_front(first.back());
      first.pop_back();
    }
  }
}
int main() {
  int num = 0;
  std::cin >> num;
  std::deque<int> first_half(0);
  std::deque<int> second_half(0);
  char goblin_type = '0';
  const char kVip = '*';
  const char kSimple = '+';
  const char kKick = '-';
  int goblin_number = 0;
  for (int tmp = 0; tmp != num; ++tmp) {
    std::cin >> goblin_type;
    if (goblin_type == kKick) {
      std::cout << first_half.front() << '\n';
      first_half.pop_front();
    }
    if (goblin_type == kSimple) {
      std::cin >> goblin_number;
      second_half.push_back(goblin_number);
    }
    if (goblin_type == kVip) {
      std::cin >> goblin_number;
      first_half.push_back(goblin_number);
    }
    FixDifference(first_half, second_half);
  }
}

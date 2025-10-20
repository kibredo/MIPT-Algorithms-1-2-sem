#include <iostream>
#include <vector>

void Partition(std::vector<int>& values, int left, int right, int& one, int& two) {
  int pivot = values[left];
  int lower = left;
  int equal = left;
  for (int i = left; i < right; i++) {
    if (values[i] < pivot) {
      std::swap(values[lower], values[i]);
      std::swap(values[equal], values[i]);
      equal++;
      lower++;
    } else if (values[i] == pivot) {
      std::swap(values[i], values[equal]);
      equal++;
    }
  }
  one = lower;
  two = equal;
}

void Search(std::vector<int>& values, int left, int right) {
  if (right - left <= 1) {
    return;
  }
  int lower;
  int equal;
  Partition(values, left, right, lower, equal);
  Search(values, left, lower);
  Search(values, equal, right);
}

int main() {
  int number;
  std::cin >> number;
  std::vector<int> values(number);
  for (int i = 0; i < number; i++) {
    std::cin >> values[i];
  }
  Search(values, 0, number);
  for (int i = 0; i < number; i++) {
    std::cout << values[i] << " ";
  }
}

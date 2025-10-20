#include <iostream>
#include <vector>
#include <random>
std::mt19937 gen(time(nullptr));
std::vector<int> arr;
std::pair<int, int> Partition(int left, int right, int pivot) {
  int sep = left - 1;
  for (int ind = left; ind < right; ind++) {
    if (arr[ind] >= pivot) {
      continue;
    }
    if (arr[ind] < pivot) {
      std::swap(arr[sep + 1], arr[ind]);
      ++sep;
    }
  }
  int count_pivots = 0;
  for (int ind = left; ind < right; ind++) {
    if (arr[ind] == pivot) {
      std::swap(arr[sep + 1], arr[ind]);
      ++sep;
      ++count_pivots;
    }
  }
  return {sep - count_pivots, sep};
}
int RandomPosition(int left, int right) {
  std::uniform_int_distribution<> distribution(left, right - 1);
  return distribution(gen);
}
void QuickSort(int left, int right) {
  if (right - left <= 1) {
    return;
  }
  int pivot = arr[RandomPosition(left, right)];
  int sep_left = Partition(left, right, pivot).first + 1;
  int sep_right = Partition(left, right, pivot).second + 1;
  QuickSort(left, sep_left);
  QuickSort(sep_right, right);
}//10 5 4 2 6 4 4 5 66 1 443
int main() {
  int n = 0;
  int var = 0;
  std::cin >> n;
  for (int tmp = 0; tmp < n; ++tmp) {
    std::cin >> var;
    arr.push_back(var);
  }
  QuickSort(0, n);
  for (auto elem : arr) {
    std::cout << elem;
  }
}   

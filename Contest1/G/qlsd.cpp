#include <iostream>
#include <vector>
int FindMax(std::vector<long long>& arr) {
  int max = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}
void LsdSort(std::vector<long long>& arr) {
  long long max = FindMax(arr);
  long long exp = 1;
  while (max / exp > 0) {
    std::vector<long long> output(arr.size());
    int count[10] = {0};
    for (int i = 0; i < arr.size(); i++) {
      count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }
    for (int i = arr.size() - 1; i >= 0; i--) {
      output[count[(arr[i] / exp) % 10] - 1] = arr[i];
      count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < arr.size(); i++) {
      arr[i] = output[i];
    }
    exp *= 10;
  }
}

int main() {
  std::vector<long long> arr(0);
  int num = 0;
  int elem = 0;
  std::cin >> num;
  for (int tmp = 0; tmp < num; ++tmp) {
    std::cin >> elem;
    arr.push_back(elem);
  }
  LsdSort(arr);
  for (auto elm : arr) {
    std::cout << elm << std::endl;
  }
  return 0;
}

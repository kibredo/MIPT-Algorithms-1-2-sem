#include<iostream>
#include<math.h>
#include<vector>
int FindMax(std::vector<long long>& arr) {
  int max = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}
void Stable_sort(std::vector<std::vector<long long>> &vect, int index) {
  std::vector<long long> arr = vect
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
void LSD(std::vector<std::vector<long long>> &vec, int number) {
  for(int ind = 0;ind < 65;++ind) {
    Stable_sort(vec, ind);
  }
}
std::vector<long long> To_binary(long long num) {
  int counter = 0;
  std::vector<long long> ans(65,0);
  while(num) {
    ans[64 - counter] = num % 2;
    ++counter;
    num /= 2;
  }
  return ans;
}
long long From_binary(std::vector<long long> vect) {
  long long a = 0;
  for(int ind = 0;ind < 65;++ind) {
    a += pow(2,ind) * vect[64 - ind];
  }
  return a;
}
int main() {
  long long num = 0;
  std::cin >> num;
  std::vector<std::vector<long long>> vectr(num);
  for(int u = 0;u < test;++u) {
    std::cin >> a;
    vectr[u] = To_binary(a);
  }
  LSD(vectr, num);
  for (auto elem : vectr) {
    std::cout << From_binary(elem) << std::endl;
  }
  return 0;
}

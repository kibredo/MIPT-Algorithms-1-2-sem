#include <iostream>
#include <vector>
int TakeByte(int64_t var, int position) {
    return ((var >> (8 * position)) & 255);
}
void StableSort(std::vector<int64_t>& arr, int size, std::vector<int>& bytes, int byte) {
    std::vector<int64_t> ans(size + 1, 0);
    for (int tmp = 1; tmp < 256; ++tmp) {
      bytes[tmp] += bytes[tmp - 1];
    }
    for (int tmp = size; tmp >= 1; --tmp) {
      ans[bytes[TakeByte(arr[tmp], byte)]] = arr[tmp];
      --bytes[TakeByte(arr[tmp], byte)];
    }
    std::swap(arr,ans);
}
void LsdSort(std::vector<int64_t>& vect, int size) {
  std::vector<int> count(256, 0);
  for (int iter = 0; iter < 8; ++iter) {
    for (int tmp = 1; tmp <= size; ++tmp) {
      count[TakeByte(vect[tmp], iter)]++;
    }
    StableSort(vect, size, count, iter);
  }
}
int main() {
  int num = 0;
  std::cin >> num; 
  std::vector<int64_t> vec(num + 1);
  for (int tmp = 1; tmp <= num; ++tmp) {
    std::cin >> vec[tmp];
  }
  LsdSort(vec, num);
  for (int tmp = 1; tmp <= num; ++tmp) {
    std::cout << vec[tmp] << '\n';
  }
}

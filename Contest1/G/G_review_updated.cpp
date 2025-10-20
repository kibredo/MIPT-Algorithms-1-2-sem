#include <iostream>
#include <vector>

const int kKmaxByte = 255;
const int kKoneByte = 8;
const int kKsize = 256;
int TakeByte(long long var, int position) {
  return ((var >> (kKoneByte * position)) & kKmaxByte);
}

void StableSort(std::vector<long long>& arr, int size, std::vector<int>& bts,
                int byte) {
  std::vector<long long> ans(size + 1, 0);
  for (int tmp = 1; tmp < kKsize; ++tmp) {
    bts[tmp] += bts[tmp - 1];
  }
  for (int tmp = size; tmp > 0; --tmp) {
    ans[bts[TakeByte(arr[tmp], byte)]] = arr[tmp];
    --bts[TakeByte(arr[tmp], byte)];
  }
  std::swap(arr, ans);
}

void LSDSort(std::vector<long long>& vect, int size) {
  std::vector<int> bytes(kKsize, 0);
  for (int iter = 0; iter < kKoneByte; ++iter) {
    for (int tmp = 1; tmp <= size; ++tmp) {
      bytes[TakeByte(vect[tmp], iter)]++;
    }
    StableSort(vect, size, bytes, iter);
    bytes.assign(kKsize, 0);
  }
}

int main() {
  int num = 0;
  std::cin >> num;
  std::vector<long long> vec(num + 1);
  for (int tmp = 1; tmp <= num; ++tmp) {
    std::cin >> vec[tmp];
  }
  LSDSort(vec, num);
  for (int tmp = 1; tmp <= num; ++tmp) {
    std::cout << vec[tmp] << '\n';
  }
}

#include <iostream>
#include <vector>
int TakeByte(long long var, int position) {
    return ((var >> (8 * position)) & 255);
}
void StableSort(std::vector<int>& arr, int size, std::vector<int>& bytes, int byte) {
    std::vector<long long> ans(size + 1, 0);
    for (int tmp = 1; tmp < 256; ++tmp) {
      bytes[tmp] += bytes[tmp - 1];
    }
    int temp = 0;
    for (int tmp = size; tmp >= 1; --tmp) {
      ans[bytes[TakeByte(arr[tmp], byte) - temp]] = arr[tmp];
      temp += 1;
    }
    int index = 0;
    for(auto elem : arr) {
        elem = ans[index];
        ++index;
    }
}
void Lsd(std::vector<long long>& vect, int size) {
    
}
int main() {
  int num = 0;
  std::cin >> num; 
  std::vector<long long> vec(num + 1);
  for (int tmp = 1; tmp <= num; ++tmp) {
    std::cin >> vec[tmp];
  }
  //const int kByte = 8;
  //const int kChar = 256;
  std::vector<int> count(256, 0);
  for (int iter = 0; iter < 8; ++iter) {
    //std::vector<int> count(256, 0);
    for (int tmp = 1; tmp <= num; ++tmp) {
      count[TakeByte(vec[tmp], iter)]++;
    }
    /*for (int tmp = 1; tmp < 256; ++tmp) {
      count[tmp] += count[tmp - 1];
    }
    std::vector<long long> current(num + 1, 0);
    for (int tmp = num; tmp >= 1; --tmp) {
      int byte = *((unsigned char*)&vec[tmp] + iter);
      current[count[byte]--] = vec[tmp];
    }
    std::swap(vec, current);
    count.assign(256, 0);*/
    StableSort(vec, num, count, iter);
  }
  for (int tmp = 1; tmp <= num; ++tmp) {
    std::cout << vec[tmp] << '\n';
  }
}

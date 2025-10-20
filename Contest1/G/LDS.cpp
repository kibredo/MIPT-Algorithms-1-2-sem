#include<iostream>
#include<math.h>
#include<vector>
void Stable_sort(std::vector<std::vector<long long>> &column, int index) {

}
void LSD(std::vector<std::vector<long long> > &vec, int number) {
  for(int ind = 0;ind < number;++ind) {
    Bubble_sort(vec, ind);
  }
}
std::vector<long long> To_binary(long long num) {
  int counter = 0;
  std::vector<long long> ans(50,0);
  while(num) {
    ans[counter] = num % 2;
    ++counter;
    num /= 2;
  }
  return ans;
}
long long From_binary(std::vector<long long> vect) {
  long long a = 0;
  for(int ind = 0;ind < 50;++ind) {
    a += pow(2,ind) * vect[ind];
  }
  return a;
}
int main() {
  long long test = 0;
  std::cin >> test;
  for(int i = 0;i < 15;++i) {
    std::cout << To_binary(test)[i];
  }
  /*long long a;
  std::vector<std::vector<long long> > v(test);
  for(int u = 0;u < test;++u) {
    std::cin >> a;
    v[u] = To_binary(a);
  }
  LSD(v, test);
  for(auto el : v) {
    std::cout << From_binary(el) << std::endl;
  }*/
  return 0;
}

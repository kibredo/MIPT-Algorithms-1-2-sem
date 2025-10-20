#include<iostream>
#include<vector>
void merge(std::vector<int> a, std::vector<int> b, std::vector<int>& c) {
  int i = 0;
  int j = 0;
  int m = (int)b.size();
  int n = (int)a.size();
  while(i < n || j < m) {
    if(j == m || (i < n && a[i] <= b[j])) {
      c[i + j] = a[i];
      ++i;
    } else {
      c[i + j] = b[i];
      ++i;
    }
  }
}
void merge_sort(std::vector<int>& A) {
  if(A.size() > 1) {
    int index = A.size()/2;
    std::vector<int> L(0);
    std::vector<int> R(0);
    for(int u = 0;u < index;++u) {
      L.push_back(A[u]);
    }
    for(int u = index;u < A.size();++u) {
      R.push_back(A[u]);
    }
    merge_sort(L);
    merge_sort(R);
    merge(L, R, A);
  }

}
int main() {
  int num = 0;
  int var = 0;
  std::cin >> num;
  std::vector<int> vec(0);
  for(int tmp = 0;tmp < num;++tmp) {
    std::cin >> var; 
    v0.push_back(var);
  }
  merge_sort(v0);
  for(auto el : v0) {
    std::cout << el << " ";
  }
}

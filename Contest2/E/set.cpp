#include<iostream>
#include<vector>

class set {
  int size;
  std::vector<int> values;
  void insert(int element);
  void erase(int element);
  void index_erase(int index); 
}
void set::insert(int element) {
  int left = 0;
  int right = size - 1;
  while(right - left > 1) {
    int mid = (right + left) / 2;
    if(values[mid] > element) {
      right = mid;
    } else {
      left = mid;
    }
  }

}

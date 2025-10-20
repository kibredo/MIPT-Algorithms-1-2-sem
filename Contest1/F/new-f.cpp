#include <iostream>
#include <vector>
#include <deque>
void Partition(std::vector<int>& vec, int& kstat, int pivot_index) {
  int pivot = vec[pivot_index];
  std::vector<int> ans(0);
  std::deque<int> lhs(0);
  std::deque<int> rhs(0);
  int tempr = 0;
  for (int tmp = 0; tmp < vec.size(); ++tmp) {
    if (vec[tmp] == pivot) {
      ++tempr;
    }
    if (vec[tmp] < pivot) {
      lhs.push_back(vec[tmp]);
    }
    if (vec[tmp] > pivot) {
      rhs.push_back(vec[tmp]);
    }
  }
  if (tempr + (int)lhs.size() >= kstat) {
    while(lhs.size() > 0) {
      ans.push_back(lhs.front());
      lhs.pop_front();
    }
    while(tempr > 0) {
      ans.push_back(pivot);
      --tempr;
    }
  }
  else {
    kstat -= (int)lhs.size() + tempr;
    while(rhs.size() > 0) {
      ans.push_back(rhs.front());
      rhs.pop_front();
    }
  }
  vec = ans;
}
int Quick_select(std::vector<int> vect, int k_stat) {
  while(vect.size() > 1) {
    int temp = (int)vect.size();
    int pivot_tmp = rand() % temp;
    Partition(vect, k_stat, pivot_tmp);
  }
  return vect[0];
}
int main() {
	std::vector<int> vect;
	int size = 0;
	int val = 0;
	std::cin >> size;
	for (int tmp = 0; tmp < size; ++tmp) {
	  std::cin >> val;
	  vect.push_back(c);
	}
	int k_stats = 0;
	std::cin >> k_stats;
	std::cout << Quick_select(vect, kstats);
} 

#include <iostream>
#include <vector>
#include <deque>
void Partition(std::vector<int>& vec, int pivot_index, int start, int finish, int& lbound, int& rbount) {
  int pivot = vec[pivot_index];
  std::vector<int> ans(0);
  std::deque<int> lhs(0);
  std::deque<int> rhs(0);
  int tempr = 0;
  for (int tmp = start; tmp <= finish; ++tmp) {
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
  while(lhs.size() != 0) {
    ans.push_back(lhs.front());
    lhs.pop_front();
  }
  while(tempr > 0) {
    ans.push_back(pivot);
    --tempr;
  }
  while(rhs.size() != 0) {
    ans.push_back(rhs.front());
    rhs.pop_front();
  }
  for (int tmp = start;tmp <= finish; ++tmp) {
    vec[tmp] = ans[tmp - start];
  }
}
void Quick_sort(std::vector<int>& vec, int size, int start_srt, int finish_srt) {
  int pivot_tmp = rand() % (finish_srt - start_srt);
  Partition(vec, pivot_tmp, start_srt, finish_srt);
  int left_bound = 0;
  int right bound = 0;
  Quick_sort(vec, finish_srt - start_srt + 1
}
int main() {
	std::vector<int> a;
	int b,c,d,st,fn;
	std::cin >> b;
	while(b) {
	  std::cin >> c;
	  a.push_back(c);
	  --b;
	}
	std::cin >> d >> st >> fn;
	Partition(a, d, st, fn);
	for(auto el : a)
		std::cout << el;
} 

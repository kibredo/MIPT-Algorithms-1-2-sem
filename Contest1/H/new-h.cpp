#include <iostream>
#include <vector>
#include <deque>
/*std::vector<int> Partition(std::vector<int> vec, int pivot_index) {
  int pivot = vec[pivot_index];
  std::vector<int> ans(0);
  std::deque<int> lhs(0);
  std::deque<int> rhs(0);
  int tempr = 0;
  for (auto elem : vec) {
    if (elem == pivot) {
      ++tempr;
    }
    if (elem < pivot) {
      lhs.push_back(elem);
    }
    if (elem > pivot) {
      rhs.push_back(elem);
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
  return ans;
}*/
void Partition(std::vector<int>& vec, int pivot_index, int start, int finish) {
  int pivot = vec[pivot_index];
  std::vector<int> ans(0);
  std::deque<int> lhs(0);
  std::deque<int> rhs(0);
  int tempr = 0;
  for (auto elem : vec) {
    if (elem == pivot) {
      ++tempr;
    }
    if (elem < pivot) {
      lhs.push_back(elem);
    }
    if (elem > pivot) {
      rhs.push_back(elem);
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
  vec = ans;
}
void Quick_sort(std::vector<int>& vec, int size) {
  int pivot_tmp = rand() % size;
  
}
int main() {
	std::vector<int> a;
	int b,c,d;
	std::cin >> b;
	while(b) {
	  std::cin >> c;
	  a.push_back(c);
	  --b;
	}
	std::cin >> d;
	Partition(a, d);
	for(auto el : a)
		std::cout << el;
} 

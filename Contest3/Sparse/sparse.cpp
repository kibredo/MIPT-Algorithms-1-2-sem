#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

void GetPreprocessed(std::vector<int>& arr, int size,
                     std::vector<std::vector<std::pair<int, int>>>& sparse) {
  for (int tmp = 0; tmp < size; tmp++) {
    sparse[tmp][0].first = tmp;
  }
  for (int log_index = 1; (1 << log_index) <= size; log_index++) {
    for (int tmp = 0; (tmp + (1 << log_index) - 1) < size; tmp++) {
      if (log_index == 1) {
        int first = sparse[tmp][0].first;
        int second = sparse[tmp + 1][0].first;
        if (arr[sparse[tmp][0].first] > arr[sparse[tmp + 1][0].first]) {
          std::swap(first, second);
        }
        sparse[tmp][log_index].second = second;
        sparse[tmp][log_index].first = first;
      } else {
        std::vector<std::pair<int, int>> vec(4);
        vec[0].second = sparse[tmp][log_index - 1].first;
        vec[1].second =
            sparse[tmp + (1 << (log_index - 1))][log_index - 1].first;
        vec[2].second =
            sparse[tmp + (1 << (log_index - 1))][log_index - 1].second;
        vec[3].second = sparse[tmp][log_index - 1].second;
        for (int tmp = 0; tmp < 4; ++tmp) {
          vec[tmp].first = arr[vec[tmp].second];
        }
        std::sort(vec.begin(), vec.end());
        sparse[tmp][log_index].second = vec[1].second;
        sparse[tmp][log_index].first = vec[0].second;
      }
    }
  }
}
int DoTheThing(std::vector<int>& arr, int left, int right,
               std::vector<std::vector<std::pair<int, int>>>& sparse) {
  int index = (int)log2(right - left + 1);
  std::vector<int> vec(0);
  std::set<int> the_set;
  the_set.insert(sparse[left][index].second);
  the_set.insert(sparse[left][index].first);
  the_set.insert(sparse[right - (1 << index) + 1][index].second);
  the_set.insert(sparse[right - (1 << index) + 1][index].first);
  for (auto elem : the_set) {
    vec.push_back(arr[elem]);
  }
  std::sort(vec.begin(), vec.end());
  return vec[1];
}
int main() {
  int size = 0;
  std::cin >> size;
  int the_log = 1;
  int small = 1;
  while (the_log < size) {
    the_log *= 2;
	++small;
  }
  ++small;	
  std::vector<std::pair<int, int>> elementary(small, {0, 0});
  std::vector<std::vector<std::pair<int, int>>> sparse(size, elementary);
  int request = 0;
  std::cin >> request;
  std::vector<int> arr(size);
  for (int tmp = 0; tmp < size; ++tmp) {
    std::cin >> arr[tmp];
  }
  GetPreprocessed(arr, size, sparse);
  int left = 0;
  int right = 0;
  for (int tmp = 0; tmp < request; ++tmp) {
    std::cin >> left >> right;
    int answer = DoTheThing(arr, left - 1, right - 1, sparse);
    std::cout << answer << std::endl;
  }
  return 0;
}

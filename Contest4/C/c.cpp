#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void GetSearched(std::vector<std::pair<std::string, std::string>>& vec,
                 std::vector<std::pair<std::string, std::string>>& fvec,
                 std::string& name) {
  int right = (int)vec.size() - 1;
  int left = 0;
  while (right - left > 1) {
    int mid = (right + left) / 2;
    if (vec[mid].first > name) {
      right = mid;
    } else {
      left = mid;
    }
  }
  if (vec[left].first == name) {
    std::cout << vec[left].second << std::endl;
    return;
  }
  if (vec[left + 1].first == name) {
    std::cout << vec[left + 1].second << std::endl;
    return;
  }
  GetSearched(fvec, vec, name);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::vector<std::pair<std::string, std::string>> vec(0);
  std::vector<std::pair<std::string, std::string>> fvec(0);
  std::string name;
  std::string key;
  int size = 0;
  int quant = 0;
  std::cin >> size;
  std::pair<std::string, std::string> total;
  for (int tmp = 0; tmp < size; ++tmp) {
    std::cin >> total.second >> total.first;
    vec.push_back(total);
    fvec.push_back({total.second, total.first});
  }
  std::sort(vec.begin(), vec.end());
  std::sort(fvec.begin(), fvec.end());
  std::cin >> quant;
  for (int tmp = 0; tmp < quant; ++tmp) {
    std::cin >> name;
    GetSearched(vec, fvec, name);
  }
}

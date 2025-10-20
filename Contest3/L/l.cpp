#include <iostream>
#include <string>
#include <vector>

void GetCreated(std::vector<std::vector<std::pair<int, int>>>& vec,
                int version) {
  int old_ver = 0;
  int old_ind = 0;
  int new_val = 0;
  std::cin >> old_ver >> old_ind >> new_val;
  --old_ver;
  --old_ind;
  vec[old_ind].push_back(std::make_pair(version, new_val));
}

void DoTheThing(const std::vector<std::vector<std::pair<int, int>>>& vec) {
  int version = 0;
  int index = 0;
  std::cin >> version >> index;
  --index;
  int right = (int)vec[index].size();
  int left = 0;
  while (right - left > 1) {
    int mid = (right + left) / 2;
    if (vec[index][mid].first > version) {
      right = mid;
    } else {
      left = mid;
    }
  }
  if (vec[index][right - 1].first < version) {
    left = right - 1;
  }
  std::cout << vec[index][left].second << '\n';
}

int main() {
  int num;
  std::cin >> num;
  std::vector<std::pair<int, int>> base(0);
  std::vector<std::vector<std::pair<int, int>>> vec(num, base);
  int elem = 0;
  for (int tmp = 0; tmp < num; ++tmp) {
    std::cin >> elem;
    vec[tmp].push_back(std::make_pair(1, elem));
  }
  int version = 1;
  int quant = 0;
  std::cin >> quant;
  std::string str;
  for (int tmp = 0; tmp < quant; ++tmp) {
    std::cin >> str;
    if (str == "create") {
      ++version;
      GetCreated(vec, version);
    } else {
      DoTheThing(vec);
    }
  }
}

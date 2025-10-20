#include <iostream>
#include <vector>
#include <cmath>

struct Fenwick {
  std::vector<std::vector<int>> data;
  int width;
  int hight;
  void GetUpdated(int the_x, int the_y, int delta) {
    for (int tmp_x = the_x; tmp_x < width; tmp_x |= (tmp_x + 1)) {
      for (int tmp_y = the_y; tmp_y < hight; tmp_y |= (tmp_y + 1)) {
        data[tmp_x][tmp_y] += delta;
      }
    }
  }

  int GetSummed(int the_x, int the_y) {
    int ans = 0;
    for (int tmp_x = the_x; tmp_x >= 0; tmp_x = (tmp_x & (tmp_x + 1)) - 1) {
      for (int tmp_y = the_y; tmp_y >= 0; tmp_y = (tmp_y & (tmp_y + 1)) - 1) {
        ans += data[tmp_x][tmp_y];
      }
    }
    return ans;
  }

  int GetFullSummed(int the_x1, int the_y1, int the_x2, int the_y2) {
    return GetSummed(the_x2, the_y2) + GetSummed(the_x1 - 1, the_y1 - 1) -
           GetSummed(the_x1 - 1, the_y2) - GetSummed(the_x2, the_y1 - 1);
  }
};

int GetLength(int first, int second) { return std::abs(first - second) + 1; }

int main() {
  int quant;
  int requests;
  std::cin >> quant >> requests;
  Fenwick store;
  store.width = quant;
  store.hight = quant;
  int the_x1 = 0;
  int the_y1 = 0;
  int the_x2 = 0;
  int the_y2 = 0;
  store.data.resize(quant, std::vector<int>(quant, 0));
  for (int tmp = 0; tmp < requests; ++tmp) {
    std::string input;
    std::cin >> input;
    if (input == "GET") {
      std::cin >> the_x1 >> the_y1 >> the_x2 >> the_y2;
      std::pair<int, int> pair_breakpoint = {std::min(the_x1, the_x2),
                                             std::min(the_y1, the_y2)};
      int x_length = GetLength(the_x2, the_x1);
      int y_length = GetLength(the_y2, the_y1); 
      std::cout << store.GetFullSummed(pair_breakpoint.first - 1,
                                       pair_breakpoint.second - 1,
                                       pair_breakpoint.first + x_length - 2,    
                                       pair_breakpoint.second + y_length - 2);
      std::cout << std::endl;
    } else {
      std::cin >> the_x1 >> the_y1;
      store.GetUpdated(the_x1 - 1, the_y1 - 1, 1);
    }
  }
}

#include <cmath>
#include <iostream>
#include <vector>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int num = 0;
  int mun = 0;
  int lun = 0;
  int elem = 0;
  std::cin >> num >> mun >> lun;
  std::vector<std::vector<int>> veca(num);
  std::vector<std::vector<int>> vecb(mun);
  for (int tmp = 0; tmp < num; ++tmp) {
    for (int utmp = 0; utmp < lun; ++utmp) {
      std::cin >> elem;
      (veca[tmp]).push_back(elem);
    }
  }
  for (int tmp = 0; tmp < mun; ++tmp) {
    for (int utmp = 0; utmp < lun; ++utmp) {
      std::cin >> elem;
      (vecb[tmp]).push_back(elem);
    }
  }
  int qnt = 0;
  std::cin >> qnt;
  int itmp = 0;
  int jtmp = 0;
  for (int tmp = 0; tmp < qnt; ++tmp) {
    std::cin >> itmp >> jtmp;
    --itmp;
    --jtmp;
    std::vector<int> vat = veca[itmp];
    std::vector<int> bat = vecb[jtmp];
    const int kKnt = 10e5 + 777;
    int check = 0;
    int index = 0;
    check = kKnt;
    for (int tmp = 0; tmp < lun; ++tmp) {
      if (check > std::max(vat[tmp], bat[tmp])) {
        index = tmp;
        check = std::max(vat[tmp], bat[tmp]);
      }
    }
    std::cout << index + 1 << std::endl;
  }
}

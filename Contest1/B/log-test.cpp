#include <cmath>
#include <iomanip>
#include <iostream>
int main() {
  double n;
  std::cin >> n;
  std::cout << std::setprecision(16) << std::exp(n);
}

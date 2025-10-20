#include <iostream>

int main() {

  for (int a = 0;a < 100; ++a) {
    if (a % 10 == 7 || a % 10 == 3) {
      std::cout << a * a << std::endl;
    }
  }
}

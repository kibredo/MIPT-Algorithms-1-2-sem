#include <cmath>
#include <deque>
#include <iostream>
#include <vector>
const long long cKMaxInt = 1e18;
const long long cKAnsConst = 30'000;

int main() {
  long long the_v = 0;
  long long the_e = 0;
  long long first = 0;
  long long second = 0;
  long long the_w = 0;
  std::cin >> the_v >> the_e;
  std::vector<std::vector<long long>> the_g(
      the_v + 1, std::vector<long long>(the_v + 1, cKMaxInt));
  std::vector<long long> d(the_v + 1, cKMaxInt);
  for (long long tmp = 0; tmp < the_e; ++tmp) {
    std::cin >> first >> second >> the_w; 
    the_g[first][second] = std::min(the_g[first][second], the_w);
  }
  d[1] = 0;
  for (long long k = 0; k < the_v; ++k) {
    for (long long vertex = 1; vertex <= the_v; ++vertex) {
      for (long long next = 1; next <= the_v; ++next) {
        if (next == vertex ||
            std::max(d[next], the_g[next][vertex]) == cKMaxInt) {
          continue;
        }
        d[vertex] = std::min(d[vertex], d[next] + the_g[next][vertex]);
      }
    }
  }
  for (auto iter = d.begin() + 1; iter != d.end(); ++iter) {
    std::cout << (*iter == cKMaxInt ? cKAnsConst : *iter) << " ";
  }
}
#include <cmath>
#include <deque>
#include <iostream>
#include <random>
#include <vector>
std::vector<unsigned> vec(0);
std::mt19937 gen(time(nullptr));
int RandomElement(int start, int finish) {
  std::uniform_int_distribution<> distribution(start, finish);
  return distribution(gen);
}
void Partition(unsigned& kstat,
               unsigned pivot_index, int& start, int& finish, int& issolved) {
  unsigned pivot = vec[pivot_index];
  unsigned tempr = 0;
  int counter = start;
  for (int tmp = start; tmp <= finish; ++tmp) {
    unsigned val = vec[tmp];
    if(val >= pivot) {
      continue;
    } else {
      std::swap(vec[tmp], vec[counter]);
      ++counter;
    }
  }
  int midpoint = 0;
  int midend = 0;
  for (int tmp = start; tmp <= finish; ++tmp) {
    if(vec[tmp] == pivot) {
      midpoint = tmp;
      while(tmp < (int)vec.size() && vec[tmp] == pivot) {
        ++tmp;
      }
      --tmp;
      midend = tmp;
      break;
    }
  }
  if(kstat < midpoint) {
    finish = midpoint - 1;
  } else {
    if(kstat <= midend) {
      issolved = pivot;
    } else {
      start = midend + 1;
      kstat -= midend;
    }
  }
}
int QuickSelect(unsigned k_stat) {
  int checker1 = 0;
  int startp = 0;
  int finishp = (int)vec.size() - 1;
  while (checker1 == 0) {
    int pivot_tmp = RandomElement(startp, finishp);
    Partition(k_stat, pivot_tmp, startp, finishp, checker1);
  }
  return checker1;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  unsigned size = 0;
  std::cin >> size;
  unsigned k_stats = 0;
  std::cin >> k_stats;
  unsigned dinamic_array[2];
  std::cin >> dinamic_array[0];
  std::cin >> dinamic_array[1];
  vec.push_back(dinamic_array[0]);
  vec.push_back(dinamic_array[1]);
  const int kKmodFirst = 123;
  const int kKmodSecond = 45;
  const int kKmodFinal = 10004321;
  for (unsigned tmp = 2; tmp < size; ++tmp) {
    dinamic_array[tmp % 2] = (kKmodSecond * dinamic_array[tmp % 2] +
                              kKmodFirst * dinamic_array[(tmp + 1) % 2]);
    dinamic_array[tmp % 2] %= kKmodFinal;
    vec.push_back(dinamic_array[tmp % 2]);
  }
  std::cout << QuickSelect(k_stats);
}

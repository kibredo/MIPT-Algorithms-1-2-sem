#include <cmath>
#include <deque>
#include <iostream>
#include <random>
#include <vector>
std::mt19937 gen(time(nullptr));
int RandomElement(int start, int finish) {
  std::uniform_int_distribution<> distribution(start, finish);
  return distribution(gen);
}
void Partition(std::vector<unsigned>& vec, unsigned& kstat,
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
  for (int tmp = start; tmp < finish; ++tmp) {
    if(vec[tmp] == pivot) {
      midpoint = tmp;
      while(vec[tmp] == pivot) {
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
      start = midpoint;
    }
  }
}
int QuickSelect(std::vector<unsigned> vect, unsigned k_stat) {
  int checker = 0;
  int startp = 0;
  int finishp = (int)vect.size() - 1;
  while (checker == 0) {
    unsigned temp = (unsigned)vect.size();
    int pivot_tmp = RandomElement(startp, finishp);
    Partition(vect, k_stat, pivot_tmp, startp, finishp, checker);
  }
  return vect[0];
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::vector<unsigned> vect;
  unsigned size = 0;
  std::cin >> size;
  unsigned k_stats = 0;
  std::cin >> k_stats;
  unsigned dinamic_array[2];
  std::cin >> dinamic_array[0];
  std::cin >> dinamic_array[1];
  vect.push_back(dinamic_array[0]);
  vect.push_back(dinamic_array[1]);
  const int kKmodFirst = 123;
  const int kKmodSecond = 45;
  const int kKmodFinal = 10004321;
  for (unsigned tmp = 2; tmp < size; ++tmp) {
    dinamic_array[tmp % 2] = (kKmodSecond * dinamic_array[tmp % 2] +
                              kKmodFirst * dinamic_array[(tmp + 1) % 2]);
    dinamic_array[tmp % 2] %= kKmodFinal;
    vect.push_back(dinamic_array[tmp % 2]);
  }
  std::cout << QuickSelect(vect, k_stats);
}

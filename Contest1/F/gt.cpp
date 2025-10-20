#include <cmath>
#include <iostream>
#include <random>
#include <vector>

const int kModuloFirst = 123;
const int kModuloSecond = 45;
const int kModuloFinal = 10004321;
std::mt19937 gen(time(nullptr));

int RandomElement(int start, int finish) {
  std::uniform_int_distribution<> distribution(start, finish);
  return distribution(gen);
}

void Partition(std::vector<int>& vec, int& kstat, int pivot_index, 
               int& start, int& finish, int& issolved) {
  int pivot = vec[pivot_index];
  int counter = start;
  for (int tmp = start; tmp <= finish; ++tmp) {
    int val = vec[tmp];
    if (val < pivot) {
      std::swap(vec[tmp], vec[counter]);
      ++counter;
    }
  }
  for (int ind = start; ind <= finish; ind++) {
    if (vec[ind] == pivot) {
      std::swap(vec[counter], vec[ind]);
      ++counter;
    }
  }
  int midpoint = 0;
  int midend = 0;
  for (int tmp = start; tmp <= finish; ++tmp) {
    if (vec[tmp] == pivot) {
      midpoint = tmp;
      while (tmp <= finish && vec[tmp] == pivot) {
        ++tmp;
      }
      --tmp;
      midend = tmp;
      break;
    }
  }
  if (kstat < midpoint + 1) {
    finish = midpoint;
  } else {
    if (kstat <= midend + 1) {
      issolved = pivot;
    } else {
      start = midend + 1;
    }
  }
}

int QuickSelect(std::vector<int>& vec, int& kstat) {
  int checker1 = 0;
  int startp = 0;
  int finishp = (int)vec.size() - 1;
  while (checker1 == 0) {
    int pivot_tmp = RandomElement(startp, finishp);
    Partition(vec, kstat, pivot_tmp, startp, finishp, checker1);
  }
  return checker1;
}

int main() {
  std::vector<int> vec(2, 0);
  int kstat = 0;
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int size = 0;
  std::cin >> size;
  std::cin >> kstat;
  std::cin >> vec[0];
  std::cin >> vec[1];
  for (int tmp = 2; tmp < size; ++tmp) {
    vec.push_back(kModuloSecond * vec[tmp - 2] + kModuloFirst * vec[tmp - 1]);
    vec[tmp] %= kModuloFinal;
  }
  std::cout << QuickSelect(vec, kstat);
}

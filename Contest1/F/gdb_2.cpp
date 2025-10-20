#include <cmath>
#include <iostream>
#include <random>
#include <vector>
std::vector<int> vec(0);
int kstat = 0;
std::mt19937 gen(time(nullptr));
int RandomElement(int start, int finish) {
  std::uniform_int_distribution<> distribution(start, finish);
  return distribution(gen);
}
void Partition(int pivot_index, int& start, int& finish, int& issolved) {
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
int QuickSelect() {
  int checker1 = 0;
  int startp = 0;
  int finishp = (int)vec.size() - 1;
  while (checker1 == 0) {
    int pivot_tmp = RandomElement(startp, finishp);
    Partition(pivot_tmp, startp, finishp, checker1);
  }
  return checker1;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int size = 0;
  std::cin >> size;
  std::cin >> kstat;
  int dinamic_array[2];
  std::cin >> dinamic_array[0];
  std::cin >> dinamic_array[1];
  vec.push_back(dinamic_array[0]);
  vec.push_back(dinamic_array[1]);
  const int kKmodFirst = 123;
  const int kKmodSecond = 45;
  const int kKmodFinal = 10004321;
  for (int tmp = 2; tmp < size; ++tmp) {
    dinamic_array[tmp % 2] = (kKmodSecond * dinamic_array[tmp % 2] +
                              kKmodFirst * dinamic_array[(tmp + 1) % 2]);
    dinamic_array[tmp % 2] %= kKmodFinal;
    vec.push_back(dinamic_array[tmp % 2]);
  }
  std::cout << QuickSelect();
}

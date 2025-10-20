#include <iostream>
#include <random>
#include <vector>
std::vector<int> vec;
std::mt19937 gen(time(nullptr));
int MakeRandomNumber(int left, int right) {
  std::uniform_int_distribution<> distribution(left, right - 1);
  return distribution(gen);
}
std::pair<int, int> Partition(int start, int finish, int pivot_index) {
  int pivot = vec[pivot_index];
  int counter = start - 1;
  int number_of_pivots = 0;
  for (int tmp = start; tmp < finish; ++tmp) {
    int val = vec[tmp];
    if (val < pivot) {
      std::swap(vec[tmp], vec[counter + 1]);
      ++counter;
    }
  }
  for (int tmp = start; tmp < finish; ++tmp) {
    if (vec[tmp] == pivot) {
      std::swap(vec[counter + 1], vec[tmp]);
      ++counter;
      ++number_of_pivots;
    }
  }
  return std::make_pair(counter - number_of_pivots, counter);
}
void QuickSort(int left_part_begin, int right_part_end) {
  if (right_part_end - left_part_begin <= 1) {
    return;
  }
  int rnd_index = MakeRandomNumber(left_part_begin, right_part_end);
  int left = Partition(left, right, rnd_index).first + 1;
  int right = Partition(left, right, rnd_index).second + 1;
  QuickSort(left_part_begin, left);
  QuickSort(right, right_part_end);
}
int main() {
  int number_of_elements = 0;
  int var = 0;
  std::cin >> number_of_elements;
  for (int tmp = 0; tmp < number_of_elements; ++tmp) {
    std::cin >> var;
    vec.push_back(var);
  }
  QuickSort(0, number_of_elements);
  int temp = 0;
  while(temp < number_of_elements) {
    std::cout << vec[temp] << " ";
    ++temp;
  }
}

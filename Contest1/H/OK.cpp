#include <iostream>
#include <random>
#include <vector>

std::mt19937 gen(time(nullptr));
std::pair<int, int> Partition(std::vector<int>& vec, int start, int finish,
                              int pivot) {
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
int MakeRandomNumber(int left, int right) {
  std::uniform_int_distribution<> distribution(left, right - 1);
  return distribution(gen);
}
void QuickSort(std::vector<int>& vec, int left_part_begin, int right_part_end) {
  if (right_part_end - left_part_begin > 1) {
    int rnd_index = MakeRandomNumber(left_part_begin, right_part_end);
    int pivot = vec[rnd_index];
    int left_part_end =
        Partition(vec, left_part_begin, right_part_end, pivot).first + 1;
    int right_part_begin =
        Partition(vec, left_part_begin, right_part_end, pivot).second + 1;
    QuickSort(vec, left_part_begin, left_part_end);
    QuickSort(vec, right_part_begin, right_part_end);
  }
}
int main() {
  int number_of_elements = 0;
  std::vector<int> array(0);
  int var = 0;
  std::cin >> number_of_elements;
  for (int tmp = 0; tmp < number_of_elements; ++tmp) {
    std::cin >> var;
    array.push_back(var);
  }
  QuickSort(array, 0, number_of_elements);
  for (auto elem : array) {
    std::cout << elem << " ";
  }
}

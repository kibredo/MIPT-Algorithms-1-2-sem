#include <iostream>
#include <random>
#include <vector>
std::mt19937 gen(time(nullptr));
int MakeRandomNumber(int left, int right) {
  std::uniform_int_distribution<> distribution(left, right - 1);
  return distribution(gen);
}
std::pair<int, int> Partition(std::vector<int>& vec, int start, int finish,
                              int pivot_index) {
  int pivot = vec[pivot_index];
  int counter = start - 1;
  int number_of_pivots = 0;
  for (int tmp = left; tmp < right; tmp++) {
    if (vec[tmp] >= pivot) {
      continue;
    }
    if (vec[tmp] < pivot) {
      std::swap(vec[counter + 1], vec[tmp]);
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
void QuickSort(std::vector<int>& vec, int left_part_begin, int right_part_end) {
  if (right_part_end - left_part_begin > 1) {
    int rnd_index = MakeRandomNumber(left_part_begin, right_part_end);
    int left_part_end =
        Partition(vec, left_part_begin, right_part_end, rnd_index).first + 1;
    int right_part_begin =
        Partition(vec, left_part_begin, right_part_end, rnd_index).second + 1;
    QuickSort(vec, left_part_begin, left_part_end);
    QuickSort(vec, right_part_begin, right_part_end);
  }
}
int main() {
  int number_of_elements = 0;
  int var = 0
  std::cin >> number_of_elements;
  std::vector<int> array(number_of_elements, 0);
  for (int tmp = 0; tmp < number_of_elements; ++tmp) {
    std::cin >> array[tmp];
  }
  QuickSort(array, 0, number_of_elements);
  for (auto elem : array) {
    std::cout << elem << " ";
  }
}

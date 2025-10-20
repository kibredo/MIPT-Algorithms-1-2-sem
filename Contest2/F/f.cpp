#include <iostream>
#include <vector>

const long long kInf = 2e9;

class the_heap {
 public:
  std::vector<std::pair<long long, long long>> heap;
  void GetSiftedUp(std::vector<long long>& index_vec, long long the_index) {
    if (the_index != 1) {
      long long tmp_ind = the_index / 2;
      if (heap[the_index].first < heap[tmp_ind].first) {
        std::swap(index_vec[heap[the_index].second],
                  index_vec[heap[tmp_ind].second]);
        std::swap(heap[the_index], heap[tmp_ind]);
        GetSiftedUp(index_vec, tmp_ind);
      }
    }
  }

  void GetSiftedDown(std::vector<long long>& index_vec, long long the_index) {
    if (2 * the_index < (long long)heap.size()) {
      long long tmp_ind = the_index * 2;
      if (tmp_ind + 1 < (long long)heap.size() &&
          heap[tmp_ind + 1].first < heap[tmp_ind].first) {
        ++tmp_ind;
      }
      if (heap[the_index].first > heap[tmp_ind].first) {
        std::swap(index_vec[heap[the_index].second],
                  index_vec[heap[tmp_ind].second]);
        std::swap(heap[the_index], heap[tmp_ind]);
        GetSiftedDown(index_vec, tmp_ind);
      }
    }
  }

  void GetInserted(std::vector<long long>& index_vec, long long value,
                  long long position) {
    heap.push_back(std::make_pair(value, position));
    long long the_index = (long long)heap.size() - 1;
    index_vec[position] = the_index;
    GetSiftedUp(index_vec, the_index);
  }

  void GetDecreased(std::vector<long long>& index_vec) {
    long long index = 0;
    long long key = 0;
    std::cin >> index;
    std::cin >> key;
    heap[index_vec[index]].first -= key;
    GetSiftedUp(index_vec, index_vec[index]);
  }

  void GetMin() {
    std::cout << heap[1].first << std::endl;
  }

  void GetExtracted(std::vector<long long>& index_vec) {
    std::swap(heap[1], heap[heap.size() - 1]);
    std::swap(index_vec[heap[1].second], index_vec[heap[heap.size() - 1].second]);
    heap.pop_back();
    GetSiftedDown(index_vec, 1);
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  long long quantity = 0;
  std::cin >> quantity;
  the_heap heap;
  heap.heap.push_back(std::make_pair(-kInf, -1));
  long long value = 0;
  std::string input;
  std::vector<long long> index_vec(0);
  index_vec.push_back(1);
  for (long long tmp = 0; tmp < quantity; ++tmp) {
    index_vec.push_back(1);
    std::cin >> input;
    if (input == "insert") {
      std::cin >> value;
      heap.GetInserted(index_vec, value, tmp + 1);
    } else if (input == "decreaseKey") {
      heap.GetDecreased(index_vec);
    } else if (input == "extractMin") {
      heap.GetExtracted(index_vec);
    } else if (input == "getMin") {
      heap.GetMin();
    }
  }
}
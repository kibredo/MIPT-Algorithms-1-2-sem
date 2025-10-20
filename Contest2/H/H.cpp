#include <iostream>
#include <vector>

class the_heap {
 private:
  void GetSilentlyExtracted() {
    std::swap(heap[1], heap[heap.size() - 1]);
    heap.pop_back();
    GetSiftedDown(1);
  }
 public:
  std::vector<int> heap;
  void GetSiftedUp(int the_index) {
    if (the_index != 1) {
      int tmp_ind = the_index / 2;
      if (heap[the_index] < heap[tmp_ind]) {
        std::swap(heap[the_index], heap[tmp_ind]);
        GetSiftedUp(tmp_ind);
      }
    }
  }

  void GetSiftedDown(int the_index) {
    if (2 * the_index < (int)heap.size()) {
      int tmp_ind = the_index * 2;
      if (tmp_ind + 1 < (int)heap.size() && heap[tmp_ind + 1] < heap[tmp_ind]) {
        ++tmp_ind;
      }
      if (heap[the_index] > heap[tmp_ind]) {
        std::swap(heap[the_index], heap[tmp_ind]);
        GetSiftedDown(tmp_ind);
      }
    }
  }

  void GetInserted(int value) {
    heap.push_back(value);
    int the_index = (int)heap.size() - 1;
    GetSiftedUp(the_index);
  }

  void DoTheThing(the_heap& delete_heap) {
    while (heap.size() > 1 && delete_heap.heap.size() > 1 &&
          heap[1] == delete_heap.heap[1]) {
      GetSilentlyExtracted();
      delete_heap.GetSilentlyExtracted();
    }
  }

  void PrintTheAnswer() {
    if (heap.size() == 1) {
      std::cout << "error" << '\n';
    } else {
      std::cout << std::abs(heap[1]) << std::endl;
    }
  }

  void GetMin(the_heap& delete_heap) {
    DoTheThing(delete_heap);
    PrintTheAnswer();
  }

  void GetExtracted(the_heap& delete_heap,
                    the_heap& negative_delete_heap) {
    DoTheThing(delete_heap);
    PrintTheAnswer();
    if (heap.size() > 1) {
      negative_delete_heap.GetInserted((-1) * heap[1]);
      delete_heap.GetInserted(heap[1]);
    }
  }
  void GetCleared() {
    heap.resize(0);
    heap.push_back(0);
  }
  size_t size() const {
    return this->heap.size();
  }
};

void GetMaxExtracted(the_heap& negative_heap,
                     the_heap& negative_delete_heap,
                     the_heap& delete_heap) {
  negative_heap.DoTheThing(negative_delete_heap);
  negative_heap.PrintTheAnswer();
  if (negative_heap.heap. size() > 1) {
    negative_delete_heap.GetInserted(negative_heap.heap[1]);
    delete_heap.GetInserted((-1) * negative_heap.heap[1]);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int quantity = 0;
  std::cin >> quantity;
  the_heap heap;
  the_heap negative_heap;
  the_heap delete_heap;
  the_heap negative_delete_heap;
  heap.heap.push_back(0);
  negative_heap.heap.push_back(0);
  delete_heap.heap.push_back(0);
  negative_delete_heap.heap.push_back(0);
  int value = 0;
  std::string input;
  for (int tmp = 0; tmp < quantity; ++tmp) {
    std::cin >> input;
    if (input == "insert") {
      std::cin >> value;
      std::cout << "ok" << '\n';
      heap.GetInserted(value);
      negative_heap.GetInserted(value * (-1));
    } else if (input == "clear") {
      std::cout << "ok" << '\n';
      heap.GetCleared();
      delete_heap.GetCleared();
      negative_delete_heap.GetCleared();
      negative_heap.GetCleared();
    } else if (input == "extract_min") {
      heap.GetExtracted(delete_heap, negative_delete_heap);
    } else if (input == "get_min") {
      heap.GetMin(delete_heap);
    } else if (input == "get_max") {
      negative_heap.GetMin(negative_delete_heap);
    } else if (input == "extract_max") {
      GetMaxExtracted(negative_heap, negative_delete_heap, delete_heap);
    } else if (input == "size") {
      std::cout << heap.size() - delete_heap.size() << '\n';
    }
  }
}

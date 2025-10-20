#include <iostream>
#include <vector>
const int kInf = 2e9 + 1;

class BinomialHeap;
struct BHNode {
  BHNode* parent = nullptr;
  int rank = 0;
  BHNode* next = nullptr;
  std::vector<BHNode*> children;
  int value = -2;
  int index = -1;
  BHNode(int value, int index) : value(value), index(index) {}
};

void DoTheThing(BHNode*& l_iter, BHNode*& r_iter, BHNode*& l_prev,
                BHNode*& r_prev) {
  while (r_iter != nullptr) {
    while (l_iter != nullptr && l_iter->rank < r_iter->rank) {
      l_prev = l_iter;
      l_iter = l_iter->next;
    }
    if (l_iter == nullptr) {
      break;
    }
    if (l_iter->rank == r_iter->rank) {
      if (l_iter->value == r_iter->value) {
        if (l_iter->index > r_iter->index) {
        } else {
          r_prev = r_iter;
          r_iter = r_iter->next;
          l_iter->children.push_back(r_prev);
          l_iter->rank++;
          r_prev->parent = l_iter;
          r_prev->next = nullptr;
        }
      } else if (l_iter->value > r_iter->value) {
        l_prev->next = r_iter;

      } else {
        r_prev = r_iter;
        r_iter = r_iter->next;
        l_iter->children.push_back(r_prev);
        l_iter->rank++;
        r_prev->parent = l_iter;
        r_prev->next = nullptr;
      }
    } else if (l_iter->rank > r_iter->rank) {
      l_prev->next = r_iter;
      while (r_iter != nullptr && l_iter->rank > r_iter->rank) {
        r_prev = r_iter;
        r_iter = r_iter->next;
      }
      r_prev->next = l_iter;
    }
  }
}

class BinomialHeap {
  public:
  BHNode* head = nullptr;
  BHNode* min_keeper = nullptr;
  void SuckMerge(BinomialHeap& other) {
    if (other.head == nullptr) {
      return;
    }
    if (head == nullptr) {
      std::swap(head, other.head);
      std::swap(min_keeper, other.min_keeper);
      return;
    }
    BHNode* l_iter = head;
    BHNode* r_iter = other.head;
    if (r_iter->rank < l_iter->rank) {
      this->head = r_iter;
      std::swap(l_iter, r_iter);
    }
    BHNode* l_prev = l_iter;
    BHNode* r_prev = r_iter;
    DoTheThing(l_iter, r_iter, l_prev, r_prev);
    if (l_prev->next == nullptr) {
      if (r_iter != nullptr) {
        if (r_iter->rank != l_prev->rank) {
          l_prev->next = r_iter;
        } else {
          while (r_iter != nullptr && r_iter->rank == l_prev->rank) {
            r_prev = r_iter;
            r_iter = r_iter->next;

            l_iter->children.push_back(r_prev);
            l_iter->rank++;
            r_prev->parent = l_iter;
            r_prev->next = nullptr;
          }
        }
      }
    }
    if (other.min_keeper->value < this->min_keeper->value) {
      this->min_keeper = other.min_keeper;
    } else if (other.min_keeper->value == this->min_keeper->value) {
      if (other.min_keeper->index < this->min_keeper->index) {
        this->min_keeper = other.min_keeper;
      }
    }
    other.head = nullptr;
    other.min_keeper = nullptr;
  }

  BHNode* Insert(int value, int index) {
    BHNode* new_tree = new BHNode(value, index);
    BinomialHeap temp_heap;
    temp_heap.head = new_tree;
    temp_heap.min_keeper = new_tree;
    this->SuckMerge(temp_heap);
    return new_tree;
  }

  void ExtractMin() {
    BinomialHeap temp;
    temp.head = min_keeper->children[0];
    temp.min_keeper = min_keeper->children[0];
    for (BHNode* child : min_keeper->children) {
      if (child->value < temp.min_keeper->value) {
        temp.min_keeper = child;
      } else if (child->value == temp.min_keeper->value) {
        if (child->index < temp.min_keeper->index) {
          temp.min_keeper = child;
        }
      }
    }
    this->SuckMerge(temp);
    delete min_keeper;
  }

  int GetMin() const {
    return min_keeper->value;
  }
};

void SwapAdjacentNodes(int unbalanced, int other, std::vector<BHNode*>& i2n) {
  std::swap(i2n[unbalanced], i2n[other]);
  std::swap(i2n[unbalanced]->value, i2n[other]->value);
}
BHNode* SiftUp(BinomialHeap& heap, BHNode* &unbalanced, std::vector<BHNode*>& i2n) {
  while (unbalanced->parent != nullptr) {
    if (unbalanced->value > unbalanced->parent->value) {
      break;
    }
    if (unbalanced->value < unbalanced->parent->value) {
      SwapAdjacentNodes(unbalanced->index, unbalanced->parent->index, i2n);
    } else if (unbalanced->value == unbalanced->parent->value) {
      if (unbalanced->index < unbalanced->parent->index) {
        SwapAdjacentNodes(unbalanced->index, unbalanced->parent->index, i2n);
      }
    }
  }
  return unbalanced;
}
BHNode* SiftDown(BinomialHeap& heap, BHNode* &unbalanced, std::vector<BHNode*>& i2n) {
  while (!unbalanced->children.empty()) {
    BHNode* selected_child = nullptr;
    int children_min = kInf;
    for (auto * child : unbalanced->children) {
      if (child->value < children_min) {
        children_min = child->value;
        selected_child = child;
      }
    }
    if (selected_child == nullptr) {
      break;
    }
    if (selected_child->value < unbalanced->value) {
      SwapAdjacentNodes(unbalanced->index, selected_child->index, i2n);
    } else if (selected_child->value == unbalanced->value) {
      if (selected_child->index < unbalanced->index) {
        SwapAdjacentNodes(unbalanced->index, selected_child->index, i2n);
      }
    }
  }
  return unbalanced;
}

void SetValue(BinomialHeap& heap, std::vector<BHNode*>& i2n, int value, int index) {
  BHNode* node = i2n[index];
  if (value == node->value) {
    return;
  }
  if (value < node->value) {
    node->value = value;
    SiftUp(heap, node, i2n);
  } else {
    node->value = value;
    SiftDown(heap, node, i2n);
  }
}

int main() {
  std::ios_base::sync_with_stdio(true);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int heaps_count;
  int query_count;
  std::cin >> heaps_count;
  std::cin >> query_count;

  std::vector<BinomialHeap> heaps(heaps_count + 1);
  std::vector<BHNode*> index_to_node(1);
  std::vector<int> index_to_heap( 1);
  int index_count = 0;
  for (int i = 0; i < query_count; i++) {
    int type;
    std::cin >> type;
    int target;
    int other;
    int value;
    int index;
    if (type == 0) {
      std::cin >> target;
      std::cin >> value;
      index_count++;
      BHNode* new_node = heaps[target].Insert(value, index_count);
      index_to_node.push_back(new_node);
      index_to_heap.push_back(target);
    } else if (type == 1) {
      std::cin >> target;
      std::cin >> other;
      heaps[target].SuckMerge(heaps[other]);
    } else if (type == 2) {
      std::cin >> index;
      SetValue(heaps[index], index_to_node, -1 * kInf, index);
      heaps[index_to_heap[index]].ExtractMin();
    } else if (type == 3) {
      std::cin >> index;
      std::cin >> value;
      SetValue(heaps[index], index_to_node, value, index);
    } else if (type == 4) {
      std::cin >> target;
      int result = heaps[target].GetMin();
      std::cout << result << '\n';
    } else if (type == 5) {
      std::cin >> target;
      heaps[target].ExtractMin();
    }
  }
  return 0;
}

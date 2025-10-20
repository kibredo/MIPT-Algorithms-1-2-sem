#include <iostream>
#include <vector>

class BinomialHeap;
struct BHNode {
	BHNode* parent = nullptr;
	BinomialHeap* root = nullptr;
	int rank = 0;
	BHNode* next = nullptr;
	std::vector<BHNode*> children;
	int value = -2;
	int index = -1;
	BHNode(int value, int index) : value(value), index(index) {

	}
};

class BinomialHeap {
	friend void SetValue(std::vector<BHNode*>&, int, int);
public:
	BHNode* head = nullptr;
	BHNode* min_keeper = nullptr;
	void SuckMerge(BinomialHeap& other) {
		if (other.head == nullptr) // нечего добавлять
			return;
		if (head == nullptr) {
			std::swap(head, other.head);
			std::swap(min_keeper, other.min_keeper);
			return;
		}
		BHNode* l_iter = head;
		BHNode* r_iter = other.head;
	}

	BHNode* Insert(int value, int index) {
		// TODO
		BHNode* new_heap = new BHNode(value, index);
		std::cout << new_heap->value << std::endl;
		new_heap->value = value;
		std::cout << new_heap->value << std::endl;
		new_heap->index = index;
		return new_heap;
	}

	void ExtractMin() {

	}

	int GetMin() {
		return min_keeper->value;
	}
private:
	BHNode* SiftUp(BHNode *unbalanced) {
		while (unbalanced->parent != nullptr) {
			if (unbalanced->value > unbalanced->parent->value)
				break;
			if (unbalanced->value < unbalanced->parent->value) {
				std::swap(unbalanced->value, unbalanced->parent->value);
				std::swap(unbalanced->index, unbalanced->parent->index);
				unbalanced = unbalanced->parent;
			} else if (unbalanced->value == unbalanced->parent->value) {
				if (unbalanced->index < unbalanced->parent->index) {
					std::swap(unbalanced->value, unbalanced->parent->value);
					std::swap(unbalanced->index, unbalanced->parent->index);
					unbalanced = unbalanced->parent;
				}
			}
		}
		return unbalanced;
	}
	BHNode* SiftDown(BHNode *unbalanced) {
		while (!unbalanced->children.empty()) {
			BHNode* selected_child = nullptr;
			int children_min = 2000000003;
			for (auto child : unbalanced->children) { // search min node
				 if (child->value < children_min) {
					 children_min = child->value;
					 selected_child = child;
				 }
			}
			if (selected_child == nullptr)
				break;
			if (selected_child->value == unbalanced->value) {
				std::swap(unbalanced->value, selected_child->value);
				std::swap(unbalanced->index, selected_child->index);
				unbalanced = selected_child;
			} else if (selected_child->value == unbalanced->value) {
				if (selected_child->index < unbalanced->index) {
					std::swap(unbalanced->value, selected_child->value);
					std::swap(unbalanced->index, selected_child->index);
					unbalanced = selected_child;
				}
			}
		}
		return unbalanced;
	}
};

void UpdateMin(int &min, BHNode* &node,
	       const int new_min, BHNode *const new_node) {
	if (new_min < min) {
		min = new_min;
		node = new_node;
	}
}

void SetValue(std::vector<BHNode*>& index_to_node, int value, int index) {
	BHNode* node = index_to_node[index];
	if (value == node->value)
		return;
	if (value < node->value) {
		node->value = value;
		BHNode* new_pos = node->root->SiftUp(node);
		index_to_node[index] = new_pos;
	} else {
		node->value = value;
		BHNode* new_pos = node->root->SiftDown(node);
		index_to_node[index] = new_pos;
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
	std::vector<BHNode*> index_to_node(heaps_count + 1);

	int min = 2000000000;
	BHNode* min_keeper = nullptr;

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
			BinomialHeap new_heap;
			/*
			heaps[target].Insert(value,index_count);
			index_to_node[index_count] = new_node;
			UpdateMin(min, min_keeper, value, new_node);
			 */
		} else if (type == 1) {
			std::cin >> target;
			std::cin >> other;
			heaps[target].SuckMerge(heaps[other]);
		} else if (type == 2) {
			std::cin >> index;
			SetValue(index_to_node, -2000000001, index);
			index_to_node[index]->root->ExtractMin();
			// TODO check
			delete index_to_node[index];
		} else if (type == 3) {
			std::cin >> index;
			std::cin >> value;
			SetValue(index_to_node, value, index);
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

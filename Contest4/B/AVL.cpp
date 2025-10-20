#include <iostream>

struct AVLVertex {
  AVLVertex* left = nullptr;
  AVLVertex* right = nullptr;
  AVLVertex* pred = nullptr;
  int value;
  int hight = 1;
  AVLVertex& operator=(const AVLVertex&) = default;
};

class AVLTree { 
 private:
  AVLVertex* root; 
 public: 
  AVLTree(){ 
      root = nullptr; 
  } 
  void GetInserted(int data);
  viod GetSelfBalanced(AVLVertex* vertex);
};

void AVLTree::GetInserted(int val) {
  AVLVertex* new_one = new AVLVertex;
  new_one->value = val;
  if (root == nullptr) {
    root = new_one;
    return;
  }
  AVLVertex* current = root;
  AVLVertex* old = nullptr;
  while (true) {
    old = current;
    if (val < current->value) {
      current = current->left;
      if (current == nullptr) {
        old->left = new_one;
        new_one->pred = old;
        break;
      }
    } else {
      current = current->right;
      if (current == nullptr) {
        old->right = new_one;
        new_one->pred = old;
        break;
      }
    }
  }
  this->GetBalanced(new_one);
}

int hight(AVLVertex* vertex) {
  if (vertex == nullptr) {
    return 0;
  }
  return vertex->height;
}

AVLVertex* rightRotate(AVLVertex* y) {
  AVLVertex* x = y->left;
  AVLVertex* T2 = x->right;
  x->right = y;
  y->left = T2;
  y->hight = std::max(hight(y->left), hight(y->right)) + 1;
  x->hight = std::max(hight(x->left), hight(x->right)) + 1;
  return x;
}

AVLVertex* leftRotate(AVLVertex* x) {
  AVLVertex* y = x->right;
  AVLVertex* T2 = y->left;
  y->left = x;
  x->right = T2;
  x->hight = std::max(hight(x->left), hight(x->right)) + 1;
  y->hight = std::max(hight(y->left), hight(y->right)) + 1;
  return y;
}

int FeelTheDifference(AVLVertex* N) {
  if (N == nullptr) {
    return 0;
  }
  return hight(N->left) - hight(N->right);
}

int main() {
  AVLTree tree;
  int quant = 0;
  std::string operation;
  int val;
  std::cin >> quant;
  AVLVertex* root = nullptr;
  for (int tmp = 0; tmp < quant; ++tmp) {
    std::cin >> operation;
    if (operation == "+") {
      std::cin >> val;
      tree.GetInserted(val);
    } else {
      std::cin >> val;
    }
  }
}

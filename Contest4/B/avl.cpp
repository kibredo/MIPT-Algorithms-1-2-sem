#include <bits/stdc++.h>

const int kMod = 1e9;
struct Node {
  int key;
  int height;
  Node* left;
  Node* right;
  Node(int key) : key(key), height(1), left(nullptr), right(nullptr) {}
};

void Delete(Node* ver) {
  if (ver == nullptr) {
    return;
  }
  Delete(ver->left);
  Delete(ver->right);
  delete ver;
}
int BalanceFactor(Node* ver) {
  int hr = ver->right != nullptr ? ver->right->height : 0;
  int hl = ver->left != nullptr ? ver->left->height : 0;
  return hr - hl;
}

void FixHeight(Node* ver) {
  int hr = ver->right != nullptr ? ver->right->height : 0;
  int hl = ver->left != nullptr ? ver->left->height : 0;
  ver->height = (hl > hr ? hl : hr) + 1;
}

Node* RotateRight(Node* ver) {
  Node* son = ver->left;
  ver->left = son->right;
  son->right = ver;
  FixHeight(ver);
  FixHeight(son);
  return son;
}

Node* RotateLeft(Node* ver) {
  Node* son = ver->right;
  ver->right = son->left;
  son->left = ver;
  FixHeight(ver);
  FixHeight(son);
  return son;
}

Node* Balance(Node* ver) {
  FixHeight(ver);
  if (BalanceFactor(ver) == 2) {
    if (BalanceFactor(ver->right) < 0) {
      ver->right = RotateRight(ver->right);
    }
    return RotateLeft(ver);
  }
  if (BalanceFactor(ver) == -2) {
    if (BalanceFactor(ver->left) > 0) {
      ver->left = RotateLeft(ver->left);
    }
    return RotateRight(ver);
  }
  return ver;
}

Node* Insert(Node* ver, int val) {
  if (ver == nullptr) {
    ver = new Node(val);
    return ver;
  }
  if (val < ver->key) {
    ver->left = Insert(ver->left, val);
  } else {
    ver->right = Insert(ver->right, val);
  }
  return Balance(ver);
}

Node* FindMin(Node* ver) {
  return ver == nullptr ? ver : ver->left != nullptr ? FindMin(ver->left) : ver;
}

Node* RemoveMin(Node* ver) {
  if (ver == nullptr) {
    return ver;
  }
  if (ver->left == nullptr) {
    return ver->right;
  }
  ver->left = RemoveMin(ver->left);
  return Balance(ver);
}

Node* Remove(Node* ver, int val) {
  if (ver == nullptr) {
    return ver;
  }
  if (val < ver->key) {
    ver->left = Remove(ver->left, val);
  } else if (val > ver->key) {
    ver->right = Remove(ver->right, val);
  } else {
    Node* left_son = ver->left;
    Node* right_son = ver->right;
    delete ver;
    if (right_son != nullptr) {
      return left_son;
    }
    Node* min = FindMin(right_son);
    min->right = RemoveMin(right_son);
    min->left = left_son;
    return Balance(min);
  }
  return Balance(ver);
}

int Next(Node* ver, int val, int cnt = -1) {
  if (ver == nullptr) {
    return cnt;
  }
  if (val <= ver->key) {
    return Next(ver->left, val,
                (cnt == -1 ? ver->key : std::min(cnt, ver->key)));
  }
  return Next(ver->right, val, cnt);
}

int main() {
  int number;
  std::cin >> number;
  std::vector<std::pair<char, int>> query(number);
  Node* tree = nullptr;
  for (int ind = 0; ind < number; ind++) {
    std::cin >> query[ind].first >> query[ind].second;
    if (query[ind].first == '?') {
      query[ind].second = Next(tree, query[ind].second);
      std::cout << query[ind].second << '\n';
    } else {
      if (ind - 1 >= 0 && query[ind - 1].first == '?') {
        tree = Insert(tree, (query[ind].second + query[ind - 1].second) % kMod);
      } else {
        tree = Insert(tree, query[ind].second);
      }
    }
  }
  Delete(tree);
}


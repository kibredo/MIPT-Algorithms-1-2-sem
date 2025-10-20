#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

void PushMin(std::stack<int>& help_hat, int element) {
    int counter = 0;
  while (!help_hat.empty() && element < help_hat.top()) {
    help_hat.pop();
    ++counter;
  }
  for (int tmp = 0; tmp < counter; ++ tmp) {
    help_hat.push(element);
  }
  help_hat.push(std::min(help_hat.top(), element));
}
void GetEnqueued(std::queue<int>& hat, std::stack<int>& help_hat,
                 int& iqlevel) {
  hat.push(iqlevel);
  if (help_hat.empty()) {
    help_hat.push(iqlevel);
  } else {
    PushMin(help_hat, iqlevel);
  }
  std::cout << "ok" << '\n';
}

void GetDequeued(std::queue<int>& hat, std::stack<int>& help_hat) {
  if (hat.empty()) {
    std::cout << "error" << '\n';
  } else {
    std::cout << hat.front() << '\n';
    hat.pop();
    help_hat.pop();
  }
}

void GetFronted(std::queue<int>& hat) {
  if (hat.empty()) {
    std::cout << "error";
  } else {
    std::cout << hat.front();
  }
  std::cout << '\n';
}

void GetCleared(std::queue<int>& hat, std::stack<int>& help_hat) {
  while (!hat.empty()) {
    hat.pop();
    help_hat.pop();
  }
  std::cout << "ok" << '\n';
}

int main() {
  std::queue<int> hat;
  std::stack<int> help_hat;
  std::string input;
  int iqlevel = 0;
  int number_of_operations = 0;
  std::cin >> number_of_operations;
  while (number_of_operations != 0) {
    std::cin >> input;
    --number_of_operations;
    if (input == "enqueue") {
      std::cin >> iqlevel;
      GetEnqueued(hat, help_hat, iqlevel);
    }
    if (input == "dequeue") {
      GetDequeued(hat, help_hat);
    }
    if (input == "front") {
      GetFronted(hat);
    }
    if (input == "size") {
      std::cout << hat.size() << '\n';
    }
    if (input == "clear") {
      GetCleared(hat, help_hat);
    }
    if (input == "min") {
      if (hat.empty()) {
        std::cout << "error" << '\n';
      } else {
        std::cout << help_hat.top() << '\n';
      }
    }
  }
}
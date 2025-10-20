#include <deque>
#include <iostream>
#include <queue>
#include <string>
void GetEnqueued(std::queue<int>& hat, std::deque<int>& help_hat,
                 int& iqlevel) {
  std::size_t size = help_hat.size();
  while (size > 0) {
  int x = q.front();
  help_hat.pop();
  --size;
  help_hat.push(x);
  if (x < min_value) {
    min_value = x;
  }
}
  std::cout << "ok" << '\n';
}

void GetDequeued(std::queue<int>& hat, std::deque<int>& help_hat) {
  if (hat.empty()) {
    std::cout << "error" << '\n';
  } else {
    std::cout << hat.front() << '\n';
    hat.pop();
    help_hat.pop_front();
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

void GetCleared(std::queue<int>& hat, std::deque<int>& help_hat) {
  while (!hat.empty()) {
    hat.pop();
    help_hat.pop_front();
  }
  std::cout << "ok" << '\n';
}

int main() {
  std::queue<int> hat;
  std::queue<int> help_hat;
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
        std::cout << help_hat.back() << '\n';
      }
    }
  }
}

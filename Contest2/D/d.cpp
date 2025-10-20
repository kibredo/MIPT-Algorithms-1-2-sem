#include <iostream>
#include <stack>
#include <string>

class the_hat {
 public:
  std::stack<int> hat;
  void MoveStackElements(the_hat& help_hat,
                         the_hat& extra_hat,
                         the_hat& extra_help_hat) {
    while (!hat.empty()) {
      extra_hat.hat.push(hat.top());
      if (extra_help_hat.hat.empty()) {
        extra_help_hat.hat.push(hat.top());
      } else {
        extra_help_hat.hat.push(std::min(hat.top(), extra_help_hat.hat.top()));
      }
      hat.pop();
      help_hat.hat.pop();
    }
  }

  void GetEnqueued(the_hat& help_hat, int& iqlevel) {
    hat.push(iqlevel);
    if (help_hat.hat.empty()) {
      help_hat.hat.push(iqlevel);
    } else {
      help_hat.hat.push(std::min(help_hat.hat.top(), iqlevel));
    }
    std::cout << "ok" << '\n';
  }

  void GetDequeued(the_hat& help_hat, the_hat& extra_hat, the_hat& extra_help_hat) {
    if (hat.empty() && extra_hat.hat.empty()) {
      std::cout << "error" << '\n';
    } else {
      if (extra_hat.hat.empty()) {
        MoveStackElements(help_hat, extra_hat, extra_help_hat);
      }
      std::cout << extra_hat.hat.top() << '\n';
      extra_hat.hat.pop();
      extra_help_hat.hat.pop();
    }
  }

  void GetFronted(the_hat& help_hat, the_hat& extra_hat,
                  the_hat& extra_help_hat) {
    if (hat.empty() && extra_hat.hat.empty()) {
      std::cout << "error";
    } else {
      if (extra_hat.hat.empty()) {
        MoveStackElements(help_hat, extra_hat, extra_help_hat);
      }
      std::cout << extra_hat.hat.top();
    }
    std::cout << '\n';
  }

  void GetCleared(the_hat& help_hat, the_hat& extra_hat,
                  the_hat& extra_help_hat) {
    while (!hat.empty()) {
      hat.pop();
      help_hat.hat.pop();
    }
    while (!extra_hat.hat.empty()) {
      extra_hat.hat.pop();
      extra_help_hat.hat.pop();
    }
    std::cout << "ok" << '\n';
  }
  size_t size() const {
    return this->hat.size();
  }
};

void GetMin(the_hat& help_hat, the_hat& extra_help_hat) {
    if (extra_help_hat.hat.empty() && help_hat.hat.empty()) {
      std::cout << "error" << '\n';
    }
    if (!extra_help_hat.hat.empty() && help_hat.hat.empty()) {
      std::cout << extra_help_hat.hat.top() << '\n';
    }
    if (extra_help_hat.hat.empty() && !help_hat.hat.empty()) {
      std::cout << help_hat.hat.top() << '\n';
    }
    if (!extra_help_hat.hat.empty() && !help_hat.hat.empty()) {
      std::cout << std::min(help_hat.hat.top(), extra_help_hat.hat.top()) << '\n';
    }
  }

int main() {
  the_hat hat;
  the_hat help_hat;
  the_hat extra_hat;
  the_hat extra_help_hat;
  std::string input;
  int iqlevel = 0;
  int number_of_operations = 0;
  std::cin >> number_of_operations;
  for (int tmp = 0; tmp < number_of_operations; ++tmp) {
    std::cin >> input;
    if (input == "enqueue") {
      std::cin >> iqlevel;
      hat.GetEnqueued(help_hat, iqlevel);
    }
    if (input == "dequeue") {
      hat.GetDequeued(help_hat, extra_hat, extra_help_hat);
    }
    if (input == "front") {
      hat.GetFronted(help_hat, extra_hat, extra_help_hat);
    }
    if (input == "size") {
      std::cout << hat.size() + extra_hat.size() << '\n';
    }
    if (input == "clear") {
      hat.GetCleared(help_hat, extra_hat, extra_help_hat);
    }
    if (input == "min") {
      GetMin(help_hat, extra_help_hat);
    }
  }
}
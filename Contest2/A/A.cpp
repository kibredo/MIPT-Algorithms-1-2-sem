#include <iostream>
#include <map>
#include <stack>
#include <string>
const char kFirstOpen = '(';
const char kFirstClose = ')';
const char kSecondOpen = '{';
const char kSecondClose = '}';
const char kThirdOpen = '[';
const char kThirdClose = ']';
std::map<char, char> scope_connection;
bool GetScopeType(char scope) {
  return scope == '(' || scope == '{' || scope == '[';
}
void MakeFirstCheck(std::stack<char>& scope_stack, bool& check, char scope) {
  if (scope_stack.empty()) {
    check = false;
  } else {
    if (scope_stack.top() == scope) {
      scope_stack.pop();
    } else {
      check = false;
    }
  }
}
int main() {
  scope_connection[kFirstOpen] = kFirstClose;
  scope_connection[kSecondOpen] = kSecondClose;
  scope_connection[kThirdOpen] = kThirdClose;
  bool checker = true;
  std::stack<char> temp_stack;
  std::string input;
  std::cin >> input;
  for (size_t tmp = 0; checker && tmp < input.size(); ++tmp) {
    if (!GetScopeType(input[tmp])) {
      MakeFirstCheck(temp_stack, checker, input[tmp]);
    } else {
      temp_stack.push(scope_connection[input[tmp]]);
    }
  }
  if (checker && temp_stack.empty()) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}

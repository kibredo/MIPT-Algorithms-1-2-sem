#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

bool GetDFSed(int node, const std::vector<std::vector<int>>& graph,
              std::vector<int>& colors, std::stack<int>& the_stack) {
  colors[node] = 1;
  the_stack.push(node);
  size_t tmp = 0;
  while (tmp < graph[node].size()) {
    int neighbor = graph[node][tmp];
    if (colors[neighbor] == 0) {
      if (GetDFSed(neighbor, graph, colors, the_stack)) {
        return true;
      }
    } else if (colors[neighbor] == 1) {
      the_stack.push(neighbor);
      return true;
    }
    ++tmp;
  }
  colors[node] = 2;
  if (!the_stack.empty() && the_stack.top() == node) {
    the_stack.pop();
  }
  return false;
}

int main() {
  int the_v = 0;
  int the_e = 0;
  std::cin >> the_v >> the_e;
  int u_tmp = 0;
  int v_tmp = 0;
  std::vector<std::vector<int>> graph(the_v + 1);
  for (int tmp = 0; tmp < the_e; ++tmp) {
    std::cin >> u_tmp >> v_tmp;
    graph[u_tmp].push_back(v_tmp);
  }
  std::vector<int> colors(the_v + 1, 0);
  std::stack<int> the_stack;
  bool cycle_exists = false;
  int tmp = 1;
  while (tmp <= the_v) {
    if (colors[tmp] == 0 && GetDFSed(tmp, graph, colors, the_stack)) {
      cycle_exists = true;
      break;
    }
    ++tmp;
  }
  if (cycle_exists) {
    std::cout << "YES\n";
    std::stack<int> ans;
    int finish = the_stack.top();
    while (!the_stack.empty()) {
      ans.push(the_stack.top());
      the_stack.pop();
      if (ans.top() == finish && ans.size() > 1) {
        break;
      }
    }
    while (ans.size() > 1) {
      std::cout << ans.top() << " ";
      ans.pop();
    }
  } else {
    std::cout << "NO\n";
  }
}

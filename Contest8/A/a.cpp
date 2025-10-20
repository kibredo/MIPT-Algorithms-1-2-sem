#include <deque>
#include <iostream>
#include <vector>
const size_t cKMagicAnswer = 2009000999;

struct Node {
  size_t vertex = 0;
  size_t dist = 0;
  Node(size_t the_u, size_t dist) : vertex(the_u), dist(dist) {}
};

struct Edge {
  size_t finish = 0;
  size_t weight = 0;
  Edge(size_t the_u, size_t the_w) : finish(the_u), weight(the_w) {}
};

void GetDistanses(size_t start, const std::vector<std::vector<Edge>>& the_g,
                  std::vector<size_t>& ans) {
  std::deque<Node> queue;
  queue.push_front(Node(start, 0));
  ans[start] = 0;
  while (!queue.empty()) {
    auto current = queue.back();
    queue.pop_back();
    if (current.dist <= ans[current.vertex]) {
      for (const auto& edge : the_g[current.vertex]) {
        auto dist = current.dist + edge.weight;
        if (dist < ans[edge.finish]) {
          ans[edge.finish] = dist;
          queue.push_front(Node(edge.finish, dist));
        }
      }
    }
  }
}

int main() {
  size_t the_q = 0;
  size_t the_v = 0;
  size_t the_e = 0;
  size_t first = 0;
  size_t second = 0;
  size_t start = 0;
  size_t the_w = 0;
  std::cin >> the_q;
  for (size_t tmp = 0; tmp < the_q; ++tmp) {
    std::cin >> the_v >> the_e;
    std::vector<std::vector<Edge>> the_g(the_v);
    for (size_t tmp = 0; tmp < the_e; ++tmp) {
      std::cin >> first >> second >> the_w;
      the_g[first].push_back(Edge(second, the_w));
      the_g[second].push_back(Edge(first, the_w));
    }
    std::cin >> start;
    std::vector<size_t> ans(the_v, cKMagicAnswer);
    GetDistanses(start, the_g, ans);
    ans[start] = 0;
    for (size_t tmp = 0; tmp < the_v; ++tmp) {
      std::cout << ans[tmp] << '\n';
    }
  }
}

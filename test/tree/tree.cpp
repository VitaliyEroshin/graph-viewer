#include <iostream>
#include <vector>
#include "viewer.hpp"

TreeMap tm;

void dfs(const std::vector<size_t> graph[], size_t n, size_t x) {
  for (auto &y : graph[x]) {
    tm.addEdge(x, y);
    dfs(graph, n, y);
  }
}

int main() {
  size_t n;
  std::cin >> n;
  assert(n > 0);
  std::vector<size_t> graph[n];
  size_t root = 0;
  for (size_t i = 0; i < n - 1; ++i) {
    size_t x, y;
    std::cin >> x >> y;
    assert(x > 0 && x <= n);
    assert(y > 0 && y <= n);

    --x;
    --y;
    graph[x].push_back(y);
  }

  dfs(graph, n, root);
  tm.show();
}
#include "viewer.hpp"

void TreeMap::addEdge(size_t parent, size_t son) {
  while (std::max(son, parent) >= _rawGraph.size()) {
    _rawGraph.push_back(std::vector<size_t>());
  }

  _rawGraph[parent].push_back(son);
}

void TreeMap::show() {
  Vertex root = buildRoot(_root);
  size_t level = 0;
  size_t padding = 0;
  
  std::queue<Vertex*> bfs;
  std::queue<size_t> basePadding;
  bfs.push(&root);
  basePadding.push(0);
  
  std::vector<std::string> representation;

  while (!bfs.empty()) {
    Vertex* x = bfs.front();
    size_t base = basePadding.front();

    basePadding.pop();
    bfs.pop();

    bool straight = false;
    if (x->level != level) {
      level = x->level;
      padding = 0;
      straight = true;
    }

    size_t xaxis = level * 3;
    size_t yaxis = (padding + base) * 3;

    if (representation.size() <= xaxis) {
      representation.resize(xaxis + 1);
    }

    if (representation[xaxis].size() <= yaxis) {
      size_t length = yaxis + 1 - representation[xaxis].size();
      representation[xaxis] += std::string(length, ' ');
    }

    representation[xaxis][yaxis] = '0' + x->label;
    if (level != 0) {
      for (size_t j = 1; j <= 3; ++j) {
        if (representation[xaxis - j].size() <= yaxis) {
          size_t length = yaxis + 1 - representation[xaxis - j].size();
          representation[xaxis - j] += std::string(length, ' ');
        }
      }

      representation[xaxis - 1][yaxis] = '|';
      representation[xaxis - 2][yaxis] = straight ? '|' : '\\';
      if (!straight) {
        for (size_t i = yaxis - 1; i >= 0 && representation[xaxis - 3][i] == ' '; --i) {
          representation[xaxis - 3][i] = '_';
        }
      }
    }
    
    base += padding;
    padding += x->size;

    for (auto &y : x->children) {
      bfs.push(&y);
      basePadding.push(base);
    }
  }

  for (auto &row : representation) {
    std::cout << row << '\n';
  }
}

TreeMap::Vertex TreeMap::buildRoot(size_t root, size_t level) {
  Vertex vertex(root, level, 0);
  bool leaf = true;
  for (auto &y : _rawGraph[root]) {
    leaf = false;
    vertex.children.push_back(buildRoot(y, level + 1));
    vertex.size += vertex.children.back().size;
  }
  if (leaf)
    vertex.size += 1;
  return vertex;
}
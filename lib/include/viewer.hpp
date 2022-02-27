#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <queue>

class TreeMap {
public:
  void addEdge(size_t parent, size_t son);   
  void show();
  void setRoot(size_t root);

private:
  struct Vertex {
    size_t label;
    size_t level;
    size_t size;

    std::vector<Vertex> children;

    Vertex(size_t label, size_t level, size_t size): label(label), level(level), size(size) {}
  };

  size_t _root = 0;
  std::vector<std::vector<size_t>> _rawGraph; 

  Vertex buildRoot(size_t root, size_t level = 0);
};
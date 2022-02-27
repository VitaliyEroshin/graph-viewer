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
    size_t x;
    size_t level;
  };

  size_t root = 0;
  std::vector<std::vector<size_t>> graph; 
};
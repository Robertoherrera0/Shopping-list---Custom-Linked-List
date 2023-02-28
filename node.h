#ifndef NODE_H
#define NODE_H
#include <iostream>

template <class T>
class Node {
 public:
  T data;
  Node* next;

  Node(T data) : next(nullptr), data(data){};
};
#endif
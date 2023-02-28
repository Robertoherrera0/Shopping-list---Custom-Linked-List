#ifndef ITERATOR_H
#define ITERATOR_H
#include <iostream>
#include "node.h"

template <class T>
class Iterator {
 public:
  Node<T>* prev;
  Node<T>* node;

  bool end() {
    if (node == NULL) {
      return true;
    } else {
      return false;
    }
  }

  T* operator->() {
    T* ptr = &node->data;
    return ptr;
  }

  Iterator<T> operator++(int) {
    prev = node;
    node = node->next;

    return *this;
  }
};

#endif

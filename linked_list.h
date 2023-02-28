#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "iterator.h"
#include "node.h"

template <class T>
class LinkedList {
 public:
  Node<T>* head;

  LinkedList<T>() { head = NULL; }

  Iterator<T> begin() {
    Iterator<T> it;
    it.node = head;
    it.prev = NULL;
    return it;
  }

  void insert_at_head(Iterator<T>& it, T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = NULL;
    if (it.node == head) {
      newNode->next = head;
      head = newNode;
    }
  }

  void insert(Iterator<T>& it, T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = NULL;
    if (head == NULL) {
      head = newNode;
      it.node = head;
      return;
    } else if (it.node == NULL) {
      it.prev->next = newNode;
      it.node = newNode;
    } else if (it.node->next != NULL) {
      newNode->next = it.node->next;
      it.node->next = newNode;
    } else {
      it.prev = it.node;
      it.prev->next = newNode;
      it.node = newNode;
    }
  }

  Iterator<T> erase(Iterator<T> it) {
    if (it.prev == NULL) {
      head = it.node->next;
      it.node = head;
    } else if (it.node == head && it.node->next != NULL) {
      it.node = it.node->next;
      head = it.node;
    } else {
      it.prev->next = it.node->next;
      it.node->next = nullptr;
      it.node = it.prev->next;
    }
    return it;
  }
};
#endif

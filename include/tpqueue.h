// Copyright 2022 NNTU-CS
#pragma once
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <iostream>

template<typename T>
class TPQueue {
 private:
  struct Item {
    T data;
    Item* next;
  };
  Item* head, * tail;
  Item* create(const T& data) {
    Item* item = new Item;
    item->data = data;
    item->next = nullptr;
    return item;
  }

 public:
  TPQueue(): head(nullptr), tail(nullptr) {}
  void print() {
    Item* temp = head;
    std::cout << "Queue:" << std::endl;
    while (temp) {
      std::cout << temp->data.ch << " ";
      temp = temp->next;
    }
    std::cout << std::endl;
  }
  void push(const T& data) {
    Item* item = create(data);
    if (!head) {
      head = tail = item;
    } else {
    if (item->data.prior > head->data.prior) {
      item->next = head;
      head = item;
    } else {
      Item* temp = head;
      while (temp->next && item->data.prior < temp->next->data.prior)
        temp = temp->next;
      item->next = temp->next;
      temp->next = item;
      if (!item->next)
      tail = item;
      }
    }
  }

  T pop() {
    if (head) {
      if (head->next) {
        T item = head->data;
        head = head->next;
        return item;
      } else {
        T item = head->data;
        head = tail = nullptr;
        return item;
      }
    } else {
        return head->data;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_

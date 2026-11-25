#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class Node {
 public:
  int data;
  Node* prev;
  Node* next;
  Node();
};

class LinkedList {
 private:
  Node* head;
  Node* tail;

 public:
  LinkedList();
  ~LinkedList();
  void append(int data);
  void removeMiddle();
  void pop();
  void insertAfter(int data, int afterData);
  void insertBefore(int data, int beforeData);
  int getCount();
  int getDataByIndex(int index);
  void display();
};

#endif
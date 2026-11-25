#include "linkedlist.h"

#include <iostream>
using namespace std;

Node::Node() {
  next = nullptr;
  prev = nullptr;
  data = 0;
}

LinkedList::LinkedList() {
  head = nullptr;
  tail = nullptr;
}

LinkedList::~LinkedList() {
  Node* current = head;
  while (current != nullptr) {
    Node* temp = current;
    current = current->next;
    delete temp;
  }
  head = nullptr;
  tail = nullptr;
}

void LinkedList::append(int data) {
  Node* current = new Node;
  current->data = data;

  if (head == nullptr && tail == nullptr) {
    head = current;
    tail = current;
  } else {
    tail->next = current;
    current->prev = tail;
    tail = current;
  }
}

// Just a thought that came to my mind while experimenting
// void LinkedList::removeMiddle() {
//   if (head == nullptr || head->next == nullptr || head->next->next ==
//   nullptr) {
//     return;
//   }
//   Node* temp = head->next;  // node 2
//   // dlw2ti ana law 3ndi 3 pants 1 <-> 2 <-> 3 <->  w 3yza a delete 2 fa
//   hahotha
//   // fe temp then i will change head-> next to point on the tail and
//   tail->prev
//   // to point to head
//   temp->prev->next = temp->next;  // 1->next => 3
//   temp->next->prev = temp->prev;  // 3->prev => 1
//   delete temp;
// }

void LinkedList::pop() {
  if (head == nullptr) {
    return;
  }
  Node* temp = tail;
  if (head == tail) {
    head = nullptr;
    tail = nullptr;
  } else {
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
  }
}

void LinkedList::insertAfter(int data, int afterData) {
  if (head == nullptr) {
    return;
  }
  // 3yza adef pant after pants 2 but there already pant after that so i want to
  // change the place of pants 3 and put my pants in 1 <-> 2 (3zya adef b3do)
  // <->  3
  Node* temp = head;  // bas ana msh 3rfa howa hykhatr ydeef b3d anhi
  while (temp != nullptr && temp->data != afterData) {
    temp = temp->next;
  }
  if (temp == nullptr) {
    return;
  }
  Node* current = new Node;
  current->data = data;
  current->prev = temp;
  current->next = temp->next;
  if (temp->next != nullptr) {   // in case 3yza add b3d last node
    temp->next->prev = current;  // 3->prev
  } else {
    tail = current;
  }
  temp->next = current;
}
void LinkedList::insertBefore(int data, int beforeData) {
  // 1 <->(insert before) 2 <-> 3
  if (head == nullptr) {
    return;
  }
  Node* temp = head;
  while (temp != nullptr && temp->data != beforeData) {
    temp = temp->next;
  }
  if (temp == nullptr) {
    return;
  }
  Node* current = new Node;
  current->data = data;
  current->prev = temp->prev;
  current->next = temp;

  if (temp->prev != nullptr) {
    temp->prev->next = current;
  } else {
    head = current;
  }
  temp->prev = current;
}

int LinkedList::getCount() {
  Node* temp = head;
  int count = 0;
  while (temp != nullptr) {
    count++;
    temp = temp->next;
  }
  return count;
}

int LinkedList::getDataByIndex(int index) {
  if (index < 0) {
    return -1;
  }
  Node* temp = head;
  int currentIndex = 0;
  while (temp != nullptr && currentIndex < index) {
    temp = temp->next;
    currentIndex++;
  }
  if (temp == nullptr) {
    return -1;
  }
  return temp->data;
}

void LinkedList::display() {
  if (head == nullptr) {
    return;
  }
  Node* temp = head;
  while (temp != nullptr) {
    cout << temp->data;
    if (temp->next != nullptr) {
      cout << "<->";
    }
    temp = temp->next;
  }
}

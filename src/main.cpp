#include <iostream>

#include "linkedlist.h"
using namespace std;

int main() {
  LinkedList l;
  l.append(10);
  l.append(20);
  l.append(40);
  l.display();
  cout << "\n======================\n";
  l.insertAfter(30, 20);
  l.display();
  cout << "\n======================\n";
  l.insertBefore(5, 10);
  l.display();
  cout << "\n======================\n";
  cout << "count: " << l.getCount();
  cout << "\n======================\n";
  cout << "data of index 3: " << l.getDataByIndex(3) << endl;
}

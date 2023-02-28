#include <iostream>
#include <string>
#include <vector>
#include "iterator.h"
#include "linked_list.h"
#include "node.h"

// Step 1. create a Grocery class that holds an isle and a name
class Grocery {
 public:
  int aisle;
  std::string name;
  Grocery(int aisle, std::string name) {
    this->aisle = aisle;
    this->name = name;
  }
};

int main() {
  // Step 2. Construct a std::list<Grocery>

  LinkedList<Grocery> groceries;
  Iterator<Grocery> it;

  // Step 3: Read N groceries and insert them one-at-a-time
  // into the list, making sure you insert them in sorted order.
  // I recommend using iterators and `insert()`.
  int n;
  std::cin >> n;

  // O(n*n)
  for (int i = 0; i < n; i++) {
    int aisle;
    std::string name;
    std::cin >> aisle >> name;

    // O(n)
    for (it = groceries.begin(); !it.end(); it++) {
      if ((it->aisle < aisle &&
           (it.node->next == NULL || it.node->next->data.aisle > aisle)) ||
          (it.node == groceries.head && it->aisle > aisle)) {
        break;
      }
    }
    if (i == 0) {
      groceries.insert(it, Grocery(aisle, name));
    } else if (it.node == groceries.head && it->aisle > aisle) {
      groceries.insert_at_head(it, Grocery(aisle, name));
    } else {
      groceries.insert(it, Grocery(aisle, name));
    }
  }

  // Step 4: Read M groceries and remove them one-at-a-time
  // from the list. I recommend using iterators, and `erase()`.

  int m;
  std::cin >> m;

  // O(m * n)
  for (int i = 0; i < m; i++) {
    std::string remove;
    std::cin >> remove;
    for (it = groceries.begin(); !it.end();) {
      if (it->name == remove) {
        it = groceries.erase(it);
      } else {
        it++;
      }
    }
  }

  // Step 5: Print out all groceries in the list.

  // O(n)
  // A little confused here, I think you could just write a function to call named print() for example - Carson
  for (it = groceries.begin(); !it.end(); it++) {
    std::cout << it->name << std::endl;
  }
}
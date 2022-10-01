using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class RotateList {
 public:
  static ListNode *rotate(ListNode *head, int rotations) {
    auto first = head;
    auto cur = head;
    ListNode *prv = nullptr;
    auto counter = 0;
    while (counter < rotations && cur != nullptr) {
      prv = cur;
      cur = cur->next;
      counter++;
    }

    // if rotations > size(list)
    if (cur == nullptr) {
      cur = first;
      prv = nullptr;
      rotations = rotations % counter;
      counter = 0;
      while (counter < rotations && cur != nullptr) {
        prv = cur;
        cur = cur->next;
        counter++;
      }
    }

    // prv is the end of the rotated list
    prv->next = nullptr;

    // after rotating, this is new head
    auto new_head = cur;

    // go to the end of the list
    while (cur != nullptr) {
      prv = cur;
      cur = cur->next;
    }

    // the end of original list should link to the start of original list
    prv->next = first;

    return new_head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  ListNode *result = RotateList::rotate(head, 8);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }

  cout << endl;
}
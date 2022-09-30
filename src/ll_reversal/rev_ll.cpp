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

class ReverseLinkedList {
 public:
  static ListNode *reverse(ListNode *head) {
    ListNode *prv = nullptr;
    auto cur = head;
    while (cur != nullptr) {
      auto tmp = cur->next;
      cur->next = prv;
      prv = cur;
      cur = tmp;
    }
    cout << endl;

    return prv;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(8);
  head->next->next->next->next = new ListNode(10);

  ListNode *result = ReverseLinkedList::reverse(head);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
  cout << endl;
}

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

class ReverseSubList {
 public:
  static ListNode *reverse(ListNode *head, int p, int q) {
    ListNode *prv = nullptr;
    ListNode *first = nullptr;
    ListNode *last = nullptr;
    ListNode *zero = nullptr;
    auto cur = head;
    auto counter = 1;
    while (cur != nullptr) {
      if (counter == p-1) {
        zero = cur;
      } else if (counter == p) {
        first = cur;
      } else if (counter == q) {
        last = cur;
        auto tmp = cur->next;
        cur->next = prv;
        prv = cur;
        cur = tmp;
        counter++;
        continue;
      } else if (counter > q) {
        first->next = cur;
        zero->next = last;
        break;
      } else {
        auto tmp = cur->next;
        cur->next = prv;
        prv = cur;
        cur = tmp;
        counter++;
        continue;
      }
      prv = cur;
      cur = cur->next;
      counter++;
    }

    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *result = ReverseSubList::reverse(head, 2, 4);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
  cout << endl;
}
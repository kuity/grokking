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

class ReverseEveryKElements {
 public:
  static ListNode *reverse(ListNode *head, int k) {
    ListNode *prv = nullptr;
    auto cur = head;
    ListNode *new_head = nullptr;
    ListNode *prev_set_first = nullptr;
    ListNode *cur_set_first = nullptr;
    auto counter = 1;
    while (cur != nullptr) {
      cout << cur->value << " ";

      // New head of the ll to return
      if (counter == k) {
        new_head = cur;
      }

      // original final element of sublist or end of ll, settle its preceding link
      if ((counter%k == 0 || cur->next == nullptr) && prev_set_first != nullptr) {
        prev_set_first->next = cur;
      }

      // original first element of sublist
      if (counter%k == 1) {
        prev_set_first = cur_set_first;
        cur_set_first = cur;
        prv = cur;
        cur = cur->next;
        prv->next = nullptr;
        counter++;
        continue;
      } else {
        auto tmp = cur->next;
        cur->next = prv;
        prv = cur;
        cur = tmp;
        counter++;
      }
    }

    cout << endl;
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
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(8);

  ListNode *result = ReverseEveryKElements::reverse(head, 3);
  cout << "Nodes of the a reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
  cout << endl;
}
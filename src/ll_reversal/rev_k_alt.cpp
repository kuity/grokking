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

class ReverseAlternatingKElements {
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
      auto is_skip_set = ((counter-1) / k) % 2 == 1;

      // final element of sublist or end of ll, settle its preceding link (reverse order set)
      if ((counter%k == 0 || cur->next == nullptr) && prev_set_first != nullptr && !is_skip_set) {
        cout << "rev set prev link" << " ";
        prev_set_first->next = cur;
      }

      // first element of sublist or end of ll, settle its preceding link (normal order set)
      if (counter%k == 1 && cur_set_first != nullptr && is_skip_set) {
        cout << "norm set prev link" << " ";
        cur_set_first->next = cur;
      }

      // second element of sublist onwards (reverse order set) = swap order
      if (counter%k != 1 && !is_skip_set) {
        cout << "rev set 2+" << " ";
        auto tmp = cur->next;
        cur->next = prv;
        prv = cur;
        cur = tmp;
        counter++;
      } else if (counter%k == 1 && !is_skip_set) { // first element of sublist (reverse order set)
        cout << "rev set 1" << " ";
        prev_set_first = cur_set_first;
        cur_set_first = cur;
        prv = cur;
        cur = cur->next;
        prv->next = nullptr;
        counter++;
      } else if (counter%k == 0 && is_skip_set) { // final element of sublist (normal order set)
        cout << "norm set last" << " ";
        prev_set_first = cur_set_first;
        cur_set_first = cur;
        prv = cur;
        cur = cur->next;
        counter++;
      } else if (is_skip_set) { // Skip the alternating set
        cout << "norm set" << " ";
        prv = cur;
        cur = cur->next;
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
  head->next->next->next->next->next->next->next->next = new ListNode(9);
  head->next->next->next->next->next->next->next->next->next = new ListNode(10);

  ListNode *result = ReverseAlternatingKElements::reverse(head, 1);
  cout << "Nodes of the reversed LinkedList are: ";
  auto counter = 1;
  while (result != nullptr && counter < 20) {
    cout << result->value << " ";
    result = result->next;
    counter++;
  }

  cout << endl;
}
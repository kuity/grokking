using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

/*
class MergeKSortedLists {
 public:
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.first > y.first;
    }
  };

  static ListNode *merge(const vector<ListNode *> &lists) {
    ListNode *resultHead = nullptr;
    int num_completed = 0;
    int num_lists = lists.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, valueCompare> q;
    vector<ListNode*> v;
    for (auto i=0; i<num_lists; i++) {
        auto l = lists[i];
        q.push(make_pair(l->value, i));
        v.push_back(l->next);
    }

    while(q.size() > 0) {
        auto e = q.top();
        ListNode *newNode = new ListNode(e.first);
        newNode->next = resultHead;
        resultHead = newNode;
        q.pop();

        if (v[e.second] != nullptr) {
            q.push(make_pair(v[e.second]->value, e.second));
            v[e.second] = v[e.second]->next;
        } 
    }

    return resultHead;
  }
};
*/

class MergeKSortedLists {
 public:
  struct valueCompare {
    bool operator()(const ListNode *x, const ListNode *y) { return x->value > y->value; }
  };

  static ListNode *merge(const vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, valueCompare> minHeap;

    // put the root of each list in the min heap
    for (auto root : lists) {
      if (root != nullptr) {
        minHeap.push(root);
      }
    }

    // take the smallest (top) element form the min-heap and add it to the result;
    // if the top element has a next element add it to the heap
    ListNode *resultHead = nullptr, *resultTail = nullptr;
    while (!minHeap.empty()) {
      ListNode *node = minHeap.top();
      minHeap.pop();
      if (resultHead == nullptr) {
        resultHead = resultTail = node;
      } else {
        resultTail->next = node;
        resultTail = resultTail->next;
      }
      if (node->next != nullptr) {
        minHeap.push(node->next);
      }
    }

    return resultHead;
  }
};

int main(int argc, char *argv[]) {
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(6);
  l1->next->next = new ListNode(8);

  ListNode *l2 = new ListNode(3);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(7);

  ListNode *l3 = new ListNode(1);
  l3->next = new ListNode(3);
  l3->next->next = new ListNode(4);

  ListNode *result = MergeKSortedLists::merge(vector<ListNode *>{l1, l2, l3});

  cout << "Here are the elements form the merged list: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}

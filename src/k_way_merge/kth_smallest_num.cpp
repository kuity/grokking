using namespace std;

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

class KthSmallestInMSortedArrays {
 public:
  struct valueCompare {
    bool operator()(const tuple<int, int, int> x, const tuple<int, int, int> y) { return get<0>(x) > get<0>(y); }
  };

  static int findKthSmallest(const vector<vector<int>> &lists, int k) {
    int result = -1;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, valueCompare> minHeap;

    // put the first element of each list in the min heap
    // (element, vec_position, index)
    for (auto i=0; i<lists.size(); i++) {
      auto v = lists[i];
      minHeap.push(make_tuple(v[0], i, 0));
    }

    auto tracker = 0; // track the nth smallest num in lists
    tuple<int, int, int> p;
    while (tracker < k) {
      p = minHeap.top();
      minHeap.pop();
      auto pos = get<1>(p);
      auto v = lists[pos];
      auto next_index = get<2>(p) + 1;
      if (next_index < v.size()) {
        minHeap.push(make_tuple(v[next_index], pos, next_index));
      }
      tracker++;
    }

    return get<0>(p);
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> lists = {{2, 6, 8}, {3, 6, 7}, {1, 3, 4}};
  int result = KthSmallestInMSortedArrays::findKthSmallest(lists, 5);
  cout << "Kth smallest number is: " << result;
}

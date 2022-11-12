using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestNumber {
 public:

  struct greater {
    bool operator()(const int& a, const int& b) const { return a > b; }
  };

  static int findKthSmallestNumber(const vector<int> &nums, int k) {
    vector<int> minHeap(nums.begin(), nums.end());
    make_heap(minHeap.begin(), minHeap.end(), greater());

    for (int i = 0; i < k-1; i++) {
      pop_heap(minHeap.begin(), minHeap.end(), greater());
      minHeap.pop_back();
    }

    return minHeap.front();
  }
};

int main(int argc, char *argv[]) {
  int result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 3);
  cout << "Kth smallest number is: " << result << endl;

  // since there are two 5s in the input array, our 3rd and 4th smallest numbers should be a '5'
  result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 4);
  cout << "Kth smallest number is: " << result << endl;

  result = KthSmallestNumber::findKthSmallestNumber(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Kth smallest number is: " << result << endl;
}

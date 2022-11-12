using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KLargestNumbers {
 public:

  struct greater {
    bool operator()(const int& a, const int& b) const { return a > b; }
  };

  static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
    // put first 'K' numbers in the min heap
    vector<int> minHeap(nums.begin(), nums.begin() + k);
    make_heap(minHeap.begin(), minHeap.end(), greater());

    // go through the remaining numbers of the array, if the number from the array is bigger than
    // the top (smallest) number of the min-heap, remove the top number from heap and add the number
    // from array
    for (int i = k; i < nums.size(); i++) {
      if (nums[i] > minHeap.front()) {
        pop_heap(minHeap.begin(), minHeap.end(), greater());
        minHeap.pop_back();
        minHeap.push_back(nums[i]);
        push_heap(minHeap.begin(), minHeap.end(), greater());
      }
    }

    // the heap has the top 'K' numbers
    return minHeap;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = KLargestNumbers::findKLargestNumbers(vector<int>{3, 1, 5, 12, 2, 11}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KLargestNumbers::findKLargestNumbers(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}

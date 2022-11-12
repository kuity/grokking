using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthLargestNumberInStream {
 public:
  struct valueCompare {
    char operator()(const int x, const int y) {
      return x > y;
    }
  };

  priority_queue<int, vector<int>, valueCompare> q;
  KthLargestNumberInStream(const vector<int> &nums, int k) {
    for (auto i=0; i<k; i++) {
        q.push(nums[i]);
    }

    for (auto i=k; i<nums.size(); i++) {
        add(nums[i]);
    }
  }

  virtual int add(int num) {
    if (num > q.top()) {
        q.push(num);
        q.pop();
    }
    return q.top();
  }
};

int main(int argc, char *argv[]) {
  KthLargestNumberInStream kthLargestNumber({3, 1, 5, 12, 2, 11}, 4);
  cout << "4th largest number is: " << kthLargestNumber.add(6) << endl;
  cout << "4th largest number is: " << kthLargestNumber.add(13) << endl;
  cout << "4th largest number is: " << kthLargestNumber.add(4) << endl;
}

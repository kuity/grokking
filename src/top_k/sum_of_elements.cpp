using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class SumOfElements {
 public:
  struct valueCompare {
    char operator()(const int &x, const int &y) {
      return x > y;
    }
  };

  static int findSumOfElements(const vector<int> &nums, int k1, int k2) {
    int elementSum = 0;
    int numToSum = k2-k1-1;
    // want to keep the k largest elements in a min heap
    int k = nums.size()-k1;
    priority_queue<int, vector<int>, valueCompare> q;

    for (auto i=0; i<k; i++) {
        q.push(nums[i]);
    }

    for (auto i=k; i<nums.size(); i++) {
        if (nums[i] > q.top()) {
            q.push(nums[i]);
            q.pop();
        }
    }

    for (auto i=0; i<numToSum; i++) {
        elementSum += q.top();
        q.pop();
    }

    return elementSum;
  }
};

int main(int argc, char *argv[]) {
  int result = SumOfElements::findSumOfElements(vector<int>{1, 3, 12, 5, 15, 11}, 3, 6);
  cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;

  result = SumOfElements::findSumOfElements(vector<int>{3, 5, 8, 7}, 1, 4);
  cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;
}

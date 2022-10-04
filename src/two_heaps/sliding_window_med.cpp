using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class SlidingWindowMedian {
 private:
  priority_queue<double, vector<double>, greater<double>> maxheap;
  priority_queue<double> minheap;

 public:
  virtual void insertNum(int num) {
    if (maxheap.size()==0) {
        maxheap.push(num);
    } else {
        minheap.push(num);
        if (minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
  }

  virtual double findMedian() {
    if (maxheap.size() > minheap.size()) {
        return maxheap.top();
    } else {
        return (maxheap.top() + minheap.top())/2;
    }
  }

  virtual vector<double> findSlidingWindowMedian(const vector<int> &nums, int k) {
    vector<double> result(nums.size() - k + 1);
    sort(nums.begin(), nums.end());
    for (auto i=0; i<k; i++) {
        insertNum(i);
    }
    result.push_back(findMedian());

    for (auto i=k; i<nums.size(); i++) {


    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  SlidingWindowMedian slidingWindowMedian;
  vector<double> result =
      slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 2);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  slidingWindowMedian = SlidingWindowMedian();
  result = slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 3);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
}

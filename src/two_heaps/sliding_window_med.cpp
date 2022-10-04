using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

// extending priority_queue to implement 'remove'
template <typename T, class Container = vector<T>,
          class Compare = less<typename Container::value_type>>
class priority_queue_special : public priority_queue<T, Container, Compare> {
 public:
  bool remove(const T &valueToRemove) {
    auto itr = std::find(this->c.begin(), this->c.end(), valueToRemove);
    if (itr == this->c.end()) {
      return false;
    }
    this->c.erase(itr);
    // ideally we should not be rebuilding the heap as we are removing only one element
    // a custom implementation of priority queue can adjust only one element in O(logN)
    make_heap(this->c.begin(), this->c.end(), this->comp);
    return true;
  }
};

class SlidingWindowMedian {
 private:
  void rebalance() {
    // cout << "maxheap size is " << maxheap.size() << endl;
    // cout << "minheap size is " << minheap.size() << endl;
    if (maxheap.size() > 1 + minheap.size()) {
        minheap.push(maxheap.top());
        maxheap.pop();
    } else if (minheap.size() > maxheap.size()) {
        maxheap.push(minheap.top());
        minheap.pop();
    }
    // cout << "maxheap size is " << maxheap.size() << endl;
    // cout << "minheap size is " << minheap.size() << endl;
    // if (maxheap.size() > 0) {
    //   cout << "maxheap top is " << maxheap.top() << endl;
    // }
    // if (minheap.size() > 0) {
    //   cout << "minheap top is " << minheap.top() << endl;
    // }
  }

 public:
  priority_queue_special<int> maxheap;
  priority_queue_special<int, vector<int>, greater<int>> minheap;

  virtual void insertNum(int num) {
    if (maxheap.size()==0) {
      maxheap.push(num);
    } else if (num <= maxheap.top()) {
      maxheap.push(num);
    } else {
      minheap.push(num);
    }
    rebalance();
  }

  virtual void removeNum(int num) {
    if (num <= maxheap.top()) {
      maxheap.remove(num);
      rebalance();
    } else {
      minheap.remove(num);
      rebalance();
    }
  }

  virtual double findMedian() {
    if (maxheap.size() > minheap.size()) {
      return maxheap.top();
    } else {
      return (maxheap.top() + minheap.top())/2.0;
    }
  }

  virtual vector<double> findSlidingWindowMedian(const vector<int> &nums, int k) {
    vector<double> result{};
    for (auto i=0; i<k; i++) {
      insertNum(nums[i]);
    }
    result.push_back(findMedian());

    for (auto i=k; i<nums.size(); i++) {
      // cout << "inserting " << nums[i] << endl;
      insertNum(nums[i]);
      // cout << "removing " << nums[i-k] << endl;
      removeNum(nums[i-k]);

      result.push_back(findMedian());
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

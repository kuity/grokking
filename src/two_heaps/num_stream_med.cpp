using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class MedianOfAStream {
 private:
  priority_queue<double, vector<double>, greater<double>> maxheap;
  priority_queue<double> minheap;
  
 public:
  virtual void insertNum(int num) {
    if (maxheap.size()==0) {
        maxheap.push(num);
    } else if (num <= maxheap.top()) {
        maxheap.push(num);
        if (maxheap.size() - minheap.size() > 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
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
};

int main(int argc, char *argv[]) {
  MedianOfAStream medianOfAStream;
  medianOfAStream.insertNum(3);
  medianOfAStream.insertNum(1);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(5);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(4);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
}
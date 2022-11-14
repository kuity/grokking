using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

class Element {
 public:
  int number = 0;
  int frequency = 0;
  int sequenceNumber = 0;

  Element(int number, int frequency, int sequenceNumber) {
    this->number = number;
    this->frequency = frequency;
    this->sequenceNumber = sequenceNumber;
  }
};

class FrequencyStack {
 public:
  struct frequencyCompare {
    bool operator()(const Element &e1, const Element &e2) {
      if (e1.frequency != e2.frequency) {
        return e2.frequency > e1.frequency;
      }
      // if both elements have same frequency, return the one that was pushed later
      return e2.sequenceNumber > e1.sequenceNumber;
    }
  };

  int sequenceNumber = 0;
  priority_queue<Element, vector<Element>, frequencyCompare> maxHeap;
  unordered_map<int, int> frequencyMap;

  virtual void push(int num) {
    frequencyMap[num] += 1;
    maxHeap.push({num, frequencyMap[num], sequenceNumber++});
  }

  // No need to update other elements in q
  // Because their frequency variable is tagged to the frequency at the time of push
  // eg. (2, 1, 1), (1, 1, 2), (2, 2, 3) <- if "2" was popped once, the (2, 1, 1) is still correct
  virtual int pop() {
    int num = maxHeap.top().number;
    maxHeap.pop();

    // decrement the frequency or remove if this is the last number
    if (frequencyMap[num] > 1) {
      frequencyMap[num] -= 1;
    } else {
      frequencyMap.erase(num);
    }

    return num;
  }
};

int main(int argc, char *argv[])
{
    FrequencyStack frequencyStack;
    frequencyStack.push(1);
    frequencyStack.push(2);
    frequencyStack.push(3);
    frequencyStack.push(2);
    frequencyStack.push(1);
    frequencyStack.push(2);
    frequencyStack.push(5);
    cout << frequencyStack.pop() << endl;
    cout << frequencyStack.pop() << endl;
    cout << frequencyStack.pop() << endl;
}

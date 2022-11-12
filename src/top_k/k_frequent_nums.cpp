using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TopKFrequentNumbers {
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.second < y.second;
    }
  };

 public:
  static vector<int> findTopKFrequentNumbers(const vector<int> &nums, int k) {
    vector<int> topNumbers;
    priority_queue<pair<int, int>, vector<pair<int, int>>, valueCompare> q;
    unordered_map<int, int> m;

    for (auto n: nums) {
        if (m.find(n) != m.end()) {
            m[n]++;
        } else {
            m.insert(make_pair(n, 1));
        }
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        q.push(make_pair(it->first, it->second));
    }

    for (auto x=0; x<k; x++) {
        auto f = q.top();
        q.pop();
        topNumbers.push_back(f.first);
    }

    return topNumbers;
  }
};

int main(int argc, char *argv[]) {
  vector<int> result =
      TopKFrequentNumbers::findTopKFrequentNumbers(vector<int>{1, 3, 5, 12, 11, 12, 11}, 2);
  cout << "Here are the K frequent numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TopKFrequentNumbers::findTopKFrequentNumbers(vector<int>{5, 12, 11, 3, 11}, 2);
  cout << "Here are the K frequent numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}

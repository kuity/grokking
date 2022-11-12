using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class MaximumDistinctElements {
 public:
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.second > y.second;
    }
  };

  static int findMaximumDistinctElements(const vector<int> &nums, int k) {
    int distinctElementsCount = 0;
    // should be a "min heap" to give element with fewest dupes
    priority_queue<pair<int, int>, vector<pair<int, int>>, valueCompare> q;

    unordered_map<int, int> m;
    for (auto n: nums) {
        m[n]++;
    }

    for (auto it=m.begin(); it!=m.end(); it++) {
        if (it->second==1) {
            distinctElementsCount++;
            continue;
        }
        q.push(make_pair(it->first, it->second));
    }

    while (k > 0 && q.size() > 0) {
        auto f = q.top();
        q.pop();
        auto num_dupes = f.second-1;
        if (num_dupes > k) {
            return distinctElementsCount; // cannot remove any more dupes
        }
        k = k - num_dupes;
        distinctElementsCount++;
    }

    // still need to remove
    if (k > 0) {
        return distinctElementsCount - k;
    } else {
        return distinctElementsCount;
    }
  }
};

int main(int argc, char *argv[]) {
  int result =
      MaximumDistinctElements::findMaximumDistinctElements(vector<int>{7, 3, 5, 8, 5, 3, 3}, 2);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

  result = MaximumDistinctElements::findMaximumDistinctElements(vector<int>{3, 5, 12, 11, 12}, 3);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

  result = MaximumDistinctElements::findMaximumDistinctElements(
      vector<int>{1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5}, 2);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;
}

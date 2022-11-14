using namespace std;

#include <iostream>
#include <limits>
#include <queue>
#include <vector>

// idea
// maintain 1 minheap and 1 maxheap
// minheap = maintain 1 elem from each list
// maxheap = only use once to get "max". after that just use var to track
class SmallestRange {
 public:
  // ((value, index), list_num)
  struct valueMin {
    bool operator()(const pair<pair<int, int>, int> x, const pair<pair<int, int>, int> y) { return x.first.first > y.first.first; }
  };

  struct valueMax {
    bool operator()(const pair<pair<int, int>, int> x, const pair<pair<int, int>, int> y) { return x.first.first < y.first.first; }
  };


  static pair<int, int> findSmallestRange(const vector<vector<int>> &lists) {
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, valueMin> q_min;
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, valueMax> q_max;
    auto sz = lists.size();

    for (auto i=0; i<sz; i++) {
        auto v = lists[i];
        q_min.push(make_pair(make_pair(v[0], 0), i));
        q_max.push(make_pair(make_pair(v[0], 0), i));
    }

    // initialize the range
    auto ans = make_pair(q_min.top().first.first, q_max.top().first.first);
    auto r = ans.second - ans.first;
    auto top = ans.second; // we will track the top of the range
    while(true) {
        auto e = q_min.top();
        auto v = lists[e.second];
        auto index = e.first.second + 1;
        auto value = e.first.first;
        q_min.pop();
        if (index > v.size()) { break; } // the range is final in this case as can no longer replace popped v elem
        q_min.push(make_pair(make_pair(v[index], index), e.second));
        
        auto new_min = q_min.top().first.first;
        if (v[index] > top) { // update the top if needed
            top = v[index];
        }

        if (top-new_min < r) { // update the range if needed
            r = top-new_min;
            ans.first = new_min;
            ans.second = top;
        }
    }

    return ans;
    
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> lists = {{1, 5, 8}, {4, 12}, {7, 8, 10}};
  auto result = SmallestRange::findSmallestRange(lists);
  cout << "Smallest range is: [" << result.first << ", " << result.second << "]" << endl;

  vector<vector<int>> l2 = {{1, 9}, {4, 12}, {7, 10, 16}};
  auto r2 = SmallestRange::findSmallestRange(l2);
  cout << "Smallest range is: [" << r2.first << ", " << r2.second << "]" << endl;
}
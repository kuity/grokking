// [s1, e1]  [s2, e2]
// [s1, e1, index_1]   [s2, e2, index_2]


// h2: s1 > s2  (min heap 4 start)
// h1: e1 < e2  (min heap 4 end)

// 1. pop from h1
// 2. pop from h2 until s > e, then stop
// 3. put [index_h1, index_h2] in result
// 4. goto 1

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class NextInterval {
 public:
  static vector<int> findNextInterval(const vector<Interval> &intervals) {
    int n = intervals.size();
    vector<int> result(n);

    auto lessStart = [](pair<int, Interval> a, pair<int, Interval> b) { return a.second.start > b.second.start; };
    priority_queue<pair<int, Interval>, vector<pair<int, Interval>>, decltype(lessStart)> q_start(lessStart);
    auto lessEnd = [](pair<int, Interval> a, pair<int, Interval> b) { return a.second.end > b.second.end; };
    priority_queue<pair<int, Interval>, vector<pair<int, Interval>>, decltype(lessEnd)> q_end(lessEnd);

    for (auto i=0; i<intervals.size(); i++) {
      q_start.push(make_pair(i, intervals[i]));
      q_end.push(make_pair(i, intervals[i]));
    }

    bool done;
    while(q_end.size() > 0) {
      done = false;
      auto x = q_end.top();
      q_end.pop();

      while(q_start.size() > 0) {
        auto y = q_start.top();
        if (y.second.start >= x.second.end) {
          result[x.first] = y.first;
          done = true;
          break;
        }
        q_start.pop();
      }
      if (done) { continue; }
      result[x.first] = -1;
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> intervals = {{2, 3}, {3, 4}, {5, 6}};
  vector<int> result = NextInterval::findNextInterval(intervals);
  cout << "Next interval indices are: ";
  for (auto index : result) {
    cout << index << " ";
  }
  cout << endl;

  intervals = {{3, 4}, {1, 5}, {4, 6}};
  result = NextInterval::findNextInterval(intervals);
  cout << "Next interval indices are: ";
  for (auto index : result) {
    cout << index << " ";
  }
}
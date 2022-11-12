using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KClosestElements {
 public:
  struct numCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { return x.first < y.first; }
  };

  static vector<int> findClosestElements(const vector<int> &arr, int K, int X) {
    vector<int> result;

    // should be a "max heap"
    priority_queue<pair<int, int>, vector<pair<int, int>>, numCompare> q;

    for (auto i=0; i<K; i++) {
        q.push(make_pair(abs(arr[i]-X), arr[i]));
    }

    for (auto i=K; i<arr.size(); i++) {
        auto diff = abs(arr[i]-X);
        if (diff < q.top().first) {
            q.pop();
            q.push(make_pair(diff, arr[i]));
        }
    }

    while (q.size() > 0) {
        result.push_back(q.top().second);
        q.pop();
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<int> result = KClosestElements::findClosestElements(vector<int>{5, 6, 7, 8, 9}, 3, 7);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KClosestElements::findClosestElements(vector<int>{2, 4, 5, 6, 9}, 3, 6);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}

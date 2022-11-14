using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestInSortedMatrix {
 public:
  struct valueCompare {
    bool operator()(const pair<int, pair<int, int>> x, const pair<int, pair<int, int>> y) { return x.first > y.first; }
  };

  static int findKthSmallest(vector<vector<int>> &matrix, int k) {
    int result = -1;

    // represent as (value, (x, y))
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, valueCompare> q;
    auto sz = matrix.size();
    auto ranking = 0;
    q.push(make_pair(matrix[0][0], make_pair(0, 0)));
    while(!q.empty()) {
        auto elem = q.top();
        q.pop();
        auto x = elem.second.first;
        auto y = elem.second.second;
        if (x < sz-1) {
            q.push(make_pair(matrix[x+1][y], make_pair(x+1, y)));
        }
        if (y < sz-1) {
            q.push(make_pair(matrix[x][y+1], make_pair(x, y+1)));
        }
        if (ranking++ == k) {
            return elem.first;
        }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> matrix2 = {vector<int>{2, 6, 8}, vector<int>{3, 7, 10},
                                 vector<int>{5, 8, 11}};
  int result = KthSmallestInSortedMatrix::findKthSmallest(matrix2, 5);
  cout << "Kth smallest number is: " << result << endl;
}
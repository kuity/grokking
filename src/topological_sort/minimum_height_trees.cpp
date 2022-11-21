using namespace std;

#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Idea: loop through nodes, try each as root
// make dict with edges (bidirectional)
// "trim" dict based on root. eg. 1->2, then trim off 2->1
// do this with a BFS
// when done, will have adjacency map
class MinimumHeightTrees {
 public:
  static vector<int> findTrees(int nodes, vector<vector<int>>& edges) {
    vector<int> minHeightTrees;
    


    return minHeightTrees;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> vec = {{0, 1}, {1, 2}, {1, 3}, {2, 4}};
  vector<int> result = MinimumHeightTrees::findTrees(5, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  vec = {{0, 1}, {0, 2}, {2, 3}};
  result = MinimumHeightTrees::findTrees(4, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  vec = {{0, 1}, {1, 2}, {1, 3}};
  result = MinimumHeightTrees::findTrees(4, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}

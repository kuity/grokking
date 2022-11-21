using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TaskSchedulingOrder {
 public:
  static vector<int> findOrder(int tasks, const vector<vector<int>>& prerequisites) {
    vector<int> sortedOrder;
    unordered_map<int, vector<int>> adjacency_map;
    unordered_map<int, int> degree_map;
    queue<int> sources;

    for(auto x=0; x<tasks; x++) {
        adjacency_map[x] = vector<int>();
        degree_map[x] = 0;
    }

    for(auto e: prerequisites) {
      int parent = e[0], child = e[1];
      adjacency_map[parent].push_back(child);
      degree_map[child]++;
    }

    for(auto i=degree_map.begin(); i!=degree_map.end(); i++) {
        if(i->second==0) {
            sources.push(i->first);
        }
    }

    while(!sources.empty()) {
        auto s = sources.front();
        sources.pop();
        sortedOrder.push_back(s);
        auto children = adjacency_map[s];
        for (auto c: children) {
            degree_map[c]--;
            if (degree_map[c] == 0) {
                sources.push(c);
            }
        }
    }

    if (sortedOrder.size() != tasks) {
        return {};
    }
    return sortedOrder;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result =
      TaskSchedulingOrder::findOrder(3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TaskSchedulingOrder::findOrder(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{2, 0}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TaskSchedulingOrder::findOrder(
      6, vector<vector<int>>{vector<int>{2, 5}, vector<int>{0, 5}, vector<int>{0, 4},
                             vector<int>{1, 4}, vector<int>{3, 2}, vector<int>{1, 3}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}

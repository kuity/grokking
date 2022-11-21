using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class AllTaskSchedulingOrders {
 private:
  static void printVec(vector<int> v) {
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl;
  }

  // idea: we will use std:next_permutation() to generate orderings of sources
  static void printRecursive(
    unordered_map<int, vector<int>> &adjacency_map, 
    unordered_map<int, int> &degree_map,
    vector<int> &sources,
    vector<int> &sortedOrder
  ) {
    // generate sources for next recursive call
    for (auto s=0; s<sources.size(); s++) {
        auto node = sources[s];
        sortedOrder.push_back(node);
        auto children = adjacency_map[node];
        sources.erase(sources.begin()+s);
        for (auto c: children) {
            degree_map[c]--;
            if(degree_map[c]==0) {
                sources.push_back(c);
            }
        }

        // cout << "new sources: ";
        // printVec(sources);
        // make next recursive call if there are any new sources
        if (sources.size() > 0) {
            printRecursive(adjacency_map, degree_map, sources, sortedOrder);
        }

        // print if the order is right len
        if (sortedOrder.size() == degree_map.size()) {
            printVec(sortedOrder);
        }

        // restore the degree_map and sorted order
        for (auto c: children) {
            if(degree_map[c]==0) {
                sources.pop_back();
            }
            degree_map[c]++;
        }
        sources.emplace(sources.begin()+s, node);
        sortedOrder.pop_back();
    }
  }

 public:
  static void printOrders(int tasks, vector<vector<int>> &prerequisites) {
    vector<int> sortedOrder;
    unordered_map<int, vector<int>> adjacency_map;
    unordered_map<int, int> degree_map;
    vector<int> sources;

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
            sources.push_back(i->first);
        }
    }

    cout << "first recursive call: ";
    printVec(sources);
    printRecursive(adjacency_map, degree_map, sources, sortedOrder);
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> vec = {{0, 1}, {1, 2}};
  AllTaskSchedulingOrders::printOrders(3, vec);
  cout << endl;

  vec = {{3, 2}, {3, 0}, {2, 0}, {2, 1}};
  AllTaskSchedulingOrders::printOrders(4, vec);
  cout << endl;

  vec = {{2, 5}, {0, 5}, {0, 4}, {1, 4}, {3, 2}, {1, 3}};
  AllTaskSchedulingOrders::printOrders(6, vec);
  cout << endl;
}

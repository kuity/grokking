using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class SequenceReconstruction {
 private:
  static void printVec(vector<int> v) {
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl;
  }

  static void findRecursive(
    unordered_map<int, vector<int>> &adjacency_map, 
    unordered_map<int, int> &degree_map,
    vector<int> &sources,
    vector<vector<int>> &sortedOrders,
    vector<int> &currentOrder
  ) {
    // generate sources for next recursive call
    for (auto s=0; s<sources.size(); s++) {
        auto node = sources[s];
        currentOrder.push_back(node);
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
            findRecursive(adjacency_map, degree_map, sources, sortedOrders, currentOrder);
        }

        // add currentOrder if it is the right len
        if (currentOrder.size() == degree_map.size()) {
            vector<int> doneOrder(currentOrder);
            cout << "ordering found: ";
            printVec(doneOrder);
            sortedOrders.push_back(doneOrder);
        }

        // restore the degree_map and current order
        for (auto c: children) {
            if(degree_map[c]==0) {
                sources.pop_back();
            }
            degree_map[c]++;
        }
        sources.emplace(sources.begin()+s, node);
        currentOrder.pop_back();
    }
  }
 public:
  static bool canConstruct(const vector<int> &originalSeq, const vector<vector<int>> &sequences) {
    unordered_map<int, vector<int>> adjacency_map;
    unordered_map<int, int> degree_map;
    vector<int> sources;
    vector<int> currentOrder = {};
    vector<vector<int>> sortedOrders;

    // initialize maps
    for (auto i: originalSeq) {
        adjacency_map[i] = vector<int>();
        degree_map[i] = 0;
    }

    // update the adjacency and degree maps
    for (auto s: sequences) {
        for (auto index=0; index<s.size()-1; index++) {
            auto parent = s[index], child = s[index+1];
            auto values = adjacency_map[parent];
            if (find(values.begin(), values.end(), child) == values.end()) {
                adjacency_map[parent].push_back(child);
                degree_map[child]++;
            }
        }
    }

    // populate sources
    for(auto i=degree_map.begin(); i!=degree_map.end(); i++) {
        if(i->second==0) {
            sources.push_back(i->first);
        }
    }

    // recursive call to find all possible orders
    findRecursive(adjacency_map, degree_map, sources, sortedOrders, currentOrder);
    cout << "number of orders = " << sortedOrders.size() << endl;

    // compare the found sequences to the original sequence 
    if (sortedOrders.size() != 1) {
        return false;
    } else if (sortedOrders[0].size() != originalSeq.size()) {
        return false;
    } else {
        auto foundOrder = sortedOrders[0];
        for (auto i=0; i<originalSeq.size(); i++) {
            if (foundOrder[i] != originalSeq[i]) {
                return false;
            }
        }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  bool result = SequenceReconstruction::canConstruct(
      vector<int>{1, 2, 3, 4},
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{3, 4}});
  cout << "Can we uniquely construct the sequence: " << result << endl;

  result = SequenceReconstruction::canConstruct(
      vector<int>{1, 2, 3, 4},
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{2, 4}});
  cout << "Can we uniquely construct the sequence: " << result << endl;

  result = SequenceReconstruction::canConstruct(
      vector<int>{3, 1, 4, 2, 5},
      vector<vector<int>>{vector<int>{3, 1, 5}, vector<int>{1, 4, 2, 5}});
  cout << "Can we uniquely construct the sequence: " << result << endl;
}

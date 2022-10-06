using namespace std;

#include <iostream>
#include <vector>

class Subsets {
 public:
  static vector<vector<int>> findSubsets(const vector<int>& nums) {
    vector<vector<int>> subsets;
    subsets.push_back(vector<int>{});
    for(auto n: nums) {
        auto lim = subsets.size();
        for(auto i=0; i<lim; i++) {
            auto new_v = subsets[i];
            new_v.push_back(n);
            subsets.push_back(new_v);
        }
    }
    return subsets;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Subsets::findSubsets(vector<int>{1, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  result = Subsets::findSubsets(vector<int>{1, 5, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}

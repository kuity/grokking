using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class SubsetWithDuplicates {
 public:
  static vector<vector<int>> findSubsets(vector<int>& nums) {
    vector<vector<int>> subsets;
    sort(nums.begin(), nums.end());
    subsets.push_back(vector<int>{});
    auto previous_ind = 0;
    auto start_ind = 0;
    for(auto ind=0; ind<nums.size(); ind++) {
        auto n = nums[ind];
        auto lim = subsets.size();
        // if current num is a duplicate (equal to previous num), don't repeat alg for all the "seen" elements
        if (ind > 0 && n == nums[ind-1]) {
            start_ind = previous_ind;
        } else {
            start_ind = 0;
        }
        previous_ind = lim;
        for(auto i=start_ind; i<lim; i++) {
            auto new_v = subsets[i];
            new_v.push_back(n);
            subsets.push_back(new_v);
        }
    }

    return subsets;
  }
};

int main(int argc, char* argv[]) {
  vector<int> vec = {1, 3, 3};
  vector<vector<int>> result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  vec = {1, 5, 3, 3};
  result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Permutations {
 public:
  static vector<vector<int>> findPermutations(const vector<int>& nums) {
    vector<vector<int>> result;
    result.push_back(vector<int> {});
    
    for (auto n: nums) {
        auto lim = result.size();
        for (auto i=0; i<lim; i++) {
            auto v = result[0];
            result.erase(result.begin());
            auto v_size = v.size();
            for (auto j=0; j<=v_size; j++) {
                auto new_v = v;
                new_v.emplace(new_v.begin()+j, n);
                result.push_back(new_v);
            }
        }
    }

    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Permutations::findPermutations(vector<int>{1, 3, 5});
  cout << "Here are all the permutations: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}

// [[]] <= 1
// [[1]] <= 3
// [[1,3],[3,1]] <= 5
// [[5,1,3], [1,5,3], [1,3,5], [5,3,1], [3,5,1], [3,1,5]]
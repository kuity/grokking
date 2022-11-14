using namespace std;

#include <iostream>
#include <vector>

class LargestPairs {
 public:
  // idea: keep a buffer for each list and a max heap
  // pop loop -> go to buffer for respective list
  // pop other list -> clear out buffer
  static vector<pair<int, int>> findKLargestPairs(const vector<int> &nums1,
                                                  const vector<int> &nums2, int k) {
    vector<pair<int, int>> result;



    return result;
  }
};

int main(int argc, char *argv[]) {
  auto result = LargestPairs::findKLargestPairs({9, 8, 2}, {6, 3, 1}, 3);
  cout << "Pairs with largest sum are: ";
  for (auto pair : result) {
    cout << "[" << pair.first << ", " << pair.second << "] ";
  }
}

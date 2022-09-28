using namespace std;

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

void swap(vector<int> &arr, int i, int j) {
    auto tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

class FindCorruptNums {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    vector<int> duplicateNumbers;
    auto i = 0;
    while (i < nums.size()) {
      auto num = nums[i];
      if (nums[num-1] != num) { // Check value at correct position of num (pos)
        swap(nums, i, num-1);
      } else { // if i != pos, num must be a duplicate
        i++;
      }
    }

    for (auto i=0; i<nums.size(); i++) {
      if (nums[i] != i+1) {
        duplicateNumbers.push_back(i+1);
        duplicateNumbers.push_back(nums[i]);
        break;
      }
    }

    return duplicateNumbers;
  }
};

int main() {
  vector<int> v {3, 1, 2, 5, 2};
  vector<int> v_ans {2, 4};
  auto N = FindCorruptNums().findNumbers(v);
  sort(N.begin(), N.end());
  for (auto x: N) {
    cout << x << " ";
  }
  cout << endl;
  
  assert(N ==  v_ans);

  vector<int> v2 {3, 1, 2, 3, 6, 4};
  vector<int> v2_ans {3, 5};
  N = FindCorruptNums().findNumbers(v2);
  sort(N.begin(), N.end());
  for (auto x: N) {
    cout << x << " ";
  }
  cout << endl;

  assert(N ==  v2_ans);
}
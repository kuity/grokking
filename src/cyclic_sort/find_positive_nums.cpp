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

class FirstKMissingPositive {
 public:
  static vector<int> findNumbers(vector<int> &nums, int k) {
    vector<int> missingNumbers;

    // extend the vector
    for (auto i=0;i<k;i++) {
      nums.push_back(-1);
    }

    auto i = 0;
    while (i<nums.size()) {
      auto val = nums[i];
      if (val < 1 || val > nums.size()) {
        i++;
      } else {
        auto true_pos = val - 1;
        if (nums[true_pos] != val) {
          swap(nums, i, true_pos);
        } else {
          i++;
        }
      }
    }

    auto counter = 0;
    auto j = 0;
    while (counter < k) {
      if (nums[j] == j+1) {
        j++;
      } else {
        missingNumbers.push_back(j+1);
        counter++;
        j++;
      }
    }

    return missingNumbers;
  }
};

int main() {
  vector<int> v {3, -1, 4, 5, 5};
  int k = 3;
  vector<int> v_ans {1,2,6};
  auto N = FirstKMissingPositive().findNumbers(v, k);
  for (auto x: N) {
    cout << x << " ";
  }
  cout << endl;
  assert(N ==  v_ans);

  vector<int> v2 {2, 3, 4};
  k = 3;
  vector<int> v2_ans {1,5,6};
  N = FirstKMissingPositive().findNumbers(v2, k);
  for (auto x: N) {
    cout << x << " ";
  }
  cout << endl;
  assert(N ==  v2_ans);
}
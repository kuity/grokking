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

class FirstSmallestMissingPositive {
 public:
  static int findNumber(vector<int> &nums) {
    auto m = -1;
    for (auto n: nums) {
      if (n < 0) {
        continue;
      } else if (n > m && m == -1) {
        m = n;
      } else if (n < m) {
        m = n;
      }
    }

    auto i = 0;
    while (i < nums.size()) {
      auto val = nums[i];
      if (val < 0) {
        i++;
        continue;
      } 

      auto true_pos = val - m;
      if (nums[true_pos] == val) {
        i++;
      } else if (true_pos >= nums.size()) {
        i++;
      } else {
        swap(nums, i, true_pos);
      }
    }

    for (auto x: nums) {
      cout << x << " ";
    }
    cout << endl;

    for (int i=0; i<nums.size(); i++) {
      auto true_val = i+m;
      if (nums[i] != true_val) {
        return true_val;
      }
    }

    return -1;
  }
};

int main() {
  vector<int> v {-3, 1, 5, 4, 2};
  int v_ans = 3;
  auto N = FirstSmallestMissingPositive().findNumber(v);
  cout << N << endl;
  assert(N ==  v_ans);

  vector<int> v2 {3, -2, 0, 1, 2};
  int v2_ans = 4;
  N = FirstSmallestMissingPositive().findNumber(v2);
  cout << N << endl;
  assert(N ==  v2_ans);
}
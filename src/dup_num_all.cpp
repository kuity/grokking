using namespace std;

#include <iostream>
#include <vector>
#include <cassert>

void swap(vector<int> &arr, int i, int j) {
    auto tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

class FindDuplicate {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    vector<int> duplicateNumbers;
    auto i = 0;
    while (i < nums.size()) {
        auto num = nums[i];
        if (nums[num-1] != num) { // Check value at correct position of num (pos)
          swap(nums, i, num-1);
        } else if (num == i+1) { // 1st check OK, check if i == pos
          i++;
        } else { // if i != pos, num must be a duplicate
          duplicateNumbers.push_back(num);
          i++;
        }
    }

    return duplicateNumbers;
  }
};

int main() {
  vector<int> v {5, 4, 7, 2, 3, 5, 3};
  vector<int> v_ans {3, 5};
  auto N = FindDuplicate().findNumbers(v);
  assert(N ==  v_ans);
}
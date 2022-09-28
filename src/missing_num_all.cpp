using namespace std;

#include <iostream>
#include <vector>

void swap(vector<int> &arr, int i, int j) {
    auto tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

class AllMissingNumbers {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    vector<int> missingNumbers;
    auto i = 0;
    auto max = 0;
    //  && nums[i] != nums[nums[i]]
    while (i < nums.size()) {
        auto num = nums[i];
        if (nums[num-1] != num) {
            swap(nums, i, num-1);
        } else {
            i++;
        }
    }
    for (auto j=0; j<nums.size(); j++) {
        if (nums[j] != j+1) {
            missingNumbers.push_back(j+1);
        }
    }
    return missingNumbers;
  }
};

int main() {
  vector<int> v {2, 3, 1, 8, 2, 3, 5, 1};
  auto N = AllMissingNumbers().findNumbers(v);
  for (auto i: N) {
    cout << i << " ";
  }
  cout << endl;
}
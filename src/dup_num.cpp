using namespace std;

#include <iostream>
#include <vector>

void swap(vector<int> &arr, int i, int j) {
    auto tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

class FindDuplicate {
 public:
  static int findNumber(vector<int> &nums) {
    // TODO: Write your code here
    auto i = 0;
    while (i < nums.size()) {
        auto num = nums[i];
        if (nums[num-1] != num) {
          swap(nums, i, num-1);
        } else if (num == i+1) {
          i++;
        } else {
          return num;
        }
    }

    return -1;
  }
};

int main() {
  vector<int> v {1, 4, 4, 3, 2};
  auto N = FindDuplicate().findNumber(v);
  cout << N << endl;
  vector<int> v2 {2, 1, 3, 3, 5, 4};
  N = FindDuplicate().findNumber(v2);
  cout << N << endl;
}
using namespace std;

#include <iostream>
#include <vector>

class TwoSingleNumbers {
public:
  static vector<int> findSingleNumbers(vector<int> &nums) {
    auto a_xor_b = 0;
    for (auto i: nums) {
        a_xor_b = a_xor_b ^ i;
    }

    auto first_nonzero_index = 0;
    auto finder = a_xor_b;
    while (true) {
        if ((finder&1) == 1) {
            break;
        }
        finder = finder >> 1;
        first_nonzero_index++;
    }

    vector<int> v_one, v_zero;
    for (auto i: nums) {
        if (((i>>first_nonzero_index)&1)==1) {
            v_one.push_back(i);
        } else {
            v_zero.push_back(i);
        }
    }

    vector<int> ans;
    auto tracker = 0;
    for (auto i: v_one) {
        tracker = tracker ^ i;
    }
    ans.push_back(tracker);
    tracker = 0;
    for (auto i: v_zero) {
        tracker = tracker ^ i;
    }
    ans.push_back(tracker);

    return ans;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {1, 4, 2, 1, 3, 5, 6, 2, 3, 5};
  vector<int> result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;

  v1 = {2, 1, 3, 2};
  result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;
}
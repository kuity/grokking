using namespace std;

#include <iostream>
#include <vector>
#include <queue>

class LargestPairs {
 public:
  // idea: keep a buffer for each list and a max heap
  // pop loop -> go to buffer for respective list
  // pop other list -> clear out buffer
  static vector<pair<int, int>> findKLargestPairs(const vector<int> &nums1,
                                                  const vector<int> &nums2, int k) {
    vector<pair<int, int>> result;
    vector<int> buf_max;
    vector<int> buf_next;
    bool last_is_one;
    int i = 0;
    int j = 0;
    int counter = 0;
    if (nums1[0] >= nums2[0]) {
      last_is_one = true;
      buf_next.push_back(nums1[0]);
      i++;
    } else {
      last_is_one = false;
      buf_next.push_back(nums2[0]);
      j++;
    }

    while(i<nums1.size() && j<nums2.size() && counter < k) {
      int greatest;
      bool current_is_one;
      if (nums1[i] >= nums2[j]) {
        greatest = nums1[i];
        i++;
        current_is_one = true;
      } else {
        greatest = nums2[j];
        j++;
        current_is_one = false;
      } 

      // If there is a "flip" i.e. this max element belongs to different list as last max element
      if (current_is_one != last_is_one) {
        buf_max = buf_next;
        buf_next = {};
        last_is_one = current_is_one;
      } 
      buf_next.push_back(greatest);

      for (auto x: buf_max) {
        result.push_back(make_pair(x, greatest));
        counter++;
        if (counter == k) {
          break;
        }
      }
    }

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
using namespace std;

#include <iostream>
#include <vector>

// Note: Iterative better as can save stack space and no need copy vector
class BinarySearch {
 public:
  static int search(const vector<int>& arr, int key) {
    auto l = arr.size();
    if (l==0) {
        return -1;
    } else if (l==1) {
        if (arr[0]==key) {
            return 0;
        } else {
            return -1;
        }
    }

    auto mid_index = l/2;
    auto mid = arr[mid_index];
    if (mid == key) {
        return mid_index;
    } 

    bool cond = (mid > key);
    if (arr[0] > arr[l-1]) {
        cond = (mid < key);
    }     
    cout << "mid is " << mid << ", key is " << key << ", cond is " << cond << endl;

    if (cond) {
        vector<int> v(arr.begin(), arr.begin() + mid_index);
        return search(v, key);
    } else {
        vector<int> v(arr.begin() + mid_index + 1, arr.end());
        auto found_index = search(v, key);
        if (found_index < 0) {
            return found_index;
        } else {
            return mid_index + 1 + found_index;
        }
    }

    return -1; 
  }
};

int main(int argc, char* argv[]) {
  cout << BinarySearch::search(vector<int>{4, 6, 10}, 10) << endl;
  cout << BinarySearch::search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 10) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 4) << endl;
}

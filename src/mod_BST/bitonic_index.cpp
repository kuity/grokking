using namespace std;

#include <iostream>
#include <vector>

class SearchBitonicArray {
 public:
  static int search(const vector<int> &arr, int key) {
    // first find the max index in array
    int low = 0;
    int sz = arr.size();
    int high = sz-1;

    while(low < high) {
        auto m = low + (high-low)/2;
        auto M = arr[m];
        auto M_right = arr[m+1];
        if (M_right > M) { // ascending
            low = m+1;
        } else { // descending
            high = m;
        } 
    }

    auto max_index = low;
    // first search ascending part of array
    low = 0;
    high = max_index;
    while(low <= high) {
        auto m = low + (high-low)/2;
        auto M = arr[m];
        if (M == key) {
            return m;
        }
        if (key < M) {
            high = m-1;
        } else {
            low = m+1;
        }
    }

    // next search descending part of array
    low = max_index;
    high = sz-1;
    while(low <= high) {
        auto m = low + (high-low)/2;
        auto M = arr[m];
        if (M == key) {
            return m;
        }
        if (key < M) {
            low = m+1;
        } else {
            high = m-1;
        }
    }

    return -1;
  }
};

int main(int argc, char *argv[]) {
  cout << SearchBitonicArray::search(vector<int>{1, 3, 8, 4, 3}, 4) << endl;
  cout << SearchBitonicArray::search(vector<int>{3, 8, 3, 1}, 8) << endl;
  cout << SearchBitonicArray::search(vector<int>{1, 3, 8, 12}, 12) << endl;
  cout << SearchBitonicArray::search(vector<int>{10, 9, 8}, 10) << endl;
}
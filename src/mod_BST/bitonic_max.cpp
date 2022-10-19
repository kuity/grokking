using namespace std;

#include <iostream>
#include <vector>

// 1 3 8 12 4 2
// l=0, h=5, m=2. 
// M=8. M-1=3. M+1=12.
// M+1 > M-1 => search M to h
// M-1 > M+1 => search l to M
// size leq 3 => return max

class MaxInBitonicArray {
 public:
  static int findMax(const vector<int>& arr) {
    int low = 0;
    int sz = arr.size();
    int high = sz-1;

    while(low < high) {
        cout << "low: " << low << ", high: " << high << endl;

        auto m = low + (high-low)/2;
        auto M = arr[m];
        auto M_right = arr[m+1];
        if (M_right > M) { // ascending
            low = m+1;
        } else { // descending
            high = m;
        } 
    }

    // the loop ends when low = high, so arr[low] = arr[high] = max elem in array
    return arr[low];
  }

};

int main(int argc, char* argv[]) {
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12, 4, 2}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{3, 8, 3, 1}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{10, 9, 8}) << endl;
}
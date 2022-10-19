using namespace std;

#include <iostream>
#include <vector>
#include <limits>

class RotationCountOfRotatedArray {
 public:
  static int countRotations(const vector<int>& arr) {
    // search for the index of the samllest elem;
    int low = 0;
    int sz = arr.size();
    int high = sz-1;

    // if there no rotations, defaults are already correct
    int least = arr[low];
    int least_index = 0;

    // If low == high, low must be the least_index
    while(low < high) {
        auto d = high-low;
        auto m = low + d/2;
        if (d%2==1) {
            m+=1;
        }
        cout << "low: " << low << ", high: " << high << ", mid: " << m << endl;
        auto M = arr[m];
        auto L = arr[low];

        // if M > L, min elem could be L or in M+1-H
        // thus, we will just check L then search M+1-H
        if (M > L) {
            if (L < least) {
                least = L;
                least_index = low;
            }
            low = m+1;
        }
        // if M < L, min elem must be in L-M (all elems after M has to be greater than M)
        // thus, we can check M then search L-(M-1)
        else if (M < L) {
            if (M < least) {
                least = M;
                least_index = m;
            }
            high = m-1;
        }
    }

    if (arr[low] < least) {
        least = arr[low];
        least_index = low;
    }

    return least_index;
  }
};

int main(int argc, char* argv[]) {
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{10, 15, 1, 3, 8}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{4, 5, 7, 9, 10, -1, 2}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{1, 3, 8, 10}) << endl;
}

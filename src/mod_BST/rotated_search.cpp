using namespace std;

#include <iostream>
#include <vector>

// if rotated, it contains 2 ascending arrays
// compare "mid" and "low"
// no matter how array is "chopped", shape is same. (up->down->up OR up)

class SearchRotatedArray {
 public:
  static int search(const vector<int>& arr, int key) {
    // TODO: Write your code here
    int low = 0;
    int sz = arr.size();
    int high = sz-1;


    while(low <= high) {
        auto d = high-low;
        auto m = low + d/2;
        if (d%2==1) {
            m+=1;
        }
        cout << "low: " << low << ", high: " << high << ", mid: " << m << endl;
        auto M = arr[m];
        auto L = arr[low];
        if (key == M) {
            return m;
        }


        if (M > L && key > M) {
            low = m+1;
        } else if (M > L && key < M && key >= L) {
            high = m-1;
        } else if (M > L && key < L) {
            low = m+1;
        } else if (M < L && key < M) {
            high = m-1;
        } else if (M < L && key > M && key < L) {
            low = m+1;
        } else if (M < L && key >= L) {
            high = m-1;
        }
    }

    return -1;
  }
};

int main(int argc, char* argv[]) {
  cout << SearchRotatedArray::search(vector<int>{10, 15, 1, 3, 8}, 15) << endl;
  cout << SearchRotatedArray::search(vector<int>{4, 5, 7, 9, 10, -1, 2}, 10) << endl;
}
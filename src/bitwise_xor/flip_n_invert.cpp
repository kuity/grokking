#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
  public:
    static int complement(int n, int digits) {
        auto complement = n;
        int ones = pow(2, digits)-1;
        return complement ^ ones;
    }

    static vector<vector<int>> flipAndInvertImage(vector<vector<int>> arr) {
      auto sz = arr.size();
      for (auto h=0; h<sz; h++) {
        auto num = 0;
        for (auto i=0; i<sz; i++) {
            // cout << v[i];
            num += arr[h][i] * pow(2, i);
        }
        // cout << endl;
        // cout << num << endl;
        auto c = complement(num, sz);
        for (auto j=0; j<sz; j++) {
            arr[h][sz-j-1] = c & 1;
            c = c >> 1;
        }
      }
      return arr;
    }

    static void print(const vector<vector<int>> arr) {
      for(int i=0; i < arr.size(); i++) {
        for (int j=0; j < arr[i].size(); j++) {
          cout << arr[i][j] << " ";
        }
        cout << endl;
      }
    }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> arr = vector<vector<int>>{{1, 0, 1}, {1, 1, 1}, {0, 1, 1}};
  Solution::print(Solution::flipAndInvertImage(arr));
  cout << endl;

  vector<vector<int>> arr2 = vector<vector<int>>{{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
  Solution::print(Solution::flipAndInvertImage(arr2));
}
using namespace std;

#include <iostream>
#include <vector>

class TargetSum {
 public:
  int findTargetSubsets(const vector<int> &num, int s) {
    auto total = 0;
    for (auto x: num) {total+=x;}
    if (s > total) {return 0;}
    vector<vector<int>> dp (num.size(), vector<int>(total+1));

    // i: index of num
    // j: number of subsets that adds up to j
    for (int i=0; i<num.size(); i++) {
        for (int j=0; j<total+1; j++) {
            // if sum is 0, only {} adds up to 0
            if (j==0) {
                dp[i][j] = 1;
                continue;
            }

            auto value = num[i];
            if (i==0) {
                if (j==value || j==-value) {
                    dp[i][j] = 1;
                }  else {
                    dp[i][j] = 0;
                }
                continue;
            }

            auto num_subsets = 0;
            // if we can add +j to subset
            if (value <= j) {
                num_subsets += dp[i-1][j-value];
            }

            // if we can add -j to subset
            if (j + value <= total) {
                num_subsets += dp[i-1][j+value];
            }

            dp[i][j] = num_subsets;
        }
    }

    return dp[num.size()-1][s];
  }
};

int main(int argc, char *argv[]) {
  TargetSum ts;
  vector<int> num = {1, 1, 2, 3};
  cout << ts.findTargetSubsets(num, 1) << endl;
  num = vector<int>{1, 2, 7, 1};
  cout << ts.findTargetSubsets(num, 9) << endl;
}
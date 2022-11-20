using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
 public:
  virtual bool canPartition(const vector<int> &num, int sum) {
    auto total = 0;
    for (auto i: num) { total += i; }
    if (sum > total) { return false; }

    vector<vector<bool>> dp(num.size(), vector<bool>(sum+1));
    for (auto i=0; i<num.size(); i++) {
        for (auto j=0; j<sum+1; j++) {
            // for index = 0, true only value is equal to sum
            if (i==0) {
                dp[i][j] = (num[i] == j);
                continue;
            }

            // option 1: value is included
            bool opt1;
            if (num[i] > j) {
                opt1 = false;
            } else {
                opt1 = dp[i-1][j-num[i]];
            }

            // option 2: value is excluded
            bool opt2 = dp[i-1][j];
            dp[i][j] = opt1 || opt2;
        }
    }

    // final answer is at the bottom right
    return dp[num.size()-1][sum];
  }
};

int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 2, 3, 7};
  cout << ss.canPartition(num, 6) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.canPartition(num, 10) << endl;
  num = vector<int>{1, 3, 4, 8};
  cout << ss.canPartition(num, 6) << endl;
}
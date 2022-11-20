using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
 public:
  static int countSubsets(const vector<int> &num, int sum) {
    auto total = 0;
    for (auto n: num) { total+=n; }
    if (sum > total) { return 0; }

    vector<vector<int>> dp (num.size(), vector<int>(sum+1));

    // i: index of num
    // j: number of distinct subsets that has subset sum equals to j
    for (int i=0; i<num.size(); i++) {
        for (int j=0; j<sum+1; j++) {
            // if subset sum = 0, there is exactly 1 distinct set: {} that adds to 0
            if (j==0) {
                dp[i][j] = 1;
                continue;
            }

            auto value = num[i];    
            // if index is 0, it can only form 1 subset sum = num[i]
            if (i==0) {
                if (j==value) { 
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
                continue;
            }

            // if value at index should be excluded, num subsets is just the previous index
            auto excluded = dp[i-1][j];

            // if value at index should be included in subset
            // problem: there could be overlap
            if (value > j) {
                dp[i][j] = excluded;
            } else {
                dp[i][j] = excluded + dp[i-1][j-value];
            }
        }
    }

    // check the dp
    // for (int i=0; i<num.size(); i++) {
    //     for (int j=0; j<sum+1; j++) {
    //         cout << "i=" << i << ",j=" << j << ",num of subsets=" << dp[i][j] << endl;
    //     }
    // }

    return dp[num.size()-1][sum];
  }
};

int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 1, 2, 3};
  cout << ss.countSubsets(num, 4) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.countSubsets(num, 9) << endl;
}

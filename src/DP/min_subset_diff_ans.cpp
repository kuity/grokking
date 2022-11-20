using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class PartitionSet {
 public:
  int canPartition(const vector<int> &num) { 
    
    // problem framing: 
    // for the x-axis, it represents whether "x" is a possible subset sum
    // we can maintain x value from 1 to s/2
    // if s/2 subset sum possible, the subset difference is 0 (optimal)
    // conversely, there's no need to go higher than s/2
    // eg. if s/2-1 is possible, then s/2+1 is possible, thus there's no need to calculate for s/2+1
    // finally, we can just take the rightmost x for which value is "true"
    auto s = 0; // sum of all elements in list
    for (auto x: num) {s+=x;}
    auto xlen = s/2+1;
    vector<vector<bool>> dp (num.size(), vector<bool>(xlen));
    int greatest;

    // define "i" as the index of element in num
    // define "j" as subset sum of the first partition
    for (auto i=0; i<num.size(); i++) {
        for (auto j=0; j<xlen; j++) {
            auto value = num[i];

            // 0 subset sum is possible in any scenario
            if (j==0) {
                dp[i][j] = true;
                greatest = 0;
                continue;
            }

            // if only first index considered, then only j=value is possible
            if (i==0) {
                dp[i][j] = value == j;
                continue;
            }

            // opt 1: exclude the element -> j does not change
            auto excluded = dp[i-1][j];

            // opt 2: include the element -> check if exceed cap
            if (value > j) {
                dp[i][j] = excluded;
            } else {
                auto included = dp[i-1][j-value];
                dp[i][j] = excluded || included;
            }

            if (dp[i][j]) {
                greatest = j;
            }
        }
    }

    // greatest possible subset sum between 0 and s/2 => derive smallest diff
    return (s-greatest) - greatest; 
  }
};

int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 9};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 3, 100, 4};
  cout << ps.canPartition(num) << endl;
}
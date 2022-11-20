using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class PartitionSet {
 public:
  int canPartition(const vector<int> &num) { 
    auto s = 0; // sum of all elements in list
    for (auto x: num) {s+=x;}
    
    // in the dp, can maintain a pair(a, b). a=>sum in bag 1, b=>sum in bag 2, which gives the min diff
    vector<vector<pair<int, int>>> dp (num.size(), vector<pair<int, int>>(s+1));

    // define "i" as the index of element in num
    // define "j" as the capacity of partition 1
    for (auto i=0; i<num.size(); i++) {
        for (auto j=0; j<s+1; j++) {
            auto value = num[i];
            if (i==0) {
                // doesn't matter which partition it goes
                dp[i][j] = make_pair(0, value);
                continue;
            }
            
            // if the capacity of partition 1 is 0, all element must go to partition 2
            if (j==0) {
                dp[i][j] = make_pair(0, value+dp[i-1][j].second);
                continue;
            }

            // opt 1: exclude the element -> check the previous index
            auto excluded = make_pair(dp[i-1][j].first, dp[i-1][j].second+value);
            auto excluded_diff = abs(excluded.first - excluded.second);
            pair<int, int> current;

            // opt 2: include the element -> check if exceed cap
            if (value > j) {
                current = excluded;
            } else {
                auto included = make_pair(dp[i-1][j-value].first + value, dp[i-1][j-value].second);
                auto included_diff = abs(included.first - included.second);
                if (excluded_diff > included_diff) {
                    current = included;
                } else {
                    current = excluded;
                }
            }
            auto current_min = abs(current.first - current.second);

            // opt 3: check whether previous "capacity" with same index has smaller minimum
            auto prev = dp[i][j-1];
            auto prev_min = abs(prev.first - prev.second);
            if (current_min < prev_min) {
                dp[i][j] = current;
            } else {
                dp[i][j] = prev;
            }
        }
    }

    auto m = dp[num.size()-1][s];
    return abs(m.first-m.second); 
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
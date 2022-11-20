using namespace std;

#include <iostream>
#include <vector>

// space optimization
class Knapsack {
 public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
    // basic checks
    if (capacity <= 0 || profits.empty() || weights.size() != profits.size()) {
      return 0;
    }

    int n = profits.size();
    // we only need one previous row to find the optimal solution, overall we need '2' rows
    // the above solution is similar to the previous solution, the only difference is that
    // we use `i%2` instead if `i` and `(i-1)%2` instead if `i-1`
    vector<vector<int>> dp(2, vector<int>(capacity + 1));

    // if we have only one weight, we will take it if it is not more than the
    // capacity
    for (int c = 0; c <= capacity; c++) {
      if (weights[0] <= c) {
        dp[0][c] = dp[1][c] = profits[0];
      }
    }

    // process all sub-arrays for all the capacities
    for (int i = 1; i < n; i++) {
      for (int c = 0; c <= capacity; c++) {
        int profit1 = 0, profit2 = 0;
        // include the item, if it is not more than the capacity
        if (weights[i] <= c) {
          profit1 = profits[i] + dp[(i - 1) % 2][c - weights[i]];
        }
        // exclude the item
        profit2 = dp[(i - 1) % 2][c];
        // take maximum
        dp[i % 2][c] = max(profit1, profit2);
      }
    }

    return dp[(n - 1) % 2][capacity];
  }
};

int main(int argc, char *argv[]) {
  Knapsack ks;
  vector<int> profits = {1, 6, 10, 16};
  vector<int> weights = {1, 2, 3, 5};
  cout << ks.solveKnapsack(profits, weights, 7) << endl;
  cout << ks.solveKnapsack(profits, weights, 6) << endl;
}
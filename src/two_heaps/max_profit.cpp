// capital: [a b c]
// profit: [x y z]
// capital & profit: [(a,x), (b,y), (c,z)] -> dump into h2

// h1 -> highest prof  h2 -> lowest capital
// let current capital = cap
// loop h2.pop => h1.push iff h2.top <= cap (step 1)
// h1.pop(1)
// update(cap)
// goto step 1

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class MaximizeCapital {
 public:
  static int findMaximumCapital(const vector<int> &capital, const vector<int> &profits,
                                int numberOfProjects, int initialCapital) {
    auto n_proj = capital.size();
    auto lessProfit = [](vector<int> a, vector<int> b) { return a[1] < b[1]; };
    priority_queue<vector<int>, vector<vector<int>>, decltype(lessProfit)> q_profits(lessProfit);
    auto moreCapital = [](vector<int> a, vector<int> b) { return a[0] > b[0]; };
    priority_queue<vector<int>, vector<vector<int>>, decltype(moreCapital)> q_capital(moreCapital);

    for (auto i=0; i<n_proj; i++) {
        vector<int> v{capital[i], profits[i]};
        q_capital.push(v);
    }

    auto done_projects = 0;
    auto cur_capital = initialCapital;
    while(done_projects < numberOfProjects) {
        cout << "current capital is " << cur_capital << endl;
        while(q_capital.size() > 0 && q_capital.top()[0] <= cur_capital) {
            q_profits.push(q_capital.top());
            q_capital.pop();
        }
        auto x = q_profits.top();
        cur_capital += x[1];
        q_profits.pop();
        done_projects++;
    }
    return cur_capital;
  }
};

int main(int argc, char *argv[]) {
  int result =
      MaximizeCapital::findMaximumCapital(vector<int>{0, 1, 2}, vector<int>{1, 2, 3}, 2, 1);
  cout << "Maximum capital: " << result << endl;
  result =
      MaximizeCapital::findMaximumCapital(vector<int>{0, 1, 2, 3}, vector<int>{1, 2, 3, 5}, 3, 0);
  cout << "Maximum capital: " << result << endl;
}

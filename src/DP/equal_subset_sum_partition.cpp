using namespace std;

#include <iostream>
#include <vector>

// soln here: BF maintaining a capacity of (s/2, s/2)
// subqn: able to partition with a cap of (x-weight, y) or (x, y-weight)?
// optimization: actually we can represent capacity as s/2
// if there exists subset that is exactly equal to s/2, the other subset must also be s/2
// then, can just use same bottom-up DP approach as 0/1 knapsack problem
class PartitionSet {
 public:
  bool canPartition(const vector<int> &num) {
    int s = 0;
    for (auto x: num) {
        s+=x;
    }
    if (s%2!=0) {
        return false;
    }

    cout << "capacity is " << s/2 << endl;
    return this->partRecursive(num, 0, make_pair(s/2, s/2));
  }

 private:
  bool partRecursive(const vector<int> &num, int index, pair<int, int> cap) {
    if (index == num.size()) {
        return cap.first == 0 && cap.second == 0;
    }
    if (cap.first < 0 || cap.second < 0) {
        return false;
    }

    auto weight = num[index];
    if (cap.first == cap.second) {
        return partRecursive(num, index+1, make_pair(cap.first-weight, cap.second));
    } else {
        auto opt1 = partRecursive(num, index+1, make_pair(cap.first-weight, cap.second));
        auto opt2 = partRecursive(num, index+1, make_pair(cap.first, cap.second-weight));
        return opt1 || opt2;
    }
  }
};

int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 4};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 1, 3, 4, 7};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{2, 3, 4, 6};
  cout << ps.canPartition(num) << endl;
}

using namespace std;

#include <iostream>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) { val = x; }
};

class CountUniqueTrees {
 private:
  static int helper(int lower, int higher) {
    if (lower >= higher) {
        return 1; // it's either a null pointer or a leaf node
    }

    auto count = 0;
    for (auto i=lower;i<=higher;i++) {

        auto left_trees = helper(lower, i-1);
        auto right_trees = helper(i+1, higher);

        // add the number of combinations of left and right trees to total
        count += (left_trees*right_trees);
    }

    return count;
  }

 public:
  int countTrees(int n) {
    int count = 0;
    count = helper(1, n);
    return count;
  }
};

int main(int argc, char *argv[]) {
  CountUniqueTrees ct;
  int count = ct.countTrees(3);
  cout << "n = 3, Total trees: " << count << endl;
  cout << "n = 2, Total trees: " << ct.countTrees(2) << endl;
  cout << "n = 4, Total trees: " << ct.countTrees(4) << endl;
}
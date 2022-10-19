using namespace std;

#include <iostream>
#include <vector>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) { val = x; }
};

class UniqueTrees {
 private:
  static vector<TreeNode *> helper(int lower, int higher) {
    if (lower >= higher) {
        return vector<TreeNode *> {};
    }

    else if (lower == higher) {
        auto r = TreeNode(lower);
        vector<TreeNode *> v { &r };
        return v;
    }

    vector<TreeNode *> res {};
    for (auto i=lower;i<=higher;i++) {
        vector<TreeNode> temp {};

        auto left_trees = helper(lower, i-1);
        auto right_trees = helper(i+1, higher);

        for (auto t: left_trees) {
            auto r = TreeNode(i);
            r.left = t;
            temp.push_back(r);
        }
        if (temp.size() == 0) {
            temp.push_back(TreeNode(i));
        }
        for (auto r: temp) {
            for (auto t: right_trees) {
                r.right = t;
                res.push_back(&r);
            }
            if (right_trees.size() == 0) {
                res.push_back(&r);
            }
        }
    }

    return res;
  }

 public:
  static vector<TreeNode *> findUniqueTrees(int n) {
    vector<TreeNode *> result;
    // TODO: Write your code here
    result = helper(1, n);
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<TreeNode *> result = UniqueTrees::findUniqueTrees(2);
  cout << "Total trees: " << result.size() << endl;

  result = UniqueTrees::findUniqueTrees(3);
  cout << "Total trees: " << result.size() << endl;
}

using namespace std;

#include <iostream>
#include <vector>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class CountAllPathSum {
 private:
  static int helper(TreeNode *root, int cur, int s) {
    if (root == nullptr) {
        return 0;
    }

    // case 1: check current + val == s
    // case 2: check children with new path

    auto with_pathSum = cur + root->val;

    if (root->left == nullptr && root->right == nullptr) {
        return with_pathSum == s;
    } else {
        auto newPathSum = helper(root->left, 0, s) + helper(root->right, 0 , s);
        if (with_pathSum == s) {
            return 1 + newPathSum;
        } else if (with_pathSum < s) {
            return newPathSum + helper(root->left, with_pathSum, s) + helper(root->right, with_pathSum , s);
        } else {
            return newPathSum;
        }
    }
  }

 public:
  static int countPaths(TreeNode *root, int S) {
    if (root == nullptr) {
        return 0;
    }
    return helper(root, 0, S);
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << CountAllPathSum::countPaths(root, 11) << endl;
}

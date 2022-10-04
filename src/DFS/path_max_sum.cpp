#include <iostream>
#include <limits>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class MaximumPathSum {
 private:
  static int helper(TreeNode *root, int &maxSum) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return root->val;
    } else {
        // ignore "negative" paths
        auto left_pathSum = max(helper(root->left, maxSum), 0);
        auto right_pathSum = max(helper(root->right, maxSum), 0);
        maxSum = max(maxSum, left_pathSum + right_pathSum + root->val);
        return max(left_pathSum, right_pathSum) + root->val;
    }
  }

 public:
  static int findMaximumPathSum(TreeNode *root) {
    int maxSum = root->val;
    auto _ = helper(root, maxSum);
    return maxSum;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
  
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->right->left->left = new TreeNode(7);
  root->right->left->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
  
  root = new TreeNode(-1);
  root->left = new TreeNode(-3);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
}

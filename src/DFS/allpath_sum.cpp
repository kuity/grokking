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

class SumOfPathNumbers {
 private:
  static void helper(TreeNode *root, string num, vector<string> *v) {
    if (root == nullptr) {
        return;
    }

    auto nxt_num = num + to_string(root->val);
    if (root->left == nullptr && root->right == nullptr) {
        (*v).push_back(nxt_num);
        return;
    } else {
        helper(root->left, nxt_num, v);
        helper(root->right, nxt_num, v);
        return;
    }
  }

 public:
  static int findSumOfPathNumbers(TreeNode *root) {
    int totalPathsSum = 0;
    vector<string> v{};
    helper(root, "", &v);
    for(auto s: v) {
        totalPathsSum += stoi(s);
    }

    return totalPathsSum;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);
  cout << "Total Sum of Path Numbers: " << SumOfPathNumbers::findSumOfPathNumbers(root) << endl;
}

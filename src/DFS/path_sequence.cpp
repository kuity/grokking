#include <iostream>
#include <vector>

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

class PathWithGivenSequence {
 private:
  static bool helper(TreeNode *root, vector<int> seq, const vector<int> &sequence) {
    if (root == nullptr) {
        return false;
    }

    seq.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr) {
        return seq == sequence;
    } else {
        return helper(root->left, seq, sequence) || helper(root->right, seq, sequence);
    }
  }

 public:
  static bool findPath(TreeNode *root, const vector<int> &sequence) {
    vector<int> v{};
    return helper(root, v, sequence);
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);

  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 0, 7})
       << endl;
  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 1, 6})
       << endl;
}
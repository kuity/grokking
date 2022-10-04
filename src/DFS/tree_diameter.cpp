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

// return (longest diameter, long path length)
// if null, diameter thru self = -1 (invalid), longest path = 1 (found leaf)
// if not null, check left -> (diam_left, longest_left), right -> (diam_right, longest_right)
class TreeDiameter {
 private:
  static vector<int> helper(TreeNode *root) {
    vector<int> v {0, 0}; // longest diameter, longest path length
    if (root == nullptr) {
        return v;
    }

    if (root->left == nullptr && root->right == nullptr) {
        v[1] = 1;
        return v;
    } else {
        auto left_v = helper(root->left);
        auto right_v = helper(root->right);
        v[1] = max(left_v[1], right_v[1]) + 1;

        auto diam_with_self = 0;
        // check if there is legit path on left and right; yes then calc diam
        if (left_v[1] > 0 && right_v[1] >> 0) {
            diam_with_self = left_v[1] + right_v[1] + 1;
        } 
        
        v[0] = max(max(left_v[0], right_v[0]), diam_with_self);
        return v;
    }
  }

 public:
  static int findDiameter(TreeNode *root) {
    // int treeDiameter = 0;
    auto res = helper(root);
    return res[0];
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;
  root->left->left = nullptr;
  root->right->left->left = new TreeNode(7);
  root->right->left->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  root->right->left->right->left = new TreeNode(10);
  root->right->right->left->left = new TreeNode(11);
  cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;
}
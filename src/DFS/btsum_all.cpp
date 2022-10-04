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

class FindAllTreePaths {
 public:
  static vector<vector<int>> findPaths(TreeNode *root, int sum) {
    vector<vector<int>> allPaths;
    if (root == nullptr) {
        return allPaths;
    }
    auto remainder = sum - root->val;

    if (remainder == 0 && root->left == nullptr && root->right == nullptr) {
        vector<int> v{root->val};
        allPaths.push_back(v);
        return allPaths;
    } else {
        auto vl = findPaths(root->left, remainder);
        auto vr = findPaths(root->right, remainder);
        for (auto v: vl) {
            v.push_back(root->val);
            allPaths.push_back(v);
        }
        for (auto v: vr) {
            v.push_back(root->val);
            allPaths.push_back(v);
        }
    }

    return allPaths;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  int sum = 23;
  vector<vector<int>> result = FindAllTreePaths::findPaths(root, sum);
  cout << "Tree paths with sum " << sum << ": " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
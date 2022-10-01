using namespace std;

#include <iostream>
#include <queue>
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

class ZigzagTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    queue<TreeNode *> nodes;
    nodes.push(root);
    auto sz = nodes.size();
    bool r2l = false; // traverse right to left
    while(sz > 0) {
        vector<int> v;
        for (auto i=0; i<sz; i++) {
            auto n = nodes.front();
            auto l = n->left;
            auto r = n->right;
            if (r2l) {
                v.emplace(v.begin(), n->val);
            } else {
                v.push_back(n->val);
            }
            if (l != nullptr) {
                nodes.push(l);
            }
            if (r != nullptr) {
                nodes.push(r);
            }           
            nodes.pop();
        }

        result.push_back(v);
        sz = nodes.size();
        r2l = !r2l;
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  root->right->left->left = new TreeNode(20);
  root->right->left->right = new TreeNode(17);
  vector<vector<int>> result = ZigzagTraversal::traverse(root);
  cout << "Zigzag traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
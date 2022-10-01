using namespace std;

#include <iostream>
#include <queue>

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

class LevelOrderTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    vector<TreeNode *> nodes{root};
    auto sz = nodes.size();
    while(sz > 0) {
        vector<int> v;
        for (auto i=0; i<sz; i++) {
            auto n = nodes.front();
            auto l = n->left;
            auto r = n->right;
            v.push_back(n->val);
            if (l != nullptr) {
                nodes.push_back(l);
            }
            if (r != nullptr) {
                nodes.push_back(r);
            }           
            nodes.erase(nodes.begin());
        }
        result.push_back(v);
        sz = nodes.size();
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
  vector<vector<int>> result = LevelOrderTraversal::traverse(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
using namespace std;

#include <deque>
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

class ReverseLevelOrderTraversal {
 public:
  static deque<vector<int>> traverse(TreeNode *root) {
    deque<vector<int>> result;
    queue<TreeNode *> nodes;
    nodes.push(root);
    auto sz = nodes.size();
    while(sz > 0) {
        vector<int> v;
        for (auto i=0; i<sz; i++) {
            auto n = nodes.front();
            auto l = n->left;
            auto r = n->right;
            v.push_back(n->val);
            if (l != nullptr) {
                nodes.push(l);
            }
            if (r != nullptr) {
                nodes.push(r);
            }           
            nodes.pop();
        }
        result.push_front(v);
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
  auto result = ReverseLevelOrderTraversal::traverse(root);

  cout << "Reverse level order traversal: ";
  for (auto que : result) {
    for (auto num : que) {
      cout << num << " ";
    }
    cout << endl;
  }
}
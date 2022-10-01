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

class MinimumBinaryTreeDepth {
 public:
  static int findDepth(TreeNode *root) {
    queue<TreeNode *> nodes;
    nodes.push(root);
    auto sz = nodes.size();
    int depth = 1;
    while(sz > 0) {
        double s = 0;
        for (auto i=0; i<sz; i++) {
            auto n = nodes.front();
            auto l = n->left;
            auto r = n->right;
            auto children = 0;
            if (l != nullptr) {
                nodes.push(l);
                children++;
            }
            if (r != nullptr) {
                nodes.push(r);
                children++;
            }
            if (children == 0) {
              return depth;
            }
            nodes.pop();
        }
        depth++;
        sz = nodes.size();
    }

    return -1;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
  root->left->left = new TreeNode(9);
  root->right->left->left = new TreeNode(11);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
}
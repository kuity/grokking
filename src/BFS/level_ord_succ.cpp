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

class LevelOrderSuccessor {
 public:
  static TreeNode *findSuccessor(TreeNode *root, int key) {
    queue<TreeNode *> nodes;
    nodes.push(root);
    auto sz = nodes.size();
    bool found_key = false;
    while(sz > 0) {
        double s = 0;
        for (auto i=0; i<sz; i++) {
            auto n = nodes.front();
            auto l = n->left;
            auto r = n->right;

            if (found_key) {
                return n;
            }
            if (n->val == key) {
                found_key = true;
            }
            if (l != nullptr) {
                nodes.push(l);
            }
            if (r != nullptr) {
                nodes.push(r);
            }           
            nodes.pop();
        }

        sz = nodes.size();
    }

    return nullptr;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  TreeNode *result = LevelOrderSuccessor::findSuccessor(root, 3);
  if (result != nullptr) {
    cout << result->val << " " << endl;
  }
  
  root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  
  result = LevelOrderSuccessor::findSuccessor(root, 9);
  if (result != nullptr) {
    cout << result->val << " " << endl;
  }
  
  result = LevelOrderSuccessor::findSuccessor(root, 12);
  if (result != nullptr) {
    cout << result->val << " " << endl;
  }
}

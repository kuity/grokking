using namespace std;

#include <iostream>
#include <queue>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;

  TreeNode(int x) {
    val = x;
    left = right = next = nullptr;
  }

  // tree traversal using 'next' pointer
  virtual void printTree() {
    TreeNode *current = this;
    cout << "Traversal using 'next' pointer: ";
    while (current != nullptr) {
      cout << current->val << " ";
      current = current->next;
    }
  }
};

class ConnectAllSiblings {
 public:
  static void connect(TreeNode *root) {
    queue<TreeNode *> nodes;
    nodes.push(root);
    auto sz = nodes.size();
    TreeNode * prev = nullptr;
    while(sz > 0) {
        for (auto i=0; i<sz; i++) {
            auto n = nodes.front();
            auto l = n->left;
            auto r = n->right;
            if (l != nullptr) {
                nodes.push(l);
            }
            if (r != nullptr) {
                nodes.push(r);
            }
            nodes.pop();
            if (prev != nullptr) {
                prev->next = n;
            }
            prev = n;
        }
        sz = nodes.size();
    }
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  ConnectAllSiblings::connect(root);
  root->printTree();
}

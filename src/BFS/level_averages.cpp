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

class LevelAverage {
 public:
  static vector<double> findLevelAverages(TreeNode *root) {
    vector<double> result;

    queue<TreeNode *> nodes;
    nodes.push(root);
    auto sz = nodes.size();
    while(sz > 0) {
        double s = 0;
        for (auto i=0; i<sz; i++) {
            auto n = nodes.front();
            auto l = n->left;
            auto r = n->right;
            s+=n->val;
            if (l != nullptr) {
                nodes.push(l);
            }
            if (r != nullptr) {
                nodes.push(r);
            }           
            nodes.pop();
        }

        result.push_back(s/sz);
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
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<double> result = LevelAverage::findLevelAverages(root);
  cout << "Level averages are: ";
  for (auto num : result) {
    cout << num << " ";
  }
}

//
// Created by ruoting on 2019/11/17.
//

#ifndef CODING_TREENODE_H
#define CODING_TREENODE_H
#include "Solution.h"
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class TreeNodeSolution : public Solution {
 public:
  void Test() override;
  bool isSameTree(TreeNode *p, TreeNode *q) {
    // 递归解法，前序遍历
    if (p && q) {
      if (p->val == q->val) {
        if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
          return true;
        } else {
          return false;
        }
      } else {
        return false;
      }
    } else {
      return !p && !q;
    }
  }
};

#endif //CODING_TREENODE_H

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
/* 广度优先用队列
 * 深度优先用栈
 * */
class TreeNodeSolution : public Solution {
 public:
  void Test() override;
  // *************** Start of HOT  *****************//
  vector<int> inorderTraversal(TreeNode *root) {
    // 中序遍历，左，中，右，深度优先
    vector<int> ans;
    stack<TreeNode *> helper;
    while (true) {
      // go to the deepest left
      while (root) {
        helper.push(root);
        root = root->left;
      }
      if (helper.empty()) {
        break;
      }
      // 根节点
      root = helper.top();
      helper.pop();
      ans.emplace_back(root->val);
      //下一轮遍历右子树
      root = root->right;
    }
    return ans;
  }
// *************** End of HOT  *****************//


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

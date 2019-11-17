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
  // 中序遍历，左，中，右，深度优先
  vector<int> inorderTraversal(TreeNode *root) {
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
  // 对称二叉树，类似广度优先思路，每次拿2个节点并比较，
  // 之后将两个节点的左右子节点按相反的顺序插入队列中
  bool isSymmetric(TreeNode *root) {
    if (!root) {
      return true;
    }
    deque<TreeNode *> helper;
    helper.push_back(root->left);
    helper.push_back(root->right);
    while (!helper.empty()) {
      auto val1 = helper.front();
      helper.pop_front();
      auto val2 = helper.front();
      helper.pop_front();
      if (val1 && val2 && val1->val == val2->val) {
        helper.push_back(val1->right);
        helper.push_back(val2->left);
        helper.push_back(val1->left);
        helper.push_back(val2->right);
      } else {
        if (!val1 && !val2) {
          continue;
        } else {
          return false;
        }
      }
    }
    return true;
  }
  // 层次遍历
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;

    deque<TreeNode *> helper;
    if (root) {
      helper.push_back(root);
    }
    // 队列中每次保存二叉树一层的节点指针
    while (!helper.empty()) {
      vector<int> layer_result;
      // 开始遍历本层时，记录本层节点数，作为本层遍历完毕的条件
      auto size = helper.size();
      for (auto i = 0; i < size; ++i) {
        auto val = helper.front();
        helper.pop_front();
        layer_result.push_back(val->val);
        if (val->left) {
          helper.push_back(val->left);
        }
        if (val->right) {
          helper.push_back(val->right);
        }
      }
      ans.push_back(layer_result);
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

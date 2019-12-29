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
//有两种通用的遍历树的策略：
//
//1 广度优先搜索（BFS），用队列
//我们按照高度顺序一层一层的访问整棵树，高层次的节点将会比低层次的节点先被访问到。
//
//2 深度优先搜索（DFS）， 用栈
//在这个策略中，我们采用深度作为优先级，以便从跟开始一直到达某个确定的叶子，然后再返回根到达另一个分支。
//深度优先搜索策略又可以根据根节点、左孩子和右孩子的相对顺序被细分为前序遍历，中序遍历和后序遍历


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

    // 对称二叉树 递归算法
    bool isSymmetric(TreeNode *a, TreeNode *b) {
        if (!a && !b) {
            return true;
        }
        if (a && b) {
            return (a->val == b->val) && isSymmetric(a->left, b->right) &&
                   isSymmetric(a->right, b->left);
        } else {
            return false;
        }
    }

    bool isSymmetric(TreeNode *root) {
        return isSymmetric(root, root);
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

    // 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数
    int maxDepth_Recursive(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return 1 + max(maxDepth_Recursive(root->left),
                       maxDepth_Recursive(root->right));
    }

    int maxDepth_BFS(TreeNode *root) {
        // 层次遍历，遍历到最后一层的时候，深度也得到了。
        if (!root) {
            return 0;
        }
        int ans = 0;
        deque<TreeNode *> helper;
        helper.push_back(root);
        while (!helper.empty()) {
            ans++;
            auto num = helper.size();
            for (auto i = 0; i < num; ++i) {
                auto node = helper.front();
                helper.pop_front();
                if (node->left) {
                    helper.push_back(node->left);
                }
                if (node->right) {
                    helper.push_back(node->right);
                }
            }
        }
        return ans;
    }

//   华为面试题
//   根据一棵树的前序遍历与中序遍历构造二叉树。 注意:你可以假设树中没有重复的元素
//   思路：先序遍历的顺序是根节点，左子树，右子树。中序遍历的顺序是左子树，根节点，右子树。
//    所以我们只需要根据先序遍历得到根节点，然后在中序遍历中找到根节点的位置，
//    它的左边就是左子树的节点，右边就是右子树的节点。
//    生成左子树和右子树就可以递归的进行了。
    TreeNode *
    buildTree(vector<int> &preorder, std::unordered_map<int, int> &value_idx,
              int left,
              int right, int &pre_idx) {
        if (left == right) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[pre_idx++]);
        auto root_idx = value_idx[root->val];
        root->left = buildTree(preorder, value_idx, left, root_idx,
                               pre_idx);
        root->right = buildTree(preorder, value_idx, root_idx + 1,
                                right, pre_idx);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        std::unordered_map<int, int> value_idx;
        for (auto i = 0; i < inorder.size(); ++i) {
            value_idx[inorder[i]] = i;
        }
        int pre_idx = 0;
        return buildTree(preorder, value_idx, 0, inorder.size(), pre_idx);
    }
// *************** End of HOT  *****************//


    bool isSameTree(TreeNode *p, TreeNode *q) {
        // 递归解法，前序遍历
        if (p && q) {
            if (p->val == q->val) {
                if (isSameTree(p->left, q->left) &&
                    isSameTree(p->right, q->right)) {
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

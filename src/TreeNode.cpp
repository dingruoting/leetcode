//
// Created by ruoting on 2019/11/17.
//

#include "../include/TreeNode.h"

void PrintNodeLevelWithOutNull(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    deque<TreeNode *> helper;
    helper.push_back(root);
    while (!helper.empty()) {
        auto cur = helper.front();
        helper.pop_front();
        std::cout << cur->val << " ";
        if (cur->left) {
            helper.push_back(cur->left);
        }
        if (cur->right) {
            helper.push_back(cur->right);
        }
    }
}

void PrintNodeLevelWithNull(TreeNode *root) {
    if (root == nullptr) {
        std::cout << "tree is empty" << std::endl;
        return;
    }
    deque<TreeNode *> helper;
    helper.push_back(root);
    while (!helper.empty()) {
        auto cur = helper.front();
        helper.pop_front();
        if (cur) {
            std::cout << cur->val << " ";
            if (!cur->left && !cur->right) {
                continue;
            }
            helper.push_back(cur->left);
            helper.push_back(cur->right);
        } else {
            std::cout << "null ";
        }
    }
}

void TreeNodeSolution::Test() {
//    TreeNode root = (1);
//    TreeNode node2 = 2;
//    TreeNode node3 = 3;
//    root.right = &node2;
//    node2.left = &node3;

//  auto res = inorderTraversal(&root);
//  PrintVector(res);
//  auto ans = levelOrder(&root);
//  for(const auto& level : ans){
//    std::cout << "[";
//    for(const auto& val : level){
//      std::cout << val << " ";
//    }
//    std::cout << "]";
//  }
//  PrintNodeLevelWithNull(&root);
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    auto tree = buildTree(preorder, inorder);
    PrintNodeLevelWithNull(tree);

}
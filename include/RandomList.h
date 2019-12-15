//
// Created by ruoting on 2019/11/17.
//

#ifndef CODING_RANDOMLIST_H
#define CODING_RANDOMLIST_H
#include "Solution.h"
class Node {
 public:
  int val;
  Node *next;
  Node *random;

  Node() {}

  Node(int _val, Node *_next, Node *_random) {
    val = _val;
    next = _next;
    random = _random;
  }
};
class RandomList : public Solution {
 public:
//  蚂蚁金服面试题：给定一个链表，每个节点包含一个额外增加的随机指针，
//  该指针可以指向链表中的任何节点或空节点。
//  要求返回这个链表的深拷贝。
  Node *copyRandomList(Node *head) {
    Node *pre = nullptr;
    Node pre_ans(0, nullptr, nullptr);
    Node *cur = &pre_ans;
    unordered_map<Node *, Node *> relation;
    Node *pHead = head;
    while (pHead) {
      cur->next = new Node(pHead->val, nullptr, nullptr);
      relation[pHead] = cur->next;
      pHead = pHead->next;
      cur = cur->next;
    }
    pHead = head;
    cur = pre_ans.next;
    while (pHead) {
      cur->random = relation[pHead->random];
      cur = cur->next;
      pHead = pHead->next;
    }
    return pre_ans.next;
  }
  void Test() override;
};
#endif //CODING_RANDOMLIST_H

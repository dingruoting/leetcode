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
//  给定一个链表，每个节点包含一个额外增加的随机指针，
//  该指针可以指向链表中的任何节点或空节点。
//  要求返回这个链表的深拷贝。
  Node *copyRandomList(Node *head) {
  }
  void Test() override;
};
#endif //CODING_RANDOMLIST_H

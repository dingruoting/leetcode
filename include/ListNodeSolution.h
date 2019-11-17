//
// Created by ruoting on 2019/11/13.
//

#ifndef CODING_LISTNODESOLUTION_H
#define CODING_LISTNODESOLUTION_H

#include "Solution.h"
// * Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class ListNodeSolution : public Solution {
 public:
  void Test() override;
 private:
  // *************** Start of HOT  *****************//
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (n <= 0) {
      return head;
    }
    // 使用哨兵节点 "prehead" 可能需要删除头节点
    ListNode prehead(0);
    prehead.next = head;
    // 双指针，一个走得快，一个走得慢
    ListNode *slower = &prehead;
    ListNode *faster = &prehead;
    for (auto i = 0; i < n + 1; ++i) {
      if (!faster) {
        return nullptr;
      }
      faster = faster->next;
    }
    while (faster != nullptr) {
      slower = slower->next;
      faster = faster->next;
    }
    slower->next = slower->next->next;
    return prehead.next;
  }
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    // 迭代法 哨兵节点
    ListNode *pre_head = new ListNode(0);
    auto begin = pre_head;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        pre_head->next = l1;
        l1 = l1->next;
      } else {
        pre_head->next = l2;
        l2 = l2->next;
      }
      pre_head = pre_head->next;
    }
    pre_head->next = l1 ? l1 : l2;
    auto output = begin->next;
    delete begin;
    return output;
  }
  ListNode *detectCycle(ListNode *head) {
    // 阶段1，根据快指针（走2步）和慢指针（走1步）是否相遇，来判断是否有环
    auto slow = head;
    auto fast = head;
    ListNode *meet = nullptr;
    while (slow && fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        meet = fast;
        break;
      }
    }
    if (meet == nullptr) {
      return meet;
    }
    // 阶段二，相遇节点和表头同时移动，相遇点即是环的入口
    slow = head;
    while (true) {
      if (slow == meet) {
        return slow;
      }
      slow = slow->next;
      meet = meet->next;
    }
  }
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pA = headA;
    ListNode *pB = headB;
    // 双指针法
    // 消除两个链表的长度差：指针pA遍历完A后遍历B，最多走len(A)+len(B)步,同理pB也是。
    // 如果两个链表不相交，则最后pA和pB同时等于空指针
    // 如果两个链表相交，由于相交点之后的长度是一样的，pA和pB会在相交点相遇。
    while (pA != pB) {
      pA = pA ? pA->next : headB;
      pB = pB ? pB->next : headA;

    }
    return pA;
  }
  // *************** End of HOT  *****************//

};

#endif //CODING_LISTNODESOLUTION_H

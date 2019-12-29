//
// Created by ruoting on 2019/11/13.
//

#ifndef CODING_LISTNODESOLUTION_H
#define CODING_LISTNODESOLUTION_H

#include "Solution.h"

// O(1) 删除链表里的指定节点：不删除该节点，把下一个节点的内容复制到当前节点，删除下一节点。

// * Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;

  ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * 对于链表问题，返回结果为头结点时，通常需要先初始化一个哨兵节点 pre，
 * 该指针的下一个节点指向真正的头结点head。使用哨兵节点的目的在于
 * 链表初始化时无可用节点值，而且链表构造过程需要指针移动，
 * 进而会导致头指针丢失，无法返回结果
 */
class ListNodeSolution : public Solution {
 public:
  void Test() override;

 private:
  // *************** Start of HOT  *****************//
  // 反转一个单链表
  ListNode *reverseList(ListNode *head) {
    // preNode的下一个节点永远指向反转好的链表起始
    ListNode preNode(0);
    // 从头到尾遍历整个链表
    while (head) {
      // 暂存当前节点的下一个节点，下一轮遍历
      auto next = head->next;
      // 将当前节点的下一个节点更新为已反转好的链表起始
      head->next = preNode.next;
      // 更新反转好的链表起始
      preNode.next = head;
      // 切换到下一个节点
      head = next;
    }
    return preNode.next;
  }

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

  // 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode preMode(0);
    auto head = &preMode;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        head->next = l1;
        l1 = l1->next;
      } else {
        head->next = l2;
        l2 = l2->next;
      }
      head = head->next;
    }
    head->next = l1 ? l1 : l2;
    return preMode.next;
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

  /*
   * 给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，
   * 并且它们的每个节点只能存储一位数字。如果，我们将这两个数相加起来，
   * 则会返回一个新的链表来表示它们的和。
   *(2 -> 4 -> 3) + (5 -> 6 -> 4) = 7 -> 0 -> 8
   * */
  ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2) {
    // 考虑进位，0或者1  求和运算最后可能出现额外的进位，比如5+5=10
    int carry = 0;
    // 使用哨兵节点
    ListNode preHead(0);
    auto root = &preHead;
    while (l1 || l2 || carry) {
      int x = l1 ? l1->val : 0;
      int y = l2 ? l2->val : 0;
      int all = (carry + x + y);
      carry = all / 10;
      root->next = new ListNode(all % 10);
      root = root->next;
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }
    return preHead.next;
  }
//  今日头条面试题：给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。
//  它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
//  你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//  输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//  输出: 7 -> 8 -> 0 -> 7
//  要求不能使用其他数据结构
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2) {
      return l1 ? l1 : l2;
    }
    return reverseList(addTwoNumbers1(reverseList(l1), reverseList(l2)));
  }
  // *************** End of HOT  *****************//

};

#endif //CODING_LISTNODESOLUTION_H

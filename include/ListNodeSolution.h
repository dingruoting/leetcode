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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (n <= 0) {
      return head;
    }
    ListNode prehead(0);
    prehead.next = head;
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

};

#endif //CODING_LISTNODESOLUTION_H

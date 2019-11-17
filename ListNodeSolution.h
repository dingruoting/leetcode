//
// Created by ruoting on 2019/11/13.
//

#ifndef CODING_LISTNODESOLUTION_H
#define CODING_LISTNODESOLUTION_H

// * Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class ListNodeSolution {
 public:
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

  static void Test();
};

#endif //CODING_LISTNODESOLUTION_H

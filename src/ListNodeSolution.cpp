//
// Created by ruoting on 2019/11/13.
//
#include <iostream>
#include "../include/ListNodeSolution.h"
void PrintListNode(ListNode *root) {
  std::cout << "list is ";
  while (root) {
    std::cout << root->val << " ";
    root = root->next;
  }
  std::cout << std::endl;
}
void ListNodeSolution::Test() {
  ListNode head(10);
  ListNode head2(11);
  ListNode second(20);
  ListNode second2(21);
  ListNode third(3);
  ListNode num4(4);
  head.next = &second;
  second.next = &third;
  third.next = &num4;
  head2.next = &second2;
  second2.next = &third;
//  ListNode head(1);
//  ListNode second(2);
//  head.next = &second;
//  second.next= &head;

  PrintListNode(&head);
  PrintListNode(&head2);
  auto val = getIntersectionNode(&head,&head2);
  if(val){
    std::cout << val->val << std::endl;
  } else {
    std::cout << "no intersection" << std::endl;
  }
//  auto cycle = detectCycle(&head);
//  if (cycle) {
//    std::cout << "has cycle , val is " << cycle->val << std::endl;
//  } else {
//    std::cout << " do not have cycle" << std::endl;
//  }
//  auto ans = removeNthFromEnd(&head, 0);
//  PrintListNode(ans);
}
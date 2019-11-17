//
// Created by ruoting on 2019/11/13.
//
#include <iostream>
#include "ListNodeSolution.h"
void PrintListNodde(ListNode* root){
    std::cout << "list is ";
    while(root){
        std::cout << root->val;
        root= root->next;
    }
    std::cout << std::endl;
}
void ListNodeSolution::Test(){
    ListNode head(1);
    ListNode second(2);
    ListNode third (3);
    ListNode num4 (4);
    ListNode num5(5);
    head.next=&second;
    second.next=&third;
    third.next = & num4;
    num4.next = &num5;
    ListNodeSolution s;
    auto ans = s.removeNthFromEnd(&head,0);
    PrintListNodde(ans);
}
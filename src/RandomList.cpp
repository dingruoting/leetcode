//
// Created by ruoting on 2019/11/17.
//
#include "../include/RandomList.h"
void PrintNode(Node *n) {
  while (n) {
    std::cout << n->val;
    if (n->random) {
      std::cout << "(" << n->random->val << ")";
    }
    n = n->next;
    if (n) {
      std::cout << " ->";
    }
  }
  std::cout << std::endl;
}
void RandomList::Test() {
  Node n1(1, nullptr, nullptr);
  Node n2(2, &n1, &n1);
  Node n3(3, &n2, nullptr);
  Node n4(4, &n3, &n1);
  n1.random = &n3;

  PrintNode(&n4);
  auto ans = copyRandomList(&n4);
  PrintNode(ans);

}

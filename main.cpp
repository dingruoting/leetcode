#include <iostream>
#include "include/ListNodeSolution.h"
#include "include/VectorSolution.h"
#include "include/TreeNode.h"
int main() {
  std::cout << "Hello, World!" << std::endl;
  Solution *s = nullptr;
//  s = new VectorSolution();
  s = new TreeNodeSolution();
  s->Test();
  delete s;

  return 0;
}
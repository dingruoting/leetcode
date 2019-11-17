#include <iostream>
#include "include/ListNodeSolution.h"
#include "include/VectorSolution.h"
#include "include/TreeNode.h"
#include "include/Math.h"
#include "include/Hash.h"
int main() {
  std::cout << "Hello, World!" << std::endl;
  Solution *s = nullptr;
//  s = new VectorSolution();
//  s = new TreeNodeSolution();
//  s = new Math();
//  s = new ListNodeSolution();
  s = new Hash();
  s->Test();
  delete s;

  return 0;
}
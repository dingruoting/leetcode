#include <iostream>
#include "include/ListNodeSolution.h"
#include "include/VectorSolution.h"
#include "include/TreeNode.h"
#include "include/Math.h"
#include "include/Hash.h"
#include "include/RandomList.h"
#include "include/language.h"
#include "include/LRUCache.h"
#include "include/GraphSolution.h"
#include "include/SearchSolution.h"
int main() {

  std::cout << "Hello, World!" << std::endl;
  Solution *s = nullptr;
//  s = new SearchSolution();
//  s = new GraphSolution();
//  s = new VectorSolution();
//  s = new TreeNodeSolution();
//    s = new Math();
  s = new ListNodeSolution();
//  s = new RandomList();
//  s = new Hash();
//    s = new Language();
  s->Test();
  delete s;
//    LRUCache obj(2);
//    obj.put(1,1);
//    obj.put(2,2);
//   std::cout << obj.get(1) << std::endl;
//    obj.put(3,3);
//    std::cout << obj.get(2) << std::endl;
  return 0;
}
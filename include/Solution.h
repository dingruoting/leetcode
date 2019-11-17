//
// Created by ruoting on 2019/11/13.
//

#ifndef CODING_SOLUTION_H
#define CODING_SOLUTION_H

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <iostream>
#include <string>
using namespace std;
class Solution {
 public:
  void PrintVector(std::vector<int> &res) {
    for (const auto &val : res) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  virtual void Test() = 0;
};

#endif //CODING_SOLUTION_H

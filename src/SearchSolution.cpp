//
// Created by ruoting on 2019/12/24.
//

#include "../include/SearchSolution.h"

void SearchSolution::printTestResult(vector<int> data, int target) {
//  std::cout << "search result for " << target << " in {";
//  for (const auto &val : data) {
//    std::cout << val << " ";
//  }
//  std::cout << "} is " << BinarySearchInsert(data, target) << std::endl;

  std::cout << "search result for " << target << " in {";
  for (const auto &val : data) {
    std::cout << " " << val;
  }
  std::cout << " } is {";
  auto ans = searchRange(data, target);
  for (const auto &val : ans) {
    std::cout << " " << val;
  }
  std::cout << " }" << std::endl;
}

void SearchSolution::Test() {
//  printTestResult({1, 3, 5, 6}, 5);
//  printTestResult({1, 3, 5, 6}, 2);
//  printTestResult({1, 3, 5, 6}, 7);
//  int data = 64;
//  std::cout << "my sqrt for " << data << " is " << mySqrt(data) << std::endl;
//  data = 8;
//  std::cout << "my sqrt for " << data << " is " << mySqrt(data) << std::endl;
//  data = 2;
//  std::cout << "my sqrt for " << data << " is " << mySqrt(data) << std::endl;
//  data = 0;
//  std::cout << "my sqrt for " << data << " is " << mySqrt(data) << std::endl;
//  data =2147395599;
//  std::cout << "my sqrt for " << data << " is " << mySqrt(data) << std::endl;
//  data =1;
//  std::cout << "my sqrt for " << data << " is " << mySqrt(data) << std::endl;
//  printTestResult({5, 7, 7, 8,8,10}, 8);
//  printTestResult({5, 7, 7, 8,8,10}, 6);
  printTestResult({}, 0);

}
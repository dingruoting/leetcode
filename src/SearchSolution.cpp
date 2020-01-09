//
// Created by ruoting on 2019/12/24.
//

#include "../include/SearchSolution.h"

void SearchSolution::printTestResult(vector<int> data,
                                     int target,
                                     int expect_res) {
//  std::cout << "search result for " << target << " in {";
//  for (const auto &val : data) {
//    std::cout << val << " ";
//  }
//  std::cout << "} is " << BinarySearchInsert(data, target) << std::endl;
//  auto res = search(data, target);
//  std::cout << "} is " << search(data, target);


  std::cout << "min val in {";
  for (const auto &val : data) {
    std::cout << val << " ";
  }
  auto ans = findMin(data);
  std::cout << "} is " << ans << std::endl;
  if (ans != expect_res) {
    std::cout << " result is failed!!";
  }
  std::cout << std::endl;
//  std::cout << "search result for " << target << " in {";
//  for (const auto &val : data) {
//    std::cout << " " << val;
//  }
//  std::cout << " } is {";
//  auto ans = searchRange(data, target);
//  for (const auto &val : ans) {
//    std::cout << " " << val;
//  }
//  std::cout << " }" << std::endl;
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
//  printTestResult({4, 5, 6, 7, 0, 2, 3}, 3, 6);
//  printTestResult({4, 5, 6, 7, 0, 2, 3}, 0, 4);
//  printTestResult({2, 5, 6, 7, 0, 1}, 2, 0);
//  printTestResult({6, 7, 8, 1, 2, 3, 4, 5}, 6, 0);
//  printTestResult({2, 5, 6, 7, 0, 1}, 8, -1);
//  printTestResult({8, 11, 22, 33, 0, 3, 6}, 5, -1);
//  printTestResult({8, 9, 2, 3, 4}, 9, 1);
//  printTestResult({1, 2, 3, 4, 5, 6}, 3, 2);
//  printTestResult({1, 2, 3}, 3, 2);
//  printTestResult({1, 3}, 3, 1);
//  printTestResult({5, 1, 3}, 3, 2);
//  printTestResult({}, 0, -1);
//  printTestResult({3, 1}, 1, 1);
//
//  printTestResult({8, 9, 2, 3, 4}, 9, 2);
//  printTestResult({1, 2, 3, 4, 5, 6}, 3, 1);
//  printTestResult({1, 2, 3}, 3, 1);
//  printTestResult({2,2,2,0,1}, 3, 0);
//  printTestResult({3,1,3}, 3, 1);
//  printTestResult({3,3,1,3}, 3, 1);
//  printTestResult({}, 0, -1);
//  printTestResult({3, 1, 1}, 1, 1);
  std::cout << myPow(2, 10) << std::endl;
  std::cout << myPow(2, -2) << std::endl;
  std::cout << myPow(1.00000, -2147483648) << std::endl;
}
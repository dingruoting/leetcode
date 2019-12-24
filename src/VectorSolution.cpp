//
// Created by ruoting on 2019/11/13.
//

#include "../include/VectorSolution.h"
#include <chrono>
void PrintVectorVector(vector<vector<int>> datas) {
  for (auto &data : datas) {
    for (auto &val : data) {
      std::cout << val << " ";
    }
  }
  std::cout << std::endl;
}

void VectorSolution::Test() {
  vector<int> data1 = {1, 66, 66,3};
  vector<int> data2 = {66, 5, 68,66};
//    vector<int> data3 = {7,8,9};
//  vector<vector<int>> testdata = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//  rotate(testdata);
//  PrintVectorVector(testdata);
//    vector<int> data = {7, 1, 5, 3, 6, 4};
//    std::cout << "max profix is " << maxProfit(data) << std::endl;
//  vector<int> data = {4, 5, 6, 7, 0, 1, 2};
//  std::cout << "search " << search(data, 0) << std::endl;
//  vector<int> data = {1, 2, 5, 6, 7};
//  std::cout << "search " << searchInOrder(data, 6) << std::endl;
//
//  std::vector<std::vector<int>> inputs =
//      {{1, 2, 3, 9, 10}, {3, 4, 11}, {2, 3, 4, 9, 10}, {2, 3, 5, 8, 9}};
//  auto ans = findCommonElems1(inputs);
//  for (auto i = 0; i < ans.size(); ++i) {
//    cout << ans[i] << endl;
//  }

  auto ans = intersection2(data1, data2);
  for (auto i = 0; i < ans.size(); ++i) {
    cout << ans[i] << endl;
  }
}
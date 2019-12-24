//
// Created by ruoting on 2019/11/13.
//

#ifndef CODING_VECTORSOLUTION_H
#define CODING_VECTORSOLUTION_H

#include "Solution.h"

class VectorSolution : public Solution {
 public:
  void Test() override;

 private:
  // 今日头条面试题
//  假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//  ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
//  搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
//  你可以假设数组中不存在重复的元素。
//  你的算法时间复杂度必须是 O(log n) 级别。

  int search(vector<int> &nums, int target) {

    return -1;
  }

//    阿里云 面试题 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//    如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
//    注意你不能在买入股票前卖出股票。
  int maxProfit(vector<int> &prices) {
    if (prices.empty()) {
      return 0;
    }
    int min_price = prices[0];
    int profix = 0;
    for (auto i = 1; i < prices.size(); ++i) {
      auto &price = prices[i];
      if (price < min_price) {
        min_price = price;
      } else {
        profix = max(profix, price - min_price);
      }
    }
    return profix;
  }
  // 阿里淘系 面试题，N个有序数组的交集
  vector<int> findCommonElems1(vector<vector<int>> Arrays) {
    if (Arrays.empty()) {
      return {};
    }
    std::vector<int> res;
    std::vector<int> idxs;
    for (auto i = 0; i < Arrays.size(); ++i) {
      idxs.emplace_back(0);
    }
    auto &min_inputs = Arrays[0];
    for (const auto &val : min_inputs) {
      bool match = true;
      for (auto k = 1; k < Arrays.size(); ++k) {
        while (Arrays[k][idxs[k]] < val) {
          idxs[k]++;
          if (idxs[k] >= Arrays[k].size()) {
            return res;
          }
        }
        if (Arrays[k][idxs[k]] == val) {
          continue;
        } else {
          match = false;
          break;
        }
      }
      if (match) {
        res.emplace_back(val);
      }
    }
    return res;
  }
};

#endif //CODING_VECTORSOLUTION_H

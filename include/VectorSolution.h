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
  // 允许多次交易 斜坡上爬升并持续增加从连续交易中获得的利润
  int maxProfit2(vector<int> &prices) {
    if (prices.empty()) {
      return 0;
    }
    int profix = 0;
    for (auto i = 1; i < prices.size(); ++i) {
      if(prices[i] > prices[i-1]){
        profix+= prices[i] - prices[i-1];
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
//两个无序数组的交集 - 输出结果中的每个元素一定是唯一的
//根据第一个数组 nums1 迭代并检查每个值是否存在在 nums2 内。如果存在将值添加到输出。这样的方法会导致 O(n×m) 的时间复杂性，其中 n 和 m 是数组的长度。
//并且会有重复查找的问题,比如，[1,7,3,4] 与[3,3] 应该输出[3]而不是[3,3]
//为了在线性时间内解决这个问题，我们使用集合 set，在 O(1) 时间复杂度实现操作。 平均情况下，这种方法的时间复杂度为O(n+m)。
// 如果要求输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。那么使用hashmap来记录每个元素出现的次数

  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res;
    std::set<int> set1;
    for (const auto &val : nums1) {
      set1.insert(val);
    }
    for (const auto &val : nums2) {
      if (set1.find(val) != set1.end()) {
        res.emplace_back(val);
        set1.erase(val);
      }
    }
    return res;
  }
};

#endif //CODING_VECTORSOLUTION_H

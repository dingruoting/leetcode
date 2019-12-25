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
};

#endif //CODING_VECTORSOLUTION_H

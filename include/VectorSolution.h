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
    void swap(int *a, int *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }

    void rotate(vector<vector<int>> &matrix) {
        //\todo
    }
//    给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
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

};

#endif //CODING_VECTORSOLUTION_H

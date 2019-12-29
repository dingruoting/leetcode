//
// Created by ruoting on 2019/12/29.
//

#ifndef CODING_DYNAMICPROGRAMMING_H
#define CODING_DYNAMICPROGRAMMING_H

#include "Solution.h"

//动态规划常常适用于有重叠子问题和最优子结构性质的问题
// Optimal substructure（优化子结构）一个问题的优化解包含了子问题的优化解
// Subteties（重叠子问题）在问题的求解过程中，很多子问题的解将被多次使用。

//基本思想：问题的最优解如果可以由子问题的最优解推导得到，则可以先求解子问题的最优解，

//动态规划特点：
//1 把原始问题划分成一系列子问题；
//2 求解每个子问题仅一次，并将其结果保存在一个表中，以后用到时直接存取，不重复计算，节省计算时间
//3 自底向上地计算。
//4 整体问题最优解取决于子问题的最优解（状态转移方程）

class DynamicProgramming : public Solution {
public:
    void Test() override;

private:
//    给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
    int maxSubArray(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int final_max = nums[0];
        std::vector<int> iMax(nums.size(), 0);
        iMax[0] = final_max;
        for (auto i = 1; i < nums.size(); ++i) {
            iMax[i] = iMax[i - 1] > 0 ? iMax[i - 1] + nums[i] : nums[i];
            final_max = std::max(final_max, iMax[i]);
        }
        return final_max;
    }
//    华为笔试题
//    假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//    每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//    注意：给定 n 是一个正整数。
//    到达第 ii 阶的方法总数就是到第 (i−1) 阶和第 (i−2) 阶的方法数之和

    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int count[n + 1];
        count[0] = 0;
        count[1] = 1;
        count[2] = 2;
        for (auto i = 3; i <= n; ++i) {
            count[i] = count[i - 1] + count[i - 2];
        }
        return count[n];
    }

//  今日头条面试题
//  给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output
//  其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
//  说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
// 思路：output[i]为当前数左边的乘积 * 右边的乘积
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> output(nums.size(), 1);
        int product_left = 1;
        int product_right = 1;
        for (auto left = 0; left < nums.size(); ++left) {
            auto right = nums.size() - left - 1;
            output[left] *= product_left;
            product_left *= nums[left];
            output[right] *= product_right;
            product_right *= nums[right];
        }
        return output;
    }

};

#endif //CODING_DYNAMICPROGRAMMING_H

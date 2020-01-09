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
//    思路：到达第 ii 阶的方法总数就是到第 (i−1) 阶和第 (i−2) 阶的方法数之和

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

//    你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金
//    影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//    给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额
//    思路：由于不可以在相邻的房屋闯入，所以在当前位置 n 房屋可盗窃的最大值，要么就是 n-1 房屋可盗窃的最大值，要么就是 n-2 房屋可盗窃的最大值加上当前房屋的值，二者之间取最大值
  int rob(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    int f[nums.size()];
    f[0] = nums[0];
    f[1] = std::max(f[0], nums[1]);
    for (auto i = 2; i < nums.size(); ++i) {
      f[i] = std::max(f[i - 2] + nums[i], f[i - 1]);
    }
    return f[nums.size() - 1];
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
//  给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
//  具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
//  思路：3个字符及以上，dp[i][j] = s[i]=s[j] && dp[i+1][j-1],dp[i][j]代表i-j是否是回文子串
//  2个字符及以下，判断s[i]=s[j] 即可。
  int countSubstrings(string s) {
    int ans = 0;
    int size = s.size();
    if (size == 0) {
      return ans;
    }
    bool is_palindromic[size][size] = {false};
    for (auto j = 0; j < size; ++j) {
      for (auto i = j; i >= 0; i--) {
        if (s[i] == s[j] && (j - i <= 1 || is_palindromic[i + 1][j - 1])) {
          is_palindromic[i][j] = true;
          ans++;
        } else {
          is_palindromic[i][j] = false;
        }
      }
    }
    return ans;
  }
};

#endif //CODING_DYNAMICPROGRAMMING_H

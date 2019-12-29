//
// Created by ruoting on 2019/12/29.
//

#ifndef CODING_DYNAMICPROGRAMMING_H
#define CODING_DYNAMICPROGRAMMING_H
#include "Solution.h"
class DynamicProgramming : public Solution {
 public:
  void Test() override;
 private:
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

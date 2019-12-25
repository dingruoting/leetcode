//
// Created by ruoting on 2019/12/24.
//

#ifndef CODING_SEARCHSOLUTION_H
#define CODING_SEARCHSOLUTION_H
#include "Solution.h"
class SearchSolution : public Solution {
 public:
  void Test() override;
 private:
  // 二分查找
  // 给定一个排序数组和一个目标值，在数组中找到目标值，
  // 并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
  int BinarySearchInsert(vector<int> &nums, int target) {
    int p = 0;
    int q = nums.size() - 1;
    while (p <= q) {
      auto mid = (p + q) >> 1;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        p = mid + 1;
      } else {
        q = mid - 1;
      }
    };
    return p;
  }
//  计算并返回 x 的平方根，其中 x 是非负整数。
//  由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
//  输入: 8
//  输出: 2
//  说明: 8 的平方根是 2.82842...,
//  由于返回类型是整数，小数部分将被舍去。
  int mySqrt(int x) {
    // 如果一个数的一半的平方大于它自己，那么这个数的取值范围 a≥4 或者 a≤0。
    if (x < 4) {
      return x;
    }
    int p = 1;
    int q = x / 2 + 1;
    while (p <= q) {
      int mid = (p + q) >> 1;
      // 注意：mid*mid可能会溢出
      if (mid == x / mid) {
        return mid;
      } else if (mid < (x / mid)) {
        p = mid + 1;
      } else {
        q = mid - 1;
      }
    }
    return p - 1;
  }
  int searchBound(vector<int> &nums,
                  int target,
                  bool lower_bound) {
    auto p = 0;
    // 注意不要使用auto ,否则当nums为空时此处结果异常。
    int q = nums.size() - 1;
    int ans = -1;
    while (p <= q) {
      auto mid = (p + q) / 2;
      if (nums[mid] == target) {
        if (lower_bound) {
          q = mid - 1;
        } else {
          p = mid + 1;
        }
        ans = mid;
      } else if (nums[mid] < target) {
        p = mid + 1;
      } else {
        q = mid - 1;
      }
    }
    return ans;
  }
//  给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//  你的算法时间复杂度必须是 O(log n) 级别。
//  如果数组中不存在目标值，返回 [-1, -1]
  vector<int> searchRange(vector<int> &nums, int target) {
    auto left = searchBound(nums, target, true);
    if (left == -1) {
      return {-1, -1};
    }
    auto right = searchBound(nums, target, false);
    return {left, right};
  }
  // 今日头条面试题
//  假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//  ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
//  搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
//  你可以假设数组中不存在重复的元素。
//  你的算法时间复杂度必须是 O(log n) 级别。
  void printTestResult(vector<int> data, int target);

};

#endif //CODING_SEARCHSOLUTION_H

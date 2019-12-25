//
// Created by ruoting on 2019/11/17.
//

#ifndef CODING_HASH_H
#define CODING_HASH_H
#include "Solution.h"
/*
1 关联容器实现能快速查找（ O(log n) 复杂度）的数据结构。
set 唯一键的集合，按照键排序
map 键值对的集合，按照键排序，键是唯一的
2 无序关联容器提供能快速查找（均摊 O(1) ，最坏情况 O(n) 的复杂度）的无序（哈希）数据结构。
unordered_set 唯一键的集合，按照键生成散列
unordered_map 键值对的集合，按照键生成散列，键是唯一的
3 顺序容器
 deque 双端队列
 list 	双链表
 vector 动态的连续数组
 array 静态的连续数组
 * */

class Hash : public Solution {
 public:
  // *************** Start of HOT  *****************//
  // 存在重复元素，边查找边插入
  bool containsDuplicate(vector<int> &nums) {
    set<int> helpers;
    for (const auto &num : nums) {
      if (helpers.find(num) != helpers.end()) {
        return true;
      }
      helpers.insert(num);
    }
    return false;
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
//  给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l)
//  使得 A[i] + B[j] + C[k] + D[l] = 0。
//  为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。
//  所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

  int fourSumCount(vector<int> A, vector<int> B, vector<int> C, vector<int> D) {
    std::unordered_map<int, int> a_and_b;
    for (const auto &a:A) {
      for (const auto &b:B) {
        auto sum = a + b;
        if (a_and_b.find(sum) != a_and_b.end()) {
          a_and_b[sum]++;
        } else {
          a_and_b[sum] = 1;
        }
      }
    }
    int ans = 0;
    for (const auto &c:C) {
      for (const auto &d:D) {
        auto target = 0 - c - d;
        if (a_and_b.find(target) != a_and_b.end()) {
          ans += a_and_b[target];
        }
      }
    }
    return ans;
  }
  // *************** End of HOT  *****************//
  void Test() override;
};

#endif //CODING_HASH_H

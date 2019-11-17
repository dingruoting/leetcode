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
  // *************** End of HOT  *****************//
  void Test() override;
};

#endif //CODING_HASH_H

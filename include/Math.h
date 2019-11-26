//
// Created by ruoting on 2019/11/17.
//

#ifndef CODING_MATH_H
#define CODING_MATH_H
#include "Solution.h"
#include <limits.h>
class Math : public Solution {
 public:
  // *************** Start of HOT  *****************//
  // 只出现一次的数字，利用异或计算
  int singleNumber(vector<int> &nums) {
    int ans = 0;
    for (const auto &val : nums) {
      ans ^= val;
    }
    return ans;
  }
  // 整数反转 ，注意符号溢出问题 32位有符号数值范围为 [−2^31,  2^31 − 1]
  int reverse(int x) {
    int y = 0;
    while (x != 0) {
      int pop = x % 10;
      if ((y > INT_MAX / 10) || (y == INT_MAX / 10 && pop > INT_MAX % 10)) {
        return 0;
      }
      if (y < INT_MIN / 10 || (y == INT_MIN / 10 && pop < INT_MIN % 10)) {
        return 0;
      }
      y = y * 10 + pop;
      x = x / 10;
    }
    return y;
  }
  // *************** End of HOT  *****************//
  void Test() override;
};

#endif //CODING_MATH_H

//
// Created by ruoting on 2019/11/17.
//

#ifndef CODING_MATH_H
#define CODING_MATH_H
#include "Solution.h"
class Math : public Solution {
 public:
  // *************** Start of HOT  *****************//
  int singleNumber(vector<int> &nums) {
    int ans = 0;
    for (const auto &val : nums) {
      ans ^= val;
    }
    return ans;
  }
  // *************** End of HOT  *****************//
  void Test() override;
};

#endif //CODING_MATH_H

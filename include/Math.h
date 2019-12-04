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
            if ((y > INT_MAX / 10) ||
                (y == INT_MAX / 10 && pop > INT_MAX % 10)) {
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

    // 输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1;
        int ans = 0;
        for (auto i = 0; i < 32; ++i) {
            if (n & mask) {
                ans++;
            }
            mask <<= 1;
        }
        return ans;
    }

    // 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
    int hammingDistance(int x, int y) {
        auto val = x ^y;
        return hammingWeight(val);
    }

    // 给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
    // 对于任意数字 n ，将 n 和 n - 1 做与运算，会把最后一个 1 的位变成 0
    // 2的幂在二进制中表示为最高位为0（一定为正），其余为有且仅有一位为1，其余都为0，所以我们只需要将这个数字与他减一后的数字进行与运算就可以判断是否为2的幂了（n&(n-1)

    bool isPowerOfTwo(int num) {
        return (num & (num - 1)) == 0;
    }

    // *************** End of HOT  *****************//
    void Test() override;
};

#endif //CODING_MATH_H

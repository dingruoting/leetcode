//
// Created by ruoting on 2019/11/17.
//

#ifndef CODING_STINGSOLUTION_H
#define CODING_STINGSOLUTION_H
#include "Solution.h"
class StingSolution : public Solution {
 public:
  void Test() override;
 private:
  int lengthOfLongestSubstring(string s) {
    int max_length = 0;
    int i = 0;
    int j = 0;
    map<char, int> windows;
    while (j < s.size()) {
      if (windows.find(s[j]) != windows.end()) {
        i = max(i, windows[s[j]]);
      }
      windows[s[j]] = j + 1;
      max_length = max(max_length, j - i + 1);
      j++;
    }
    return max_length;
  }
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
  bool isFirtElement(char a) {
    return a == '(' || a == '[' || a == '{';
  }
  bool isMatch(char a, char b) {
    if (a == '(') {
      return b == ')';
    }
    if (a == '[') {
      return b == ']';
    }
    if (a == '{') {
      return b == '}';
    }
    return false;
  }
  bool isValid(string s) {
    stack<char> windows;
    auto itr = s.begin();
    while (itr != s.end()) {
      if (windows.empty() || isFirtElement(*itr)) {
        windows.push(*itr);
      } else {
        if (isMatch(windows.top(), *itr)) {
          windows.pop();
        } else {
          return false;
        }
      }
      itr++;
    }
    return windows.empty();
  }

  class LongestCommonPrefix {
   public:
    string commonPrefix(string left, string right) {
      auto lenth = min(left.length(), right.length());
      for (auto i = 0; i < lenth; ++i) {
        if (left[i] != right[i]) {
          return left.substr(0, i);
        }
      }
      return left.substr(0, lenth);
    }
    string longestCommonPrefix(vector<string> &strs,
                               int strs_start,
                               int strs_end) {
      if (strs_start == strs_end) {
        return strs[strs_start];
      }
      auto min = (strs_start + strs_end) / 2;
      auto left = longestCommonPrefix(strs, strs_start, min);
      auto right = longestCommonPrefix(strs, min + 1, strs_end);
      return commonPrefix(left, right);
    }
    string SolutionA(vector<string> &strs) {
      if (strs.empty()) {
        return string();
      }
      // 归并法
      return longestCommonPrefix(strs, 0, strs.size() - 1);
    }
    string SolutionB(vector<string> &strs) {
      if (strs.empty()) {
        return string();
      }
      // 暴力解法
      auto result = strs[0];
      for (auto i = 0; i < result.size(); ++i) {
        auto val = result[i];
        for (auto j = 0; j < strs.size(); ++j) {
          if (strs[j].size() < i || strs[j][i] != val) {
            return result.substr(0, i);
          }
        }
      }
      return result;
    }

  };

};

#endif //CODING_STINGSOLUTION_H

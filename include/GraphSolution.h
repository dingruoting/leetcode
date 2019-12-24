//
// Created by ruoting on 2019/12/24.
//

#ifndef CODING_GRAPHSOLUTION_H
#define CODING_GRAPHSOLUTION_H
#include "Solution.h"
class GraphSolution : public Solution {
//  在一个小镇里，按从 1 到 N 标记了 N 个人。传言称，这些人中有一个是小镇上的秘密法官。
//  如果小镇的法官真的存在，那么：
//  小镇的法官不相信任何人。
//  每个人（除了小镇法官外）都信任小镇的法官。
//  只有一个人同时满足属性 1 和属性 2 。
//  给定数组 trust，该数组由信任对 trust[i] = [a, b] 组成，表示标记为 a 的人信任标记为 b 的人。
//  如果小镇存在秘密法官并且可以确定他的身份，请返回该法官的标记。否则，返回 -1。

  int findJudge(int N, vector<vector<int>> &trust) {
    vector<int> in_degree(N, 0);
    vector<int> out_degree(N, 0);;
    for (const auto &pair : trust) {
      out_degree[pair[0] - 1]++;
      in_degree[pair[1] - 1]++;
    }
    for (auto i = 0; i < N; ++i) {
      if (in_degree[i] == N - 1 && out_degree[i] == 0) {
        return i + 1;
      }
    }
    return -1;
  }
  void Test() override;
};

#endif //CODING_GRAPHSOLUTION_H

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
//  有 N 个花园，按从 1 到 N 标记。在每个花园中，你打算种下四种花之一。
//  paths[i] = [x, y] 描述了花园 x 到花园 y 的双向路径。
//  另外，没有花园有 3 条以上的路径可以进入或者离开。
//  你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。
//  以数组形式返回选择的方案作为答案 answer，其中 answer[i] 为在第 (i+1) 个花园中种植的花的种类。花的种类用  1, 2, 3, 4 表示。保证存在答案。
//  分析：限制每个节点的度为3，同时提供四种颜色，因此不需要回溯
  vector<int> gardenNoAdj(int N, vector<vector<int>> &paths) {
    // 1 构建邻接表
    std::vector<std::vector<int>> table(N);
    for (const auto &path: paths) {
      if (path[1] < path[0]) {
        table[path[0] - 1].emplace_back(path[1] - 1);
      } else {
        table[path[1] - 1].emplace_back(path[0] - 1);
      }
    }
    // 2 遍历所有节点，对于每个节点 查看其邻接点颜色，使用不同的颜色染色即可
    std::vector<int> color(N, 1);
    for (auto i = 1; i < N; ++i) {
      set<int> all_colors = {1, 2, 3, 4};
      for (const auto &adj : table[i]) {
        all_colors.erase(color[adj]);
      }
      color[i] = *all_colors.begin();
    }
    return color;
  }
  void Test() override;
};

#endif //CODING_GRAPHSOLUTION_H

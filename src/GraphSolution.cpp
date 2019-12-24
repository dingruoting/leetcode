//
// Created by ruoting on 2019/12/24.
//

#include "../include/GraphSolution.h"

void GraphSolution::Test() {
//  int num = 2;
//  vector<vector<int>> trust = {{1, 2}};
//  auto ans = findJudge(num, trust);
//  std::cout << "judge is " << ans << std::endl;
//  num = 3;
//  trust = {{1, 3},{2,3},{3,1}};
//  ans = findJudge(num, trust);
//  std::cout << "judge is " << ans << std::endl;
  int garden_num = 4;
  vector<vector<int>> garden_path = {{1, 2}, {3, 4}};
  auto garden_color = gardenNoAdj(garden_num, garden_path);
  for (const auto &color : garden_color) {
    std::cout << color << " ";
  }
  std::cout << std::endl;
  garden_path = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 3}, {2, 4}};
  garden_color = gardenNoAdj(garden_num, garden_path);
  for (const auto &color : garden_color) {
    std::cout << color << " ";
  }
  std::cout << std::endl;
}

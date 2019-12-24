//
// Created by ruoting on 2019/12/24.
//

#include "../include/GraphSolution.h"

void GraphSolution::Test() {
  int num = 2;
  vector<vector<int>> trust = {{1, 2}};
  auto ans = findJudge(num, trust);
  std::cout << "judge is " << ans << std::endl;
  num = 3;
  trust = {{1, 3},{2,3},{3,1}};
  ans = findJudge(num, trust);
  std::cout << "judge is " << ans << std::endl;
}

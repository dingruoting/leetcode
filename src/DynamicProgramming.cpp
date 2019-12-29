//
// Created by ruoting on 2019/12/29.
//

#include "../include/DynamicProgramming.h"
void DynamicProgramming::Test() {
  std::vector<int> data = {1,2,3,4};
  auto ans = productExceptSelf(data);
  std::cout << "[" ;
  for(const auto& num : ans){
    std::cout << num << " ";
  }
  std::cout << "] " << std::endl;
};
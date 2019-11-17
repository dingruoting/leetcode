//
// Created by ruoting on 2019/11/17.
//

#include "../include/Hash.h"

void Hash::Test() {
  vector<int> data = {1, 2, 3, 55, 5};
  std::cout << "contains duplicate " << containsDuplicate(data) << std::endl;
}
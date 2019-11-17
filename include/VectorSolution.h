//
// Created by ruoting on 2019/11/13.
//

#ifndef CODING_VECTORSOLUTION_H
#define CODING_VECTORSOLUTION_H

#include "Solution.h"

class VectorSolution : public Solution {
 public:
  void Test() override;
 private:
  void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
  }
  void rotate(vector<vector<int>> &matrix) {
    //\todo
  }

};

#endif //CODING_VECTORSOLUTION_H

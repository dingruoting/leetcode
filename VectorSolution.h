//
// Created by ruoting on 2019/11/13.
//

#ifndef CODING_VECTORSOLUTION_H
#define CODING_VECTORSOLUTION_H

#include <vector>
#include <set>
#include <map>
#include <list>
using namespace std;
class VectorSolution {
 public:
  void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
  }
  void rotate(vector<vector<int>> &matrix) {
    //\todo
  }

  static void Test();

};

#endif //CODING_VECTORSOLUTION_H

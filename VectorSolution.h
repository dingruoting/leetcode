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
    void swap(int* a,int* b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(auto loop = 0;loop < n/2;++loop){
            for(int row_i = loop;row_i < n-1-loop;++row_i){
                auto col_j = loop;
                auto& target = matrix[row_i][col_j];
                int col = col_j;
                int row = row_i;
                    for(auto k = 0;k <4;++k){
                    auto new_row = col;
                    auto new_col = n-row-1;
                    swap(&target,&matrix[new_row][new_col]);
                    row = new_row;
                    col = new_col;
                }

            }

        }
        swap(&matrix[0][0],&matrix[2][0]);
    }

    static int Test();


};


#endif //CODING_VECTORSOLUTION_H

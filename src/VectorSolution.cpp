//
// Created by ruoting on 2019/11/13.
//

#include "../include/VectorSolution.h"

void PrintVectorVector(vector<vector<int>> datas) {
    for (auto &data : datas) {
        for (auto &val : data) {
            std::cout << val << " ";
        }
    }
    std::cout << std::endl;
}

void VectorSolution::Test() {
//    vector<int> data1 = {1,2,3};
//    vector<int> data2 = {4,5,6};
//    vector<int> data3 = {7,8,9};
//  vector<vector<int>> testdata = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//  rotate(testdata);
//  PrintVectorVector(testdata);
    vector<int> data = {7, 1, 5, 3, 6, 4};
    std::cout << "max profix is " << maxProfit(data) << std::endl;

}
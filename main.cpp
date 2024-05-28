#include <iostream>
#include <random>
#include <vector>

int main(){
    std::cout << "hello" << std::endl;
    //固定随机数种子
    std::mt19937 rng(42);
    //定义随机数分布，这里使用均匀分布，范围为1，100
    std::uniform_int_distribution<int> uni(0,1);
    //定义矩阵为256x256
    const int num_row = 5;
    const int num_col = 5;
    //创建二维向量存储
    std::vector<std::vector<int>> matrix;
    matrix.resize(num_row);
    for (auto& row : matrix){
        row.resize(num_col);
    }
    std::cout << "随机数" << std::endl;

    //生成随机数
    for (int i = 0; i < num_row; ++i){
        for (int j = 0; j < num_col; ++j){
            // std::cout << "Setting matrix[" << i << "][" << j << "]" << std::endl;
            matrix[i][j] = uni(rng);
        }
    }
    //打印出来
    for(const auto& num_row : matrix){
        for(int val : num_row){
            std::cout << val << " ";
        }
        std:: cout << std::endl;
    }

    return 0;
}
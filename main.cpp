// #include <iostream>
// #include <random>
// #include <vector>
// #include <opencv4/opencv2/opencv.hpp>
//
// int main(){
//     std::cout << "hello" << std::endl;
//     //固定随机数种子
//     std::mt19937 rng(42);
//     //定义随机数分布，这里使用均匀分布，范围为1，100
//     std::uniform_int_distribution<int> uni(0,1);
//     //定义矩阵为256x256
//     const int num_row = 256;
//     const int num_col = 256;
//     //创建二维向量存储
//     std::vector<std::vector<int>> matrix;
//     matrix.resize(num_row);
//     for (auto& row : matrix){
//         row.resize(num_col);
//     }
//     std::cout << "随机数" << std::endl;
//
//     //生成随机数
//     for (int i = 0; i < num_row; ++i){
//         for (int j = 0; j < num_col; ++j){
//             // std::cout << "Setting matrix[" << i << "][" << j << "]" << std::endl;
//             matrix[i][j] = uni(rng) * 255;
//         }
//     }
//     //打印出来
//     for(const auto& num_row : matrix){
//         for(int val : num_row){
//             std::cout << val << " ";
//         }
//         std:: cout << std::endl;
//     }
//
//     cv::Mat image = cv::imread("resources/images/球球.jpg");
//     if(image.empty()) {
//         std::cerr << "未能打开照片" << std::endl;
//     }else {
//         std::cout << "打开成功" << std::endl;
//     }
//     cv::imshow("loaded image", image);
//     cv::waitKey(0);
//
//     cv::Mat img(num_row,num_col,CV_8UC1);
//     for(int i = 0; i < num_row; ++i) {
//         for(int j = 0; j < num_row; ++j) {
//             img.at<uchar>(i,j) = matrix[i][j];
//         }
//     }
//     cv::imshow("Image",img);
//     cv::waitKey(0);
//     return 0;
// }

#include <opencv2/opencv.hpp>
#include <vector>
#include <random>
#include <iostream>

int main() {
    // 固定随机数种子
    std::mt19937 rng(42);
    // 定义随机数分布，这里使用均匀分布，范围为0, 1
    std::uniform_int_distribution<int> uni(0, 1);
    // 定义矩阵为256x256
    const int num_row = 256;
    const int num_col = 256;
    // 创建二维向量存储
    std::vector<std::vector<int>> matrix(num_row, std::vector<int>(num_col));

    // 定义分块大小
    const int block_size = 32;

    // 生成随机数并分块填充
    for (int i = 0; i < num_row; i += block_size) {
        for (int j = 0; j < num_col; j += block_size) {
            int value = uni(rng) * 255;
            for (int bi = 0; bi < block_size && (i + bi) < num_row; ++bi) {
                for (int bj = 0; bj < block_size && (j + bj) < num_col; ++bj) {
                    matrix[i + bi][j + bj] = value;
                }
            }
        }
    }

    // 创建一个Mat对象
    cv::Mat img(num_row, num_col, CV_8UC1);

    // 将二维向量的数据复制到Mat对象中
    for (int i = 0; i < num_row; ++i) {
        for (int j = 0; j < num_col; ++j) {
            img.at<uchar>(i, j) = matrix[i][j];
        }
    }

    // 显示图像
    cv::imshow("Image", img);

    // 等待用户按下某个键
    cv::waitKey(0);

    // 保存图像
    cv::imwrite("output.png", img);

    return 0;
}

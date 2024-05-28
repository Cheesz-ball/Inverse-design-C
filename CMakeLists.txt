cmake_minimum_required(VERSION 3.22)

project(myproject)
set(CMAKE_CXX_STANDARD 17)

# 找到OpenCV包
find_package(OpenCV 4 REQUIRED)

# 添加可执行文件
add_executable(myproject main.cpp)

# 添加OpenCV头文件路径
include_directories(${OpenCV_INCLUDE_DIRS})

# 链接OpenCV库
target_link_libraries(myproject ${OpenCV_LIBS})

#复制到构建目录
file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})
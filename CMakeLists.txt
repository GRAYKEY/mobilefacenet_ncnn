#1.cmake verson，指定cmake的最小版本号 
cmake_minimum_required(VERSION 2.8)

#2.project name，指定项目的名称，一般和项目的文件夹名称对应
project(mobilefacenet_ncnn C CXX)

#3.set environment variable，设置环境变量
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#4.include头文件目录 
include_directories(${CMAKE_CURRENT_LIST_DIR}/3rdparty/opencv/include
          ${CMAKE_CURRENT_LIST_DIR}/3rdparty/opencv/include/opencv
          ${CMAKE_CURRENT_LIST_DIR}/3rdparty/opencv/include/opencv2
          ${CMAKE_CURRENT_LIST_DIR}/3rdparty/ncnn/include
                    ${CMAKE_CURRENT_LIST_DIR}/src)

#5.library目录及name名称
link_directories(${CMAKE_CURRENT_LIST_DIR}/3rdparty/ncnn/lib
		${CMAKE_CURRENT_LIST_DIR}/3rdparty/opencv/lib)

list(APPEND MBF_LINKER_LIBS opencv_core2413 opencv_highgui2413 opencv_imgproc2413 ncnn)

#6.source directory源文件目录
file(GLOB MBF_SRC ${CMAKE_CURRENT_LIST_DIR}/src/*.h
                    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
set(MBF_COMPILE_CODE ${MBF_SRC})

#7.1.add executable file，编译为可执行文件
add_executable(mobilefacenet_ncnn ${MBF_COMPILE_CODE})
#7.2.add library file，编译为动态库
# add_library(mobilefacenet_ncnn SHARED ${MBF_COMPILE_CODE})

#8.add link library，添加工程所依赖的库
target_link_libraries(mobilefacenet_ncnn ${MBF_LINKER_LIBS})
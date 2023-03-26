cmake_minimum_required(VERSION 3.10)
project(fast_math)

set(CMAKE_CXX_STANDARD 17)
find_package(benchmark REQUIRED)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_FLAGS "-O2")

include_directories(include)

add_library(fast_math test/test.cpp test/benchmark.cpp)
target_link_libraries(fast_math benchmark::benchmark)
target_link_libraries(fast_math ${OpenCV_LIBS})
target_include_directories(fast_math INTERFACE include)

add_executable(test test/test.cpp)
target_link_libraries(test ${OpenCV_LIBS})

add_executable(benchmark test/benchmark.cpp)
target_link_libraries(benchmark benchmark::benchmark ${OpenCV_LIBS})
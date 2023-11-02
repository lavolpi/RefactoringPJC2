cmake_minimum_required(VERSION 3.22)
project(PJC)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         10.0.0
)

FetchContent_MakeAvailable(fmt)

add_executable(Refractoring Refractoring.cpp)
target_link_libraries(Refractoring fmt)
cmake_minimum_required(VERSION 3.0.0)
project(STRUCTURE-DATA VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB_RECURSE SRC_FILES src/*.cc)
add_executable(structured main.cc ${SRC_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_include_directories(structured PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
include(CPack)

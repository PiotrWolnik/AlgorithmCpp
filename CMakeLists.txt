cmake_minimum_required(VERSION 3.14)
project(AlgorithmCpp)

include(cmake/UpdateSubmodules.cmake)
include(CTest)
add_subdirectory(external)

option(COMPILE_PSO "Option to compile PSO project" ON)
if(COMPILE_PSO)
    add_subdirectory(PSO)
endif()

file(GLOB_RECURSE ALL_SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/*.cpp"
    "${CMAKE_SOURCE_DIR}/*.hpp"
)

add_custom_target(
    clang-format
    COMMAND clang-format -i -style=file -assume-filename=${CMAKE_SOURCE_DIR}/.clang-format ${ALL_SOURCE_FILES}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Applying clang-format to all .cpp and .hpp files"
)

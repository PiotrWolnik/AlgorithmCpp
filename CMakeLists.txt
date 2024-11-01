cmake_minimum_required(VERSION 3.14)
project(AlgorithmCpp)

include(cmake/UpdateSubmodules.cmake)
include(CTest)
add_subdirectory(external)

option(COMPILE_PSO "Option to compile PSO project" ON)
if(COMPILE_PSO)
	add_subdirectory(PSO)
endif()

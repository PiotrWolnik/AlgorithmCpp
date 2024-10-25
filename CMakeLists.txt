cmake_minimum_required(VERSION 3.14)
project(AlgorithmCpp)

option(COMPILE_PSO "Option to compile PSO project" OFF)
if(COMPILE_PSO)
	add_subdirectory(PSO)
endif()

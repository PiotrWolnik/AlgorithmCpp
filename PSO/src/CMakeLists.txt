file(GLOB SOURCES "*.cpp")

add_library(MyLib ${SOURCES})

target_include_directories(MyLib PUBLIC ${CMAKE_SOURCE_DIR}/include)
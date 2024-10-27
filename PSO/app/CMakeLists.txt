set(SOURCE_FILES
    main.cpp
)
set(CURR_PROJ_NAME PSO)
add_executable(${CURR_PROJ_NAME} ${SOURCE_FILES})
target_compile_features(${CURR_PROJ_NAME} PRIVATE cxx_std_20)

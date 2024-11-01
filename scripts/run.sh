cmake -B build &&\
cmake --build build &&\
cmake --build build --target clang-format &&\
./build/PSO/app/PSO

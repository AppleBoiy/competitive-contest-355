cmake_minimum_required(VERSION 3.27)
project(competitive_contest)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(officialsol
        src/officialsol.cpp
)

add_executable(defaultsol
        src/defaultsol.cpp
)

add_executable(generator
        src/generator.cpp
)

add_executable(fib
        src/fib.cpp
)

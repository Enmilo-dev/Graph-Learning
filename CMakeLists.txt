cmake_minimum_required(VERSION 3.31)

project(GraphBuilder)

set(CMAKE_CXX_STANDARD 17)

# Include directories for headers - point to the actual locations
include_directories(include/models)
include_directories(include/service)

# Add executable with all source files
add_executable(GraphBuilder
    src/models/graphBuilder.cpp
    src/service/print.cpp
    src/service/bfs.cpp
    src/service/dfs.cpp
    src/service/cycle.cpp
    src/models/menu.cpp
    src/main.cpp
)

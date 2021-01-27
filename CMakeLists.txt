cmake_minimum_required(VERSION 2.8.11)

project(dungeon-game)

# Useful CMake options for Qt projects
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# Create a list with all .cpp source files
set( project_sources
        main.c
        GameService.c)

# Create executable with all necessary source files
add_executable(${PROJECT_NAME}
        ${project_sources}
        )

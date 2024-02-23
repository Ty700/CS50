cmake_minimum_required(VERSION 3.22)

project(VotingSystem VERSION 1.0.0)

option(DEBUG "Debug Mode" OFF)

if(DEBUG)
    message("Exe. in DEBUG MODE")
    add_compile_definitions(DEBUG)
endif()

set(C_STANDARD 17)
set(C_STANDARD_REQUIRED ON)
set(C_EXTENSIONS OFF)

set(EXECUTABLE_NAME VotingSystem)
set(CANDIDATE_LIB candidate)

add_subdirectory(lib)
add_subdirectory(src)
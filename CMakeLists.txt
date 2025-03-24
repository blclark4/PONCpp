cmake_minimum_required(VERSION 3.30)
project(PONCpp LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(PONCpp src/main.cpp)
target_compile_features(PONCpp PRIVATE cxx_std_20)
target_link_libraries(PONCpp PRIVATE SFML::Graphics)

message(STATUS "Available targets: ${SFML_TARGETS}")

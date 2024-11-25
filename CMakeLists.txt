cmake_minimum_required(VERSION 3.10)

project(Space_Shooter)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SFML_DIR "D:/SFML-2.6.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(Space_Shooter src/main.cpp)

target_compile_options(Space_Shooter PRIVATE -Wall -Wextra -Werror)

target_link_libraries(Space_Shooter PRIVATE sfml-system sfml-window sfml-graphics)

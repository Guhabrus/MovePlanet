cmake_minimum_required(VERSION 3.2)

project(MovePlanet C CXX)
SET(EXAMPLE_BINARY "MovePlanet")

# set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(Threads)
find_package(ZLIB)
find_package(Boost COMPONENTS filesystem system program_options regex REQUIRED)

if(NOT ${Boost_FOUND})
    message(FATAL_ERROR "Boost C++ Libraries not found.")
endif()

include_directories(${Boost_INCLUDE_DIR})
link_directories("/usr/local/lib")

add_executable(${EXAMPLE_BINARY} src/main.cpp
src/Window/Window.cpp)

  target_compile_options(${EXAMPLE_BINARY} PRIVATE -Wall -Wextra -pedantic -Werror )


set_target_properties(${EXAMPLE_BINARY} PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON) 
target_link_libraries(${EXAMPLE_BINARY} PRIVATE Qt5::Widgets)

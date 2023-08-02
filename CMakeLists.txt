cmake_minimum_required(VERSION 3.0.0)

project(pid)

option(BUILD_EXAMPLES "Build the example executables (Default ON)." ON) # TODO

add_library(
  pid
  ${CMAKE_CURRENT_SOURCE_DIR}/pid/src/pid.cpp
)

target_include_directories(
  pid
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/pid/include
)


if(BUILD_EXAMPLES)

  add_executable(
    hello_pid
    ${CMAKE_CURRENT_SOURCE_DIR}/example/hello_pid.cpp
  )
  target_link_libraries(hello_pid pid)

endif()

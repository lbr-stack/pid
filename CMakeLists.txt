cmake_minimum_required(VERSION 3.0.0)

project(pid)

option(PID_BUILD_EXAMPLES "Build the example executables (Default ON)." ON) # TODO

add_library(
  pid
  ${CMAKE_CURRENT_SOURCE_DIR}/pid/src/pid.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/pid/src/pid_array.cpp
)

target_include_directories(
  pid
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/pid/include
)


if(PID_BUILD_EXAMPLES)

  add_executable(
    hello_pid
    ${CMAKE_CURRENT_SOURCE_DIR}/example/hello_pid.cpp
  )
  target_link_libraries(hello_pid pid)

  add_executable(
    hello_pid_array
    ${CMAKE_CURRENT_SOURCE_DIR}/example/hello_pid_array.cpp
  )
  target_link_libraries(hello_pid_array pid)

endif()

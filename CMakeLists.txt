cmake_minimum_required(VERSION 3.0.0)

project(pid)

option(PID_BUILD_EXAMPLES "Build the example executables (Default ON)." ON)

add_library(
  pid
  ${CMAKE_CURRENT_SOURCE_DIR}/src/pid.cpp
)

target_include_directories(
  pid
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
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

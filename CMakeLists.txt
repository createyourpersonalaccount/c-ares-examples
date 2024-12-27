cmake_minimum_required(VERSION 3.16)
project(
  cfilesize
  VERSION 0.1
  DESCRIPTION "Examples for the c-ares library"
  LANGUAGES C CXX
)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
find_package(Cares REQUIRED)
add_subdirectory(examples)

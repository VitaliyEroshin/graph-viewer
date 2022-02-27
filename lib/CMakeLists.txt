cmake_minimum_required(VERSION 3.20)

project (
  GRAPHVIEW
  VERSION 1.0
  DESCRIPTION "Library for graph representation"
  LANGUAGES CXX
  )

file(GLOB SOURCES_DIR source/*.cpp)
file(GLOB HEADERS_DIR include/*.hpp)

add_library(service SHARED ${SOURCES_DIR})

target_include_directories(service PRIVATE ${HEADERS_DIR})
set_target_properties(elevator PROPERTIES CXX_STANDARD 17)
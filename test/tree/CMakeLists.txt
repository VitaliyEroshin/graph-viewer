cmake_minimum_required(VERSION 3.20)

project (
  TREEGRAPH
  )
  
set(SOURCES ./tree.cpp)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/../../lib/)

add_executable(tree ${SOURCES})
set_target_properties(tree PROPERTIES
  CXX_STANDARD 17
  )

target_include_directories(tree PUBLIC ${LIB_DIR}/include/)

target_link_libraries(tree ${LIB_DIR}/build/libviewer.dylib)
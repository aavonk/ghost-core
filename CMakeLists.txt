cmake_minimum_required(VERSION 3.20)
project(ghostdb)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(external/googletest)

add_executable(ghostdb main.cpp)
target_link_libraries(ghostdb ghostdb_lib)
#add_executable(ghostdb main.cpp src/core/collection.hpp src/core/collection.cpp src/core/object.cpp src/core/object.hpp src/core/object_property_base.hpp src/core/object_property_int.cpp src/core/object_property_int.hpp src/core/property.hpp src/core/property.cpp)

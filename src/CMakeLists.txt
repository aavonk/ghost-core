set(BINARY ${CMAKE_PROJECT_NAME})

#add executable(ExampleProject main.cpp file1.cpp file1.h, etc)
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.hpp *.cpp)

set(SOURCES ${SOURCES})
add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})
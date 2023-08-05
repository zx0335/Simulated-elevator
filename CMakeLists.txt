set(CMAKE_CXX_COMPILER "arm-linux-gnueabi-g++")

include_directories(./include)

file(GLOB SOURCES ./src/*.cpp)
add_executable(target ${SOURCES})

target_link_libraries(target pthread)
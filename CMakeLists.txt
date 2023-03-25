cmake_minimum_required(VERSION 3.25)
project(sortnode C)

set(CMAKE_C_STANDARD 11)

add_executable(sortnode
        sortnode.c)
set_target_properties(sortnode PROPERTIES LINK_FLAGS "-Wl,--stack,10000000")
target_compile_definitions(sortnode PRIVATE -DHEAP_SIZE=10000000)
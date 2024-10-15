cmake_minimum_required(VERSION 3.8)
project(Test)


# find_package()

# Include_directories()


# add_executable(LFH LF_main.cpp linefollowing.cpp)
add_executable(Test test.cpp)
add_executable(Robothash robothash.cpp)
add_executable(Robot2 main.cpp)




target_link_libraries(Test)
target_link_libraries(Robothash)
target_link_libraries(Robot2)



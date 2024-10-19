cmake_minimum_required(VERSION 3.8)
project(Test)


# find_package()

# Include_directories()


# add_executable(LFH LF_main.cpp linefollowing.cpp)
add_executable(Test test.cpp)
add_executable(Robothash robothash.cpp)
add_executable(Robot2 main.cpp)
add_executable(Twosum robot_twosums.cpp)
add_executable(Remove robot_remove.cpp)
add_executable(Link robot_linkedlist.cpp)
add_executable(Prime primenumber.cpp)








target_link_libraries(Test)
target_link_libraries(Robothash)
target_link_libraries(Robot2)
target_link_libraries(Twosum)
target_link_libraries(Prime)





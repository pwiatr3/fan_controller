cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(FanController)

set(SRC_LIST
    Controller.cpp
    Controller.hpp
    Fan.cpp
    Fan.hpp
    Termomether.cpp
    Termomether.hpp
)

# include_directories(src)
add_library(${PROJECT_NAME}-lib ${SRC_LIST})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib pthread)

# set(TEST_SRC_LIST
#     test/PizzeriaTest.cpp
#     test/test_main.cpp
# )

# link_libraries(gmock)
# add_executable(${PROJECT_NAME}-ut ${TEST_SRC_LIST})
# target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib)

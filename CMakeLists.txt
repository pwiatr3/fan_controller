cmake_minimum_required(VERSION 3.11.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main # release-1.10.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg

project(FanController)

add_compile_options(-Wall -Wextra -Wpedantic -g)
include_directories(.)
add_library(SlowThermometer-lib SlowThermometer/SlowThermometer.cpp)

set(SRC_LIST
    Controller.hpp
    Controller.cpp
    Fan.hpp
    Fan.cpp
    LcdDisplay.hpp
    LcdDisplay.cpp
)

add_library(${PROJECT_NAME}-lib ${SRC_LIST})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib SlowThermometer-lib pthread)

set(TEST_SRC_LIST
    tests/FanTests.cpp
    tests/ControllerTests.cpp
)

add_executable(${PROJECT_NAME}-ut ${TEST_SRC_LIST})

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)

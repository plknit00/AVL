cmake_minimum_required(VERSION 3.14)
project(AVL VERSION 0.1.0 LANGUAGES C CXX)
add_executable(AVL main.cpp tree.cpp avl.cpp)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(
  test_tree
  test.cpp
)
target_link_libraries(
  test_tree
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_tree)

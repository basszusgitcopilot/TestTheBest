cmake_minimum_required(VERSION 3.28)

project(testTheBest)

include(GoogleTest)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(CTest)

add_subdirectory(KnowledgeTest)
add_subdirectory(TestTheBestLib)
add_subdirectory(TestTheBestTests)
add_subdirectory(TestTheBestApp)
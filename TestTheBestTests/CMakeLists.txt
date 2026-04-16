add_executable(
  testTestTheBestLib
  src/GTestTestTheBestLib.cpp
)

target_link_libraries(
  testTestTheBestLib
  PRIVATE
  testTheBestLib
  GTest::gtest_main
)

gtest_discover_tests(testTestTheBestLib)
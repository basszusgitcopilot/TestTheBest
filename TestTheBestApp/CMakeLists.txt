project(testTheBestApp)

file(GLOB TEST_ITEMS_SRC
     "src/testitems/TestItem*.cpp"
)

add_executable(${PROJECT_NAME}
src/TestTheBestApp.cpp
src/testfactories/TestDialogFactoryImpl.cpp
src/testfactories/TestItemListFactory.cpp
src/testfactories/TestItemListFactoryImpl.cpp
src/testfactories/gen/GenTestItemFactoryImpl.cpp
src/testfactories/gen/GenTestItemListFactory.cpp
src/testfactories/gen/GenTestItemListFactoryImpl.cpp
src/utils/MathUtils.cpp
src/utils/StringUtils.cpp
src/utils/TestUtils.cpp
${TEST_ITEMS_SRC}
)

target_include_directories(${PROJECT_NAME}
PRIVATE
include
include/testfactories
include/testfactories/gen
include/testitems
include/testitems/common
include/utils
)

target_link_libraries(${PROJECT_NAME} PRIVATE knowledgeTest)

add_executable(codeGen 
src/CodeGen.cpp
)
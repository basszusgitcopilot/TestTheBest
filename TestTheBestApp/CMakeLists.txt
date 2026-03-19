project(testTheBestApp)

add_executable(${PROJECT_NAME}
src/TestDialogFactoryImpl.cpp
src/TestItemFactoryImpl.cpp
src/TestItemListFactoryImpl.cpp
src/TestTheBestApp.cpp
src/testitems/TestItemAddition.cpp
)

target_include_directories(${PROJECT_NAME}
PRIVATE
include
include/testitems
)

target_link_libraries(${PROJECT_NAME} PRIVATE knowledgeTest)
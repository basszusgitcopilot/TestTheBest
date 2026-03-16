project(testTheBestApp)

add_executable(${PROJECT_NAME}
 src/TestTheBestApp.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE knowledgeTest)
project(testTheBestApp)

add_executable(${PROJECT_NAME}
src/TestDialogFactoryImpl.cpp
src/TestItemFactoryImpl.cpp
src/TestItemListFactoryImpl.cpp
src/TestTheBestApp.cpp
src/testitems/TestItemAddition.cpp
src/testitems/algebra/TestItemQuadraticEquation.cpp
src/testitems/stereometry/TestItemStereoSphereSurfaceVolume.cpp
src/testitems/stereometry/TestItemStereoSphereVolume.cpp
)

target_include_directories(${PROJECT_NAME}
PRIVATE
include
include/testitems
include/testitems/algebra
include/testitems/stereometry
include/utils
)

target_link_libraries(${PROJECT_NAME} PRIVATE knowledgeTest)
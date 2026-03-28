project(testTheBestApp)

add_executable(${PROJECT_NAME}
src/TestDialogFactoryImpl.cpp
src/TestItemFactoryImpl.cpp
src/TestItemListFactoryImpl.cpp
src/TestTheBestApp.cpp
src/testitems/TestItemAddition.cpp
src/testitems/algebra/TestItemAlgebraLinearFactorization.cpp
src/testitems/algebra/TestItemAlgebraLinearFactorization3.cpp
src/testitems/algebra/TestItemAlgebraQuadraticEquation.cpp
src/testitems/stereometry/TestItemStereoSphereSurfaceVolume.cpp
src/testitems/stereometry/TestItemStereoSphereVolume.cpp
src/testitems/stochastic/TestItemStochasticCombination.cpp
src/utils/MathUtils.cpp
src/utils/TestUtils.cpp
)

target_include_directories(${PROJECT_NAME}
PRIVATE
include
include/testitems
include/testitems/algebra
include/testitems/stereometry
include/testitems/stochastic
include/utils
)

target_link_libraries(${PROJECT_NAME} PRIVATE knowledgeTest)
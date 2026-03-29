project(testTheBestApp)

add_executable(${PROJECT_NAME}
src/TestTheBestApp.cpp
src/testfactories/TestDialogFactoryImpl.cpp
src/testfactories/TestItemFactoryImpl.cpp
src/testfactories/TestItemListFactory.cpp
src/testfactories/TestItemListFactoryImpl.cpp
src/testitems/TestItemAddition.cpp
src/testitems/algebra/TestItemAlgebraLinearFactorization.cpp
src/testitems/algebra/TestItemAlgebraLinearFactorization3.cpp
src/testitems/algebra/TestItemAlgebraQuadraticEquation.cpp
src/testitems/differential/TestItemDifferentialRules.cpp
src/testitems/integral/TestItemDefiniteIntegral.cpp
src/testitems/integral/TestItemIntegralRules.cpp
src/testitems/stereometry/TestItemStereoSphereSurfaceVolume.cpp
src/testitems/stereometry/TestItemStereoSphereVolume.cpp
src/testitems/stochastic/TestItemStochasticBernoulliExperiment.cpp
src/testitems/stochastic/TestItemStochasticCombination.cpp
src/utils/MathUtils.cpp
src/utils/StringUtils.cpp
src/utils/TestUtils.cpp
)

target_include_directories(${PROJECT_NAME}
PRIVATE
include
include/testfactories
include/testitems
include/testitems/algebra
include/testitems/differential
include/testitems/integral
include/testitems/stereometry
include/testitems/stochastic
include/utils
)

target_link_libraries(${PROJECT_NAME} PRIVATE knowledgeTest)
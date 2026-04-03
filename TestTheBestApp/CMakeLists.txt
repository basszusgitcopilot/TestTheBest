project(testTheBestApp)

add_executable(${PROJECT_NAME}
src/TestTheBestApp.cpp
src/testfactories/TestDialogFactoryImpl.cpp
src/testfactories/TestItemListFactory.cpp
src/testfactories/TestItemListFactoryImpl.cpp
src/testfactories/gen/GenTestItemFactoryImpl.cpp
src/testfactories/gen/GenTestItemListFactory.cpp
src/testfactories/gen/GenTestItemListFactoryImpl.cpp
src/testitems/TestItemArithmeticAddition.cpp
src/testitems/TestItemAlgebraLinearFactorization.cpp
src/testitems/TestItemAlgebraLinearFactorization3.cpp
src/testitems/TestItemAlgebraQuadraticEquation.cpp
src/testitems/TestItemDifferentialRules.cpp
src/testitems/TestItemIntegralDefinite.cpp
src/testitems/TestItemIntegralRules.cpp
src/testitems/TestItemStereoSphereSurfaceVolume.cpp
src/testitems/TestItemStereoSphereVolume.cpp
src/testitems/TestItemStochasticBernoulliExperiment.cpp
src/testitems/TestItemStochasticCombination.cpp
src/testitems/TestItemVectorCrossProduct.cpp
src/testitems/TestItemVectorDotProduct.cpp
src/utils/MathUtils.cpp
src/utils/StringUtils.cpp
src/utils/TestUtils.cpp
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
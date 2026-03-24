#include "TestItemFactoryImpl.h"

#include "MultipleChoiceTestItem.h"
#include "TestItemAddition.h"
#include "TestItemFactory.h"
#include "TestItemQuadraticEquation.h"
#include "TestItemStereoSphereSurfaceVolume.h"
#include "TestItemStereoSphereVolume.h"
#include "TestItemStochasticCombination.h"

namespace com::prog::testthebest {
auto TestItemFactoryImpl::createTestItem(const Type type) -> std::shared_ptr<TestItem> {
    switch (type) {
    case Type::ADDITION: {
        return std::make_shared<TestItemAddition>();
    }
    case Type::MC_ADDITION: {
        return std::make_shared<MultipleChoiceTestItem<TestItemAddition>>();
    }
    case Type::MC_ALGEBRA_QUADRATIC_EQUATION: {
        return std::make_shared<MultipleChoiceTestItem<TestItemQuadraticEquation>>();
    }
    case Type::MC_STOCHASTIC_COMBINATION: {
        return std::make_shared<MultipleChoiceTestItem<TestItemStochasticCombination>>();
    }
    case Type::MC_STEREO_SPHERE_SURFACEAREA_VOLUME: {
        return std::make_shared<MultipleChoiceTestItem<TestItemStereoSphereSurfaceVolume>>();
    }
    case Type::MC_STEREO_SPHERE_VOLUME: {
        return std::make_shared<MultipleChoiceTestItem<TestItemStereoSphereVolume>>();
    }
    default: {
        return nullptr;
    }
    }
}
} // namespace com::prog::testthebest
#pragma once

#include "TestItem.h"
#include <memory>
#include <string>
#include <utility>

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemStereoRules : public TestItem {
  public:
    TestItemStereoRules();
    auto operator==(const TestItem &other) const -> bool override;
    auto getQuestion() const -> std::string override;
    auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;

  private:
    int32_t ruleIndex;

    const std::vector<std::pair<std::string, std::string>> rules{
        {"das Volumen eines Würfels", "a³"},                                  //
        {"die Oberfläche eines Würfels", "6a²"},                              //
        {"das Volumen eines Quaders", "a⋅b⋅c"},                               //
        {"die Oberfläche eines Quaders", "2(ab + ac + bc)"},                  //
        {"das Volumen eines Prismas", "Grundfläche⋅h"},                       //
        {"die Oberfläche eines Prismas", "2⋅Grundfläche + Mantelfläche"},     //
        {"das Volumen einer Pyramide", "Grundfläche⋅h/3"},                    //
        {"die Oberfläche eines Prismas", "Grundfläche + Mantelfläche"},       //
        {"das Volumen eines Tetraeders", "(a³√2)/12"},                        //
        {"die Oberfläche eines Tetraeders", "a²√3"},                          //
        {"das Volumen eines Zylinders", "r²⋅π⋅h"},                            //
        {"die Oberfläche eines Zylinders", "2⋅r⋅π⋅(h + r)"},                  //
        {"das Volumen eines geraden Kreiskegels", "1/3⋅r²⋅π⋅h"},              //
        {"die Oberfläche eines geraden Kreiskegels", "r⋅π⋅(r + √(h² + r²))"}, //
        {"das Volumen eines Kugels", "4/3⋅r³⋅π"},                             //
        {"die Oberfläche eines Kugels", "4⋅r²⋅π"},                            //
    };
};
} // namespace com::prog::testthebest
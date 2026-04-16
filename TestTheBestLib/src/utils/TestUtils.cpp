#include "TestUtils.h"
#include <fstream>
#include <iostream>

auto writeQuestionsToFile(std::string fileName, std::shared_ptr<KnowledgeTestDialog> testDialog) -> void {
    std::ofstream dialogstream;
    dialogstream.open(fileName);
    auto testItems = testDialog->getKnowledgeTestItems();
    for (uint8_t i = 0; i < testItems.size(); ++i) {
        dialogstream << "--------------------" << std::endl << "Aufgabe " << std::to_string(i + 1) << "." << std::endl;
        dialogstream << testItems.at(i)->getQuestion() << std::endl;
    }
    dialogstream.close();
}
auto writeAnswersToFile(std::string fileName, std::shared_ptr<KnowledgeTestDialog> testDialog) -> void {
    std::ofstream dialogstream;
    dialogstream.open(fileName);
    auto testItems = testDialog->getKnowledgeTestItems();
    for (uint8_t i = 0; i < testItems.size(); ++i) {
        dialogstream << "Lösung " << std::to_string(i + 1) << ".: " << testItems.at(i)->getRightAnswer() << std::endl;
    }
    dialogstream.close();
}
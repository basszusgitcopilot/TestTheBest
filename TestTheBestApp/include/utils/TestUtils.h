#pragma once
#include "KnowledgeTestDialog.h"
#include <memory>
#include <string>

using namespace com::prog::knowledgetest;
auto writeQuestionsToFile(std::string fileName, std::shared_ptr<KnowledgeTestDialog> testDialog) -> void;
auto writeAnswersToFile(std::string fileName, std::shared_ptr<KnowledgeTestDialog> testDialog) -> void;

#include "KnowledgeTestDialogRunner.h"
#include "TestDialogFactoryImpl.h"
#include <iostream>

using namespace com::prog::knowledgetest;
namespace com::prog::testthebest {
class TestTheBestApp {
  public:
    TestTheBestApp(){};

    static auto showQuestion(std::string question) -> void {
        std::cout << "-----------------------------------------------------------------------------" << std::endl;
        std::cout << question << std::endl;
    }

    static auto getAnswer() -> std::string {
        std::string input;
        std::getline(std::cin, input);
        return input;
    }

    static auto reactionToResult(bool result, std::string rightAnswer) -> void {
        std::string correctAnswer = "███████╗███████╗██╗  ██╗██████╗      ██████╗ ██╗   ██╗████████╗██╗\n"
                                    "██╔════╝██╔════╝██║  ██║██╔══██╗    ██╔════╝ ██║   ██║╚══██╔══╝██║\n"
                                    "███████╗█████╗  ███████║██████╔╝    ██║  ███╗██║   ██║   ██║   ██║\n"
                                    "╚════██║██╔══╝  ██╔══██║██╔══██╗    ██║   ██║██║   ██║   ██║   ╚═╝\n"
                                    "███████║███████╗██║  ██║██║  ██║    ╚██████╔╝╚██████╔╝   ██║   ██╗\n"
                                    "╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝     ╚═════╝  ╚═════╝    ╚═╝   ╚═╝\n";
        std::string wrongAnswer{"Alles gut. Die richtige Antwort ist: "};

        if (result) {
            std::cout << std::endl << std::endl << correctAnswer << std::endl << std::endl;
        } else {
            std::cout << std::endl << std::endl << wrongAnswer << rightAnswer << std::endl << std::endl;
        }
    }

    static auto useStatistics(KnowledgeTestDialogRunner::KnowledgeTestDialogStatus testDialogStatus,
                              KnowledgeTestDialogRunner::KnowledgeTestDialogRunnerStatistic statistics) -> void {
        if (testDialogStatus == KnowledgeTestDialogRunner::KnowledgeTestDialogStatus::START_TURN) {
            std::cout << "Number of remaining questions: " << statistics.numOfRemainingTestItems << std::endl;
        } else if (testDialogStatus == KnowledgeTestDialogRunner::KnowledgeTestDialogStatus::ENDED) {
            std::cout << "Number of questions: " << statistics.numOfTestItems << std::endl;
            std::cout << "Number of correct answers: " << statistics.numOfCorrectAnswers << std::endl;
            std::cout << "Number of tries: " << statistics.numOfTries << std::endl;
        }
    }

    auto run() -> void {
        auto testDialogFactory = std::make_shared<TestDialogFactoryImpl>();
        auto testDialog = testDialogFactory->createTestDialog();

        KnowledgeTestDialogRunner testDialogRunner({.repeatUntilCorrectAnswer = false,
                                                    .removeOnlyCorrectlyAnsweredItems = true,
                                                    .showQuestion = showQuestion,
                                                    .getAnswer = getAnswer,
                                                    .reactionToResult = [](bool result, std::string rightAnswer) { reactionToResult(result, rightAnswer); },
                                                    .useStatistics = useStatistics});
        testDialogRunner.runKnowledgeTestDialog(testDialog);
    }

  private:
};
} // namespace com::prog::testthebest

using namespace com::prog::testthebest;
auto main(int /*argc*/, char * /*argv*/[]) -> int {
    TestTheBestApp().run();
    return 0;
}
//
// Created by gallaann on 13.04.23.
//

#include "StreamingTextEditor.h"

#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <filesystem>

namespace {
    enum{
        SUCCESS = 0,
        ERROR = 1
    };

    std::shared_ptr<IOperation> firstOperation{};
    std::shared_ptr<IOperation> prevOperation{};

    std::vector<std::string> splitInputIntoOperationsWithArguments(const std::string &argumentsToSplit) {
        std::stringstream expression(argumentsToSplit);
        std::vector<std::string> splitedArguments;
        std::string operation;
        while (std::getline(expression, operation, '|')) {
            splitedArguments.push_back(operation);
        }
        return splitedArguments;
    }

    std::shared_ptr<IOperation> getCurrentOperation(const std::string &operation) {
        size_t spacePosition = operation.find(' ');
        std::string operationType = operation.substr(0, spacePosition);

        std::shared_ptr<IOperation> cur_operation;

        if (operationType == "echo") {
            std::string str = operation.substr(spacePosition + 1);
            return std::make_shared<EchoOperation>(str);
        }
        if (operationType == "cat") {
            std::filesystem::path filename = operation.substr(spacePosition + 1);
            return std::make_shared<CatOperation>(filename);
        }
        if (operationType == "grep") {
            std::string substr = operation.substr(spacePosition + 1);
            return std::make_shared<GrepOperation>(substr);
        }
        
        //error
        std::cerr << "Unknown operation type: " << operationType << std::endl;
        return nullptr;
    }

    void addToStream(const std::shared_ptr<IOperation> currentOperation) {
        if(!currentOperation){
            return;
        }

        if (firstOperation) {
            prevOperation->SetNextOperation(currentOperation);
            prevOperation = currentOperation;
            return;
        }

        firstOperation = currentOperation;
        prevOperation = currentOperation;
    }

    void output(){
        firstOperation->HandleEndOfInput();
    };
}

namespace StreamingTextEditor {
    int TextEditor::execute(int argc, char **argv) {
        if (argc < 2) {
            std::cerr << "Usage: " << argv[0] << " expression\n";
            return ERROR;
        }

        operations = splitInputIntoOperationsWithArguments(argv[1]);

        std::shared_ptr<IOperation> currentOperation{};
        for (const auto &operation: operations) {
            addToStream(getCurrentOperation(operation));
        }

        output();

        return SUCCESS;
    }
}

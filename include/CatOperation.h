//
// Created by gallaann on 12.04.23.
//

#pragma once

#include "IOperation.h"

#include <fstream>
#include <iostream>

class CatOperation : public IOperation {
public:
    void ProcessLine(const std::string &str) override {
        m_nextOp->ProcessLine(str);
    }

    void HandleEndOfInput() override {
        std::ifstream input(m_fileName);

        if (!input) {
            std::cerr << "Error: could not open file: " << m_fileName << std::endl;
            return;
        }

        std::string currentLine;
        while (getline(input, currentLine)) {
            if (m_nextOp) {
                m_nextOp->ProcessLine(currentLine);
            }
            std::cout << currentLine << std::endl;
        }

        if (m_nextOp) {
            m_nextOp->HandleEndOfInput();
            return;
        }
    }

    void SetNextOperation(std::shared_ptr<IOperation> nextOp) override {
        m_nextOp = nextOp;
    }

    CatOperation(const std::string &fileName) : m_fileName(fileName), m_nextOp(nullptr) {}

private:
    std::string m_fileName;
    std::shared_ptr<IOperation> m_nextOp;
};

//
// Created by gallaann on 12.04.23.
//

#include "IOperation.h"

#include <iostream>

class GrepOperation : public IOperation {
public:
    void ProcessLine(const std::string &str) override {
        if (str.find(m_subString) == std::string::npos) {
            return;
        }
        if (m_nextOp) {
            m_nextOp->ProcessLine(str);
            return;
        }
        std::cout << str;
    }

    void HandleEndOfInput() override {
        if (m_nextOp) {
            m_nextOp->HandleEndOfInput();
            return;
        }
    }

    void SetNextOperation(std::shared_ptr<IOperation> nextOp) override {
        m_nextOp = nextOp;
    }

    GrepOperation(const std::string &subString) : m_subString(subString), m_nextOp(nullptr) {}

private:
    std::string m_subString;
    std::shared_ptr<IOperation> m_nextOp;
};

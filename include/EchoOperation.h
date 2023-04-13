//
// Created by gallaann on 12.04.23.
//

#pragma once

#include "IOperation.h"

#include <iostream>

class EchoOperation : public IOperation {
public:
    void ProcessLine(const std::string &str) override {
        if (m_nextOp){
            m_nextOp->ProcessLine(m_string);
            return;
        }
        std::cout << m_string << std::endl;
    }

    void HandleEndOfInput() override {
        if (m_nextOp){
            m_nextOp->ProcessLine(m_string);
            m_nextOp->HandleEndOfInput();
            return;
        }
        std::cout << m_string << std::endl;
    }

    void SetNextOperation(std::shared_ptr<IOperation> nextOp) override {
        m_nextOp = nextOp;
    }

    EchoOperation(const std::string &string) : m_string(string), m_nextOp(nullptr) {}

private:
    std::string m_string;
    std::shared_ptr<IOperation> m_nextOp;
};

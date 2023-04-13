//
// Created by gallaann on 12.04.23.
//

#pragma once

#include "IOperation.h"

#include <iostream>

class EchoOperation : public IOperation {
public:
    void ProcessLine(const std::string &str) override {
        m_nextOp->ProcessLine(m_string);
    }

    void HandleEndOfInput() override {
        if (m_nextOp){
            m_nextOp->HandleEndOfInput();
            return;
        }
        std::cout << m_string;
    }

    void SetNextOperation(IOperation *nextOp) override {
        m_nextOp = nextOp;
    }

    EchoOperation(const std::string &string) : m_string(string), m_nextOp(nullptr) {}

private:
    std::string m_string;
    IOperation *m_nextOp;
};

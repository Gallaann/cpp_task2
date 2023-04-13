//
// Created by gallaann on 12.04.23.
//

#pragma once

#include <string>

class IOperation {
public:
    virtual ~IOperation() {}
    virtual void ProcessLine(const std::string& str) = 0;
    virtual void HandleEndOfInput() = 0;
    virtual void SetNextOperation(IOperation* nextOp) = 0;
};

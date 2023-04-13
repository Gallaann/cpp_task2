//
// Created by gallaann on 12.04.23.
//

#pragma once

#include <string>
#include <memory>

class IOperation {
public:
    virtual ~IOperation() {}
    virtual void ProcessLine(const std::string& str) = 0;
    virtual void HandleEndOfInput() = 0;
    virtual void SetNextOperation(std::shared_ptr<IOperation>  nextOp) = 0;
};

//
// Created by gallaann on 13.04.23.
//

#pragma once

#include "CatOperation.h"
#include "EchoOperation.h"
#include "GrepOperation.h"

#include <vector>

namespace StreamingTextEditor{
    class TextEditor{
    public:
        int execute(int argc, char** argv);

    private:
        std::vector<std::string> operations;
    };
}
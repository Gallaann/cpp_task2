//
// Created by gallaann on 13.04.23.
//

#pragma once

#include "../include/CatOperation.h"
#include "../include/EchoOperation.h"
#include "../include/GrepOperation.h"

#include <vector>

namespace StreamingTextEditor{
    class TextEditor{
    public:
        int execute(int argc, char** argv);

    private:
        std::vector<std::string> operations;
    };
}
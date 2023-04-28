//
// Created by gallaann on 07.04.23.
//

#include <gtest/gtest.h>

#include "StreamingTextEditor.h"

TEST(CatOperationTest, FileWithoutBreaks) {
    std::ostringstream output;
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    std::string expectedOutput = "This is a test file\n";

    std::shared_ptr<IOperation> firstOperation = std::make_shared<CatOperation>("../../tests/test.txt");
    firstOperation->HandleEndOfInput();

    std::cout.rdbuf(coutBuffer);
    std::string actualOutput = output.str();

    EXPECT_EQ(actualOutput, expectedOutput);
}

TEST(CatOperationTest, FileWithBreaks) {
    std::ostringstream output;
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    std::string expectedOutput = "first line\nsecond line\n\nline after break\n";

    std::shared_ptr<IOperation> firstOperation = std::make_shared<CatOperation>("../../tests/test_with_line_breaks.txt");
    firstOperation->HandleEndOfInput();

    std::cout.rdbuf(coutBuffer);
    std::string actualOutput = output.str();

    EXPECT_EQ(actualOutput, expectedOutput);
}

TEST(CatOperationTest, NonexistentFile) {
    std::ostringstream output;
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    std::string expectedOutput = "This is a test file\n";

    std::shared_ptr<IOperation> firstOperation = std::make_shared<CatOperation>("../../tests/no.txt");
    firstOperation->HandleEndOfInput();

    std::cout.rdbuf(coutBuffer);
    std::string actualOutput = output.str();

    EXPECT_FALSE(actualOutput == expectedOutput);
}

TEST(CatOperationTest, TwoFilesInARow) {
    std::ostringstream output;
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    std::string expectedOutput = "This is a test file\nThis is a test file\n";

    std::shared_ptr<IOperation> firstOperation = std::make_shared<CatOperation>("../../tests/test.txt");
    std::shared_ptr<IOperation> secondOperation = std::make_shared<CatOperation>("../../tests/test.txt");
    firstOperation->SetNextOperation(secondOperation);

    firstOperation->HandleEndOfInput();

    std::cout.rdbuf(coutBuffer);
    std::string actualOutput = output.str();

    EXPECT_EQ(actualOutput, expectedOutput);
}

TEST(CatOperationTest, StringOnInput) {
    std::ostringstream output;
    std::streambuf *coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    std::string expected_output = "This is a test string\n";

    std::shared_ptr<IOperation> Operation = std::make_shared<CatOperation>("test");
    Operation->ProcessLine("This is a test string");

    std::cout.rdbuf(coutBuffer);
    std::string actual_output = output.str();

    EXPECT_EQ(actual_output, expected_output);
}

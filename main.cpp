#include "StreamingTextEditor.h"

int main(int argc, char* argv[]) {
    StreamingTextEditor::TextEditor textEditor{};
    textEditor.execute(argc, argv);

    return 0;
}

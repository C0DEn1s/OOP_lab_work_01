#include "text_editor.h"

#include <utility>

using namespace std;

TextEditOperation::TextEditOperation() = default;

TextEditOperation::TextEditOperation(const string& op, string s, const unsigned int& pos)
                                : operation(recognizeOperation(op)),
                                  text(move(s)),
                                  position(pos) {}

TextEditOperation::TextEditOperation(const TextEditOperation& copy_class) = default;

const string& TextEditOperation::getText() const {
    return text;
}

Operation TextEditOperation::getOperation() const {
    return operation;
}

unsigned int TextEditOperation::getPosition() const {
    return position;
}

void TextEditOperation::setOperation(const string& op) {
    operation = recognizeOperation(op);
}

void TextEditOperation::setText(const string& s) {
    text = s;
}

void TextEditOperation::setPosition(const unsigned int& pos) {
    position = pos;
}

Operation recognizeOperation(const string& s) {
    if (s == "INSERT") {
        return Operation::Insert;
    } else if (s == "DELETE") {
        return Operation::Delete;
    }
    return Operation::NoAction;
}
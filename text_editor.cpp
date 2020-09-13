#include "text_editor.h"

TextEditOperation::TextEditOperation() {

}

TextEditOperation::TextEditOperation(const Operation& op, const string& s, const unsigned int& pos)
                                : operation(op),
                                  text(s),
                                  position(pos) {}

TextEditOperation::TextEditOperation(const TextEditOperation& copy_class)
                                : operation(copy_class.operation),
                                  text(copy_class.text),
                                  position(copy_class.position) {}

const string& TextEditOperation::getText() const {
    return text;
}

Operation TextEditOperation::getOperation() const {
    return operation;
}

unsigned int TextEditOperation::getPosition() const {
    return position;
}

void TextEditOperation::setOperation(const Operation& op) {
    operation = op;
}

void TextEditOperation::setText(const string& s) {
    text = s;
}

void TextEditOperation::setPosition(const unsigned int& pos) {
    position = pos;
}

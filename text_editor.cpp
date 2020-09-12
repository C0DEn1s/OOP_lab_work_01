#include "text_editor.h"

TextEditOperation::TextEditOperation() {

}

TextEditOperation::TextEditOperation(const Operation& op, const string& s, const int& pos)
                                : operation(op),
                                  text(s),
                                  position(pos) {}

TextEditOperation::TextEditOperation(const TextEditOperation& copy_class)
                                : operation(copy_class.operation),
                                  text(copy_class.text),
                                  position(copy_class.position) {}

string TextEditOperation::GetText() const {
    return text;
}

Operation TextEditOperation::GetOperation() const {
    return operation;
}

int TextEditOperation::GetPosition() const {
    return position;
}

void TextEditOperation::SetOperation(const Operation &op) {
    operation = op;
}

void TextEditOperation::SetText(const string &s) {
    text = s;
}

void TextEditOperation::SetPosition(const int &pos) {
    position = pos;
}

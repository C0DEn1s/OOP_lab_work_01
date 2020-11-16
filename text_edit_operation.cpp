#include "text_edit_operation.h"

using namespace std;

TextEditOperation::TextEditOperation(string text_, unsigned pos)
                                : text(std::move(text_)),
                                  position(pos) {}

const string& TextEditOperation::getText() const {
    return text;
}

unsigned int TextEditOperation::getPosition() const {
    return position;
}

void TextEditOperation::setText(const string& s) {
    text = s;
}

void TextEditOperation::setPosition(unsigned pos) {
    position = pos;
}
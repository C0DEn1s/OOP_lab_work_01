#include "insert.h"

Insert::Insert(const std::string& text_, unsigned pos)
        : TextEditOperation(text_, pos) {}

void Insert::apply(std::string& text_) const {
    text_.insert(position, text);
}

void Insert::undo(std::string& text_) const {
    text_.erase(position, text.size());
}

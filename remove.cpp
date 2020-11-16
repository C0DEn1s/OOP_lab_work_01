#include "remove.h"

Remove::Remove(const std::string& text_, unsigned pos)
        : TextEditOperation(text_, pos) {}

void Remove::apply(std::string& text_) const {
    text_.erase(position, text.size());
}

void Remove::undo(std::string& text_) const {
    text_.insert(position, text);
}

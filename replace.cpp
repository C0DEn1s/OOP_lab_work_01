#include "replace.h"

Replace::Replace(const std::string& old_, const std::string& new_, unsigned pos)
                    : m_remove(old_, pos),
                      m_insert(new_, pos) {}

void Replace::apply(std::string& text_) const {
    m_remove.apply(text_);
    m_insert.apply(text_);
}

void Replace::undo(std::string& text_) const {
    m_insert.undo(text_);
    m_remove.undo(text_);
}

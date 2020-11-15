#ifndef TEXT_EDITOR_H_INSERT_H
#define TEXT_EDITOR_H_INSERT_H

#include "text_edit_operation.h"

class Insert : public TextEditOperation {
public:
    Insert(const std::string& text_, size_t position_);
    void apply(std::string& text_) const override;
    void undo(std::string& text_) const override;
};

#endif //TEXT_EDITOR_H_INSERT_H

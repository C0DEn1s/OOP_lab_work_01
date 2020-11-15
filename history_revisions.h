#ifndef LAB_WORK_01_HISTORY_REVISIONS_H
#define LAB_WORK_01_HISTORY_REVISIONS_H

#include "Stack.h"
#include "text_edit_operation.h"

#include <iostream>

class EditHistory {
public:
    EditHistory() = default;

    void insert(const std::string& text_, unsigned pos);
    void remove(unsigned pos, unsigned length_);
    void replace(const std::string& new_, size_t position_, unsigned pos);
    void undo();
    void redo();

    bool is_empty_undo();
    bool is_empty_redo();

    [[nodiscard]] const std::string& getText() const;
private:
    std::string text;
    Stack<std::shared_ptr<TextOperation>> undo_stack;
    Stack<std::shared_ptr<TextOperation>> redo_stack;
    void applyOperation(std::shared_ptr<TextOperation>&& operation_);
};

#endif //LAB_WORK_01_HISTORY_REVISIONS_H

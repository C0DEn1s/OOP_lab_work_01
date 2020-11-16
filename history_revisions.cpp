#include "history_revisions.h"
#include "remove.h"
#include "insert.h"
#include "replace.h"


void EditHistory::remove(unsigned pos, size_t length_) {
    if ((pos + length_ > text.size()) || (length_ == 0)) {
        std::cerr << "Invalid remove\n";
        return;
    }
    redo_stack.clear();
    applyOperation(std::make_shared<Remove>(text.substr(pos, length_), pos));
}

void EditHistory::insert(const std::string& text_, unsigned pos) {
    if ((pos > text.size()) || text_.empty()) {
        std::cerr << "Invalid insert\n";
        return;
    }
    redo_stack.clear();
    applyOperation(std::make_shared<Insert>(text_, pos));
}

void EditHistory::replace(const std::string& new_, unsigned pos, size_t length_) {
    if ((pos + length_ > text.size()) || new_.empty()) {
        std::cerr << "Invalid replace\n";
        return;
    }
    redo_stack.clear();
    applyOperation(std::make_shared<Replace>(text.substr(pos, length_), new_, pos));
}

void EditHistory::undo() {
    if (undo_stack.empty()) {
        std::cerr << "Unable to undo\n";
        return;
    }
    auto operation = undo_stack.top();
    undo_stack.pop();
    operation->undo(text);
    redo_stack.push(std::move(operation));
}

void EditHistory::redo() {
    if (redo_stack.empty()) {
        std::cerr << "Unable to redo\n";
        return;
    }
    auto operation = redo_stack.top();
    redo_stack.pop();
    operation->apply(text);
    undo_stack.push(std::move(operation));
}

bool EditHistory::is_empty_undo() {
    return undo_stack.empty();
}

bool EditHistory::is_empty_redo() {
    return redo_stack.empty();
}

const std::string& EditHistory::getText() const {
    return text;
}

void EditHistory::applyOperation(std::shared_ptr<TextOperation>&& operation_) {
    operation_->apply(text);
    undo_stack.push(std::move(operation_));
}

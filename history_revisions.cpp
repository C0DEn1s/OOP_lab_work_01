#include "history_revisions.h"

#include <utility>


EditHistory::EditHistory() = default;

EditHistory::EditHistory(const Stack <TextEditOperation>& f, const Stack <TextEditOperation>& s, bool flag)
                        : first(f),
                          second(s),
                          was_undo(flag) {}

EditHistory::EditHistory(const EditHistory& other)
                        : first(other.first),
                          second(other.second),
                          was_undo(other.was_undo) {}

EditHistory::~EditHistory() = default;

void EditHistory::insert(std::string s, unsigned pos) {
    if (was_undo) {
        second.clear();
        was_undo = false;
    }
    TextEditOperation in("INSERT", std::move(s), pos);
    first.push(in);
}

void EditHistory::erase(std::string s, unsigned pos) {
    if (was_undo) {
        second.clear();
        was_undo = false;
    }
    TextEditOperation in("DELETE", std::move(s), pos);
    first.push(in);
}

void EditHistory::undo() {
    NodeStack<TextEditOperation> p;
    size_t length = first.size();
    for (size_t i = 0; i < length; ++i) {
        p = first.getTop();
        second.push(*p);
        first.pop();
    }
    was_undo = true;
}
void EditHistory::redo() {
    NodeStack<TextEditOperation> p;
    size_t length = second.size();
    for (size_t i = 0; i < length; ++i) {
        p = second.getTop();
        first.push(*p);
        second.pop();
    }
    was_undo = true;
}

unsigned int EditHistory::size() const {
    return first.size() + second.size();
}

NodeStack<TextEditOperation> EditHistory::getTopFirst() const {
    return first.getTop();
}

NodeStack<TextEditOperation> EditHistory::getTopSecond() const {
    return second.getTop();
}

bool EditHistory::empty_f() {
    return first.empty();
}

bool EditHistory::empty_s() {
    return second.empty();
}

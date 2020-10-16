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
        second.emplace(std::move(first.getTop()));
        first.pop();
    }
    was_undo = true;
}

void EditHistory::redo() {
    NodeStack<TextEditOperation> p;
    size_t length = second.size();
    for (size_t i = 0; i < length; ++i) {
        first.emplace(std::move(second.getTop()));
        second.pop();
    }
    was_undo = true;
}

unsigned int EditHistory::size() const {
    return first.size() + second.size();
}

const TextEditOperation& EditHistory::getTopFirst() const {
    return first.getTop();
}

TextEditOperation& EditHistory::getTopFirst() {
    return const_cast<TextEditOperation&>(const_cast<const EditHistory&>(*this).getTopFirst());  // first.getTop();
}

const TextEditOperation& EditHistory::getTopSecond() const {
    return second.getTop();
}

TextEditOperation& EditHistory::getTopSecond() {
    return const_cast<TextEditOperation&>(const_cast<const EditHistory&>(*this).getTopSecond());  // second.getTop();
}

bool EditHistory::empty_f() {
    return first.empty();
}

bool EditHistory::empty_s() {
    return second.empty();
}

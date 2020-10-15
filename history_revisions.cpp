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

EditHistory::~EditHistory() {
    std::cerr << "~edithistory" << endl;
}

void EditHistory::insert(string s, unsigned pos) {
    if (was_undo) {
        second.clear();
    }
    TextEditOperation in("INSERT", std::move(s), pos);
    first.push(in);
}

void EditHistory::erase(string s, unsigned pos) {
    if (was_undo) {
        second.clear();
    }
    TextEditOperation in("DELETE", std::move(s), pos);
    first.push(in);
}

void EditHistory::undo() {
    NodeStack<TextEditOperation> p;
    while (first.getTop()) {
        p = first.getTop();
        second.push(*p);
        first.pop();
    }
    was_undo = true;
}
void EditHistory::redo() {
    NodeStack<TextEditOperation> p;
    while (second.getTop()) {
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

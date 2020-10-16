#ifndef LAB_WORK_01_HISTORY_REVISIONS_H
#define LAB_WORK_01_HISTORY_REVISIONS_H

#include "Stack.h"
#include "text_editor.h"

#include <iostream>
#include <iomanip>

class EditHistory {
public:
    EditHistory();
    EditHistory(const Stack<TextEditOperation>& f, const Stack<TextEditOperation>& s, bool flag);
    EditHistory(const EditHistory& other);

    ~EditHistory();

    void insert(std::string s, unsigned pos);
    void erase(std::string s, unsigned pos);
    void undo();
    void redo();

    bool empty_f();
    bool empty_s();
    [[nodiscard]] unsigned int size() const;
    [[nodiscard]] const TextEditOperation& getTopFirst() const;
    [[nodiscard]] TextEditOperation& getTopFirst();
    [[nodiscard]] const TextEditOperation& getTopSecond() const;
    [[nodiscard]] TextEditOperation& getTopSecond();
private:
    Stack<TextEditOperation> first;
    Stack<TextEditOperation> second;
    bool was_undo = false;
};

#endif //LAB_WORK_01_HISTORY_REVISIONS_H

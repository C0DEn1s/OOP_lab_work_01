#ifndef LAB_WORK_01_HISTORY_REVISIONS_H
#define LAB_WORK_01_HISTORY_REVISIONS_H

#include "Stack.h"

#include <iostream>
#include <iomanip>

using namespace std;

class EditHistory {
public:
    void addText(const string& s);
    void undo();
    void redo();
private:
    Stack<string> first;
    Stack<string> second;
};

void EditHistory::addText(const string &s) {
    first.push(s);

}

#endif //LAB_WORK_01_HISTORY_REVISIONS_H

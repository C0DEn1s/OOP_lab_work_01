#ifndef LAB_WORK_01_TEXT_EDITOR_H
#define LAB_WORK_01_TEXT_EDITOR_H

#include <string>

enum class Operation {
    Insert,
    Delete
};

using namespace std;

class TextEditOperation {
public:
    TextEditOperation();
    TextEditOperation(const Operation& op, const string& s, const int& pos);
    TextEditOperation(const TextEditOperation& copy_class);

    Operation GetOperation() const;
    void SetOperation(const Operation& op);

    string GetText() const;
    void SetText(const string& s);

    int GetPosition() const;
    void SetPosition(const int& pos);

private:
    Operation operation;
    string text;
    int position;
};

#endif //LAB_WORK_01_TEXT_EDITOR_H

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
    TextEditOperation(const Operation& op, const string& s, const unsigned int& pos);
    TextEditOperation(const TextEditOperation& copy_class);

    Operation getOperation() const;
    void setOperation(const Operation& op);

    string getText() const;
    void setText(const string& s);

    unsigned int getPosition() const;
    void setPosition(const unsigned int& pos);

private:
    Operation operation;
    string text;
    unsigned int position;
};

#endif //LAB_WORK_01_TEXT_EDITOR_H

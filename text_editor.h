#ifndef LAB_WORK_01_TEXT_EDITOR_H
#define LAB_WORK_01_TEXT_EDITOR_H

#include <string>

enum class Operation {
    NoAction,
    Insert,
    Delete
};

class TextEditOperation {
public:
    TextEditOperation();

    TextEditOperation(const std::string& op, std::string s, const unsigned int& pos);
    TextEditOperation(const TextEditOperation& copy_class);

    [[nodiscard]] Operation getOperation() const;
    void setOperation(const std::string& s);

    [[nodiscard]] const std::string& getText() const;
    void setText(const std::string& s);

    [[nodiscard]] unsigned int getPosition() const;
    void setPosition(const unsigned int& pos);

private:
    Operation operation = Operation::NoAction;
    std::string text;
    unsigned int position = 0;
};

Operation recognizeOperation(const std::string& s);

#endif //LAB_WORK_01_TEXT_EDITOR_H

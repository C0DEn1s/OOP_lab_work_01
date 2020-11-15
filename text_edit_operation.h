#ifndef LAB_WORK_01_TEXT_EDITOR_H
#define LAB_WORK_01_TEXT_EDITOR_H

#include "text_operation.h"

class TextEditOperation : public TextOperation {
public:
    TextEditOperation() = default;
    TextEditOperation(std::string text_, unsigned pos);
    TextEditOperation(const TextEditOperation& copy_class) = default;

    [[nodiscard]] const std::string& getText() const;
    void setText(const std::string& s);

    [[nodiscard]] unsigned int getPosition() const;
    void setPosition(unsigned pos);

protected:
    std::string text;
    unsigned int position = 0;
};

#endif //LAB_WORK_01_TEXT_EDITOR_H

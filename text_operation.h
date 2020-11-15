#ifndef TEXT_OPERATION_H
#define TEXT_OPERATION_H

#include <string>

class TextOperation {
public:
    virtual void apply(std::string& text_) const = 0;
    virtual void undo(std::string& text_) const = 0;
    virtual ~TextOperation() = default;
};

#endif //TEXT_OPERATION_H


#ifndef LAB_WORK_01_TEXT_EDITOR_H
#define LAB_WORK_01_TEXT_EDITOR_H

#include <string>

class TextEditor {
public:
    void Insert(std::string& s);
    void Delete(std::string& s);
private:
    std::string text;
};

#endif //LAB_WORK_01_TEXT_EDITOR_H

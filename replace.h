#ifndef LAB_WORK_01_REPLACE_H
#define LAB_WORK_01_REPLACE_H

#include "remove.h"
#include "insert.h"

class Replace : public TextOperation {
public:
    Replace(const std::string& old_, const std::string& new_, unsigned pos);
    void apply(std::string& text_) const override;
    void undo(std::string& text_) const override;
private:
    Remove m_remove;
    Insert m_insert;
};

#endif //LAB_WORK_01_REPLACE_H

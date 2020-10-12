#include "text_editor.h"
#include "history_revisions.h"
#include <iostream>

#include <cassert>

void TestEditorCtor() {
    TextEditOperation defCtor;
    assert(defCtor.getOperation() == Operation::NoAction &&
           defCtor.getText() == "" &&
           defCtor.getPosition() == 0);

    TextEditOperation parCtor("INSERT", "Hello!", 3);
    assert(parCtor.getOperation() == Operation::Insert &&
           parCtor.getText() == "Hello!" &&
           parCtor.getPosition() == 3);

    TextEditOperation copyCtor = parCtor;
    assert(copyCtor.getOperation() == parCtor.getOperation() &&
           copyCtor.getText() == parCtor.getText() &&
           copyCtor.getPosition() == parCtor.getPosition());

    std::cerr << "TextEditor Constructor Test OK" << std::endl;
}

void TestEditorAccess() {
    auto access = TextEditOperation("INSERT", "Hi!", 3);
    assert(access.getOperation() == Operation::Insert &&
           access.getText() == "Hi!" &&
           access.getPosition() == 3);

    access.setOperation("DELETE");
    assert(access.getOperation() == Operation::Delete);

    access.setText("Bye!");
    assert(access.getText() == "Bye!");

    access.setPosition(5);
    assert(access.getPosition() == 5);

    std::cerr << "TextEditor Access Test OK" << std::endl;
}

void TestHistoryCtor();
void TestHistoryAccess();

void TestStack() {
    Stack<int> stack;
    assert(stack.empty());

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    assert(*stack.getTop() == 4);
    assert(stack.size() == 4);

    stack.pop();
    assert(*stack.getTop() == 3);
    assert(stack.size() == 3);

    Stack<int> copy = stack;
    assert(*copy.getTop() == *stack.getTop());
    assert(copy.size() == stack.size());

    stack.clear();
    assert(stack.empty());
    std::cerr << "Satck Test is OK" << std::endl;
}

void Test() {
    TestEditorCtor();
    TestEditorAccess();
    TestStack();
    std::cerr << "All Tests OK" << std::endl;
}
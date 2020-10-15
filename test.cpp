#include "text_editor.h"
#include "history_revisions.h"
#include <iostream>

#include <cassert>

void TestEditorCtor() {
    TextEditOperation defCtor;
    assert(defCtor.getOperation() == Operation::NoAction &&
           defCtor.getText().empty() &&
           defCtor.getPosition() == 0);

    TextEditOperation parCtor("INSERT", "Hello!", 3);
    assert(parCtor.getOperation() == Operation::Insert &&
           parCtor.getText() == "Hello!" &&
           parCtor.getPosition() == 3);

    const TextEditOperation& copyCtor = parCtor;
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
    std::cerr << "Stack Test OK" << std::endl;
}

void TestHistoryContainer() {
    EditHistory history;
    assert(history.empty_f());
    assert(history.empty_s());

    history.insert("Hello, ", 0);
    assert(history.size() == 1);
    auto temp = *(history.getTopFirst());
    string bottom = temp.getText();   // first element
    assert(bottom == "Hello, ");

    history.erase("o, ", 4);
    assert(history.size() == 2);

    Stack<TextEditOperation> f;
    f.push({"INSERT", "Text", 0});
    f.push({"INSERT", "Text2", 4});

    Stack<TextEditOperation> s;
    s.push({"INSERT", "Text3", 0});
    s.push({"INSERT", "Text4", 5});

    EditHistory stack(f, s, false);
    assert(stack.size() == 4);

    stack.~EditHistory();
    assert(stack.empty_f());
    assert(stack.empty_s());

    EditHistory copy = history;
    assert(copy.size() == history.size());
    temp = *(copy.getTopFirst());
    assert(temp.getText() == "o, ");

    history.undo();
    temp = *(history.getTopSecond());
    assert(temp.getText() == bottom);

    history.redo();
    temp = *(history.getTopFirst());
    assert(temp.getText() == "o, ");

    history.insert("o, world!", 4);
    assert(history.empty_s());
    assert(history.size() == 3);

    std::cerr << "TestHistoryContainer Test OK" << std::endl;
}

void Test() {
    TestEditorCtor();
    TestEditorAccess();
    TestStack();
    TestHistoryContainer();
    std::cerr << "All Tests OK" << std::endl;
}
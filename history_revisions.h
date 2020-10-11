#ifndef LAB_WORK_01_HISTORY_REVISIONS_H
#define LAB_WORK_01_HISTORY_REVISIONS_H

#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class NodeStack {
    T data;
    NodeStack<T>* next;
};

template <typename T>
class Stack {
public:
    Stack();
    Stack(const Stack<T>& stack);
    ~Stack();

    void push(const T& data);
    T pop();
    void clear();
    const T& peek() const;
    [[nodiscard]] unsigned int size() const;
    NodeStack<T>* getTop() const;

private:
    NodeStack<T>* pTop;  //
};

template <typename T>
class EditHistory {
public:
    void undo();

private:
    Stack<T> cancel_1;
    Stack<T> cancel_2;
};

template <typename T>
Stack<T>::Stack() : pTop(nullptr) {}

template<typename T>
Stack<T>::Stack(const Stack<T>& other_stack) {
    NodeStack<T>* p;
    NodeStack<T>* p2;
    NodeStack<T>* cur;

    pTop = nullptr;
    cur = nullptr;

    p = other_stack.pTop;
    while (p != nullptr) {
        p2 = new NodeStack<T>;

        p2->data = p->data;
        p2->next = nullptr;

        if (pTop == nullptr) {
            pTop = p2;
            cur = p2;
        } else {
            cur->next = p2;
            cur = cur->next;
        }

        p = p->next;
    }
}


template<typename T>
Stack<T>::~Stack() {
    clear();
}

template<typename T>
void Stack<T>::push(const T& data) {
    NodeStack<T>* p;
    p = new NodeStack<T>;

    p->data = data;
    p->next = pTop;

    pTop = p;
}

template<typename T>
T Stack<T>::pop() {
    if (pTop == nullptr) {
        cout << "Stack is empty.\n";
        return;
    }
    NodeStack<T>* temp;
    T data = pTop->data;

    temp = pTop;
    pTop = pTop->next;
    delete temp;

    return data;
}

template <typename T>
void Stack<T>::clear() {
    NodeStack<T>* p;
    NodeStack<T>* temp;

    p = pTop;
    while (p != nullptr) {
        temp = p;
        p = p->next;
        delete temp;
    }
    pTop = nullptr;
}

template<typename T>
const T& Stack<T>::peek() const {

}

template<typename T>
unsigned int Stack<T>::size() const {
    if (pTop == nullptr) {
        return 0;
    } else {
        NodeStack<T>* p;
        unsigned int count = 0;
        while (p != nullptr) {
            count++;
            p = p->next;
        }
    }
}

template<typename T>
NodeStack<T>* Stack<T>::getTop() const {
    return pTop;
}

template<typename T>
void printStack(const Stack<T>& stack) {
    if (stack.getTop() == nullptr) {
        cout << "Stack is empty.\n";
    } else {
        NodeStack<T>* p;
        p = stack.getTop();
        while (p != nullptr) {
            cout << p->data << '|';
            p = p->next;
        }
        cout << '\n';
    }
}

#endif //LAB_WORK_01_HISTORY_REVISIONS_H

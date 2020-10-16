#ifndef LAB_WORK_01_STACK_H
#define LAB_WORK_01_STACK_H

#include "history_revisions.h"
#include <iostream>
#include <iomanip>
#include <utility>

template <typename T>
class Stack;
class EditHistory;

template <typename T>
class NodeStack {
public:
    friend Stack<T>;
    friend EditHistory;
    NodeStack() = default;
    bool operator==(const NodeStack<T>& rhs) const;
    bool operator!=(const NodeStack<T>& rhs) const;
    explicit NodeStack(const T& new_value)
                        : data(new_value) {}

    explicit NodeStack(T&& new_value)
                        : data(move(new_value)) {}

    ~NodeStack() = default;
    T operator*();
private:
    T data;
    NodeStack<T>* next;
};

template <typename T>
T NodeStack<T>::operator*() {
    return data;
}

template<class T>
bool NodeStack<T>::operator==(const NodeStack<T> &rhs) const {
    return data == rhs.data;
}

template<class T>
bool NodeStack<T>::operator!=(const NodeStack<T> &rhs) const {
    return data != rhs.data;
}

template <typename T>
class Stack {
public:
    Stack() = default;
    Stack(const Stack<T>& stack);
    Stack& operator=(const Stack& other);
    Stack(Stack<T>&& stack) noexcept;
    Stack& operator=(const Stack&& other) noexcept;
    ~Stack();

    void push(const T& data);
    void pop();
    void clear();
    bool empty();
    [[nodiscard]] unsigned int size() const;
    NodeStack<T> getTop() const;
private:
    NodeStack<T>* pTop = nullptr;
    unsigned size_ = 0;
};

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
    size_ = other_stack.size_;
}

template<typename T>
Stack<T>::Stack(Stack<T>&& stack) noexcept {
    for (NodeStack<T>* tmp = stack.pTop; tmp != nullptr; tmp = tmp->next) {
        push(move(tmp->data));
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
    ++size_;
}

template<typename T>
void Stack<T>::pop() {
    if (pTop == nullptr) {
        std::cout << "Stack is empty.\n";
        return;
    }
    NodeStack<T>* temp;
    temp = pTop;
    pTop = pTop->next;
    delete temp;
    --size_;
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
    size_ = 0;
}

template<typename T>
unsigned int Stack<T>::size() const {
    return size_;
}

template <typename T>
bool Stack<T>::empty() {
    return size_ == 0;
}

template<typename T>
NodeStack<T> Stack<T>::getTop() const {
    return *pTop;
}

template<typename T>
void printStack(const Stack<T>& stack) {
    if (stack.getTop() == nullptr) {
        std::cout << "Stack is empty.\n";
    } else {
        NodeStack<T>* p;
        p = stack.getTop();
        while (p != nullptr) {
            std::cout << p->data << "\n";
            p = p->next;
        }
        std::cout << '\n';
    }
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    *this(other);
    return *this;
//    NodeStack<T>* tmp = other.pTop;
//    NodeStack<T>* p = pTop;
//    for (size_t i = 0; i < other.size_; ++i) {
//        p->data = tmp->data;
//        p = p->next;
//        tmp = tmp->next;
//    }
//    this->size_ = other.size_;
//    return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack&& other) noexcept {
    *this = other;
    return *this;
}

#endif //LAB_WORK_01_STACK_H

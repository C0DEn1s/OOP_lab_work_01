#ifndef LAB_WORK_01_STACK_H
#define LAB_WORK_01_STACK_H
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class Stack;

template <typename T>
class NodeStack {
public:
    friend Stack<T>;
    const T& operator*() {
        return data;
    }
private:
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
    void pop();
    void clear();
    bool empty();
    [[nodiscard]] unsigned int size() const;
    NodeStack<T> getTop() const;
private:
    NodeStack<T>* pTop;
    unsigned size_ = 0;
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
    size_ = other_stack.size_;
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
        cout << "Stack is empty.\n";
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
    if (size_ == 0)  {
        return true;
    }
    return false;
}

template<typename T>
NodeStack<T> Stack<T>::getTop() const {
    return *pTop;
}


template<typename T>
void printStack(const Stack<T>& stack) {
    if (stack.getTop() == nullptr) {
        cout << "Stack is empty.\n";
    } else {
        NodeStack<T>* p;
        p = stack.getTop();
        while (p != nullptr) {
            cout << p->data << "\n";
            p = p->next;
        }
        cout << '\n';
    }
}

#endif //LAB_WORK_01_STACK_H

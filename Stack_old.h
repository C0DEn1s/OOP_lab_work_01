#ifndef LAB_WORK_01_STACK_H
#define LAB_WORK_01_STACK_H

#include "history_revisions.h"
#include <iostream>
#include <iomanip>
#include <utility>
#include <memory>

template <typename T>
class Stack_old;
class EditHistory;

template <typename T>
class NodeStack {
public:
    friend Stack_old<T>;
    friend EditHistory;
    NodeStack() = default;
    bool operator==(const NodeStack<T>& rhs) const;
    bool operator!=(const NodeStack<T>& rhs) const;
    explicit NodeStack(const T& new_value) = delete;
    NodeStack<T>& operator=(const NodeStack& other) = delete;
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
bool NodeStack<T>::operator==(const NodeStack<T>& rhs) const {
    return data == rhs.data;
}

template<class T>
bool NodeStack<T>::operator!=(const NodeStack<T>& rhs) const {
    return data != rhs.data;
}

template <typename T>
class Stack_old {
public:
    Stack_old() = default;
    Stack_old(const Stack_old<T>& stack);
    Stack_old& operator=(const Stack_old& other);
    Stack_old(Stack_old<T>&& stack) noexcept;
    Stack_old& operator=(Stack_old&& other) noexcept;
    ~Stack_old();

    void push(const T& data);
    void emplace(T&& data);
    void pop();
    void clear();
    bool empty();
    [[nodiscard]] unsigned int size() const;
    const T& getTop() const;
    T& getTop();
    //friend std::ostream& operator<<(std::ostream&, const Stack_old<T>&);
    //friend std::istream& operator>>(std::istream&, Stack_old<T>&);
private:
    NodeStack<T>* pTop = nullptr;
    unsigned size_ = 0;
};

template<typename T>
Stack_old<T>::Stack_old(const Stack_old<T>& other_stack) {
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
Stack_old<T>::Stack_old(Stack_old<T>&& stack) noexcept {
    for (NodeStack<T>* tmp = stack.pTop; tmp != nullptr; tmp = tmp->next) {
        emplace(std::move(tmp->data));
    }
}

template<typename T>
Stack_old<T>::~Stack_old() {
    clear();
}

template<typename T>
void Stack_old<T>::push(const T& data) {
    NodeStack<T>* p;
    p = new NodeStack<T>;

    p->data = data;
    p->next = pTop;

    pTop = p;
    ++size_;
}

template <typename T>
void Stack_old<T>::emplace(T&& data) {
    NodeStack<T>* p;
    p = new NodeStack<T>;

    p->data = std::move(data);
    p->next = pTop;

    pTop = p;
    ++size_;
}

template<typename T>
void Stack_old<T>::pop() {
    if (pTop != nullptr) {
        NodeStack<T>* temp;
        temp = pTop;
        pTop = pTop->next;
        delete temp;
        --size_;
    }
}

template <typename T>
void Stack_old<T>::clear() {
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
unsigned int Stack_old<T>::size() const {
    return size_;
}

template <typename T>
bool Stack_old<T>::empty() {
    return size_ == 0;
}

template<typename T>
const T& Stack_old<T>::getTop() const {
    if (pTop == nullptr) {
        throw std::out_of_range("getTop() of empty stack");
    }
    return pTop->data;
}

template<typename T>
T& Stack_old<T>::getTop() {
//    return const_cast<T&>(const_cast<Stack_old<T>&>(*this).getTop());
    return pTop->data;
}

template<typename T>
void printStack(const Stack_old<T>& stack) {
    if (stack.getTop() == nullptr) {
        std::cout << "Stack_old is empty.\n";
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
Stack_old<T>& Stack_old<T>::operator=(const Stack_old& other) {
    if (pTop == other.pTop) {
        return *this;
    }
    NodeStack<T>* tmp = other.pTop;
    Stack_old<T> add;
    for (size_t i = 0; i < other.size_; ++i) {
        add.push(tmp->data);
        tmp = tmp->next;
    }
    clear();
    tmp = add.pTop;
    for (size_t i = 0; i < other.size_; ++i) {
        push(tmp->data);
        tmp = tmp->next;
    }
    this->size_ = other.size_;
    return *this;
}

template<typename T>
Stack_old<T>& Stack_old<T>::operator=(Stack_old&& other) noexcept {
    this->pTop = other.pTop;
    this->size_ = other.size_;
    other.pTop = nullptr;
    other.size_ = 0;
    return *this;
}

//std::ostream& operator<<(std::ostream& stream, const Stack_old<int>& stack) {
//    if (stack.pTop == nullptr) {
//        return stream;
//    }
//    auto p = stack.pTop;
//    auto s = stack.size();
//    stream.write(reinterpret_cast<char*>(&s), sizeof(s));
//    stream << p->value();
//    while (p = p->next().get()) {
//        stream << p->value();
//    }
//    return stream;
//}
//
//template<typename T> std::istream& operator>>(std::istream& stream, Stack_old<T>& stack) {
//    size_t s;
//    stream.read(reinterpret_cast<char*>(&s), sizeof(s));
//    stack.clear();
//    for (size_t i = 0; i < s; ++i) {
//        T temp;
//        stream >> temp;
//        stack.push(temp);
//    }
//    return stream;
//}

#endif //LAB_WORK_01_STACK_H

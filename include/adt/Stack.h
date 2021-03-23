#pragma once

#include "common/Node.h"
#include <ostream>

template <typename T>
class Stack {
  private:
    Node<T> *top;

  public:
    Stack();
    Stack(const Stack<T> &stack);
    Stack<T> &operator=(const Stack<T> &stack);
    ~Stack();
    bool isEmpty() const;
    bool push(T data);
    bool pop();
    bool pop(T &data);
    bool getTop(T &data) const;

    template <typename U>
    friend std::ostream &operator<<(std::ostream &out, const Stack<U> &list);
};

template <typename T>
inline Stack<T>::Stack() : top(nullptr) {}

template <typename T>
inline Stack<T>::Stack(const Stack<T> &stack) : top(stack.top) {
    if (top == nullptr)
        return;
    top = new Node<T>(stack.top->data);
    auto current = top;
    for (auto other = stack.top->next; other != nullptr; other = other->next) {
        current->next = new Node<T>(other->data);
        current = current->next;
    }
}

template <typename T>
inline Stack<T> &Stack<T>::operator=(const Stack<T> &stack) {
    if (this != &stack)
        return *this;
    while (!isEmpty())
        pop();
    top = new Node<T>(stack.top->data);
    auto current = top;
    for (auto other = stack.top->next; other != nullptr; other = other->next) {
        current->next = new Node<T>(other->data);
        current = current->next;
    }
    return *this;
}

template <typename T>
inline Stack<T>::~Stack() {
    while (!isEmpty())
        pop();
}

template <typename T>
inline bool Stack<T>::isEmpty() const {
    return top == nullptr;
}

template <typename T>
inline bool Stack<T>::push(T data) {
    auto temp = new Node<T>(data);
    temp->next = top;
    top = temp;
    return true;
}

template <typename T>
inline bool Stack<T>::pop() {
    if (isEmpty())
        return false;
    auto temp = top;
    top = top->next;
    delete temp;
    return true;
}

template <typename T>
inline bool Stack<T>::pop(T &data) {
    if (isEmpty())
        return false;
    auto temp = top;
    data = temp->data;
    top = temp->next;
    delete temp;
    return true;
}

template <typename T>
inline bool Stack<T>::getTop(T &data) const {
    if (top == nullptr)
        return false;
    data = top->data;
    return true;
}

#pragma once

#include "common/Node.h"

template <typename T>
class Queue {
  public:
    Queue();
    Queue(const Queue<T> &queue);
    Queue<T> &operator=(const Queue<T> &queue);
    ~Queue();
    bool isEmpty() const;
    bool enqueue(T data);
    bool dequeue();
    bool dequeue(T &data);
    bool getFront(T &data) const;

  private:
    Node<T> *start;
    Node<T> *end;
};

template <typename T>
inline Queue<T>::Queue() : start(nullptr), end(nullptr) {}

template <typename T>
inline Queue<T>::Queue(const Queue<T> &queue)
    : start(queue.start), end(queue.end) {
    if (start == nullptr || end == nullptr)
        return;
    start = new Node<T>(start->data);
    auto current = start;
    for (auto other = start->next; other != nullptr; other = other->next) {
        current->next = new Node<T>(other->data);
        current = current->next;
    }
    end = current;
}

template <typename T>
inline Queue<T> &Queue<T>::operator=(const Queue<T> &queue) {
    if (this == &queue)
        return *this;
    while (!isEmpty())
        dequeue();
    if (queue.isEmpty())
        return *this;
    start = new Node<T>(queue.start->data);
    auto current = start;
    for (auto other = queue.start->next; other != nullptr;
         other = other->next) {
        current->next = new Node<T>(other->data);
        current = current->next;
    }
    end = current;
    return *this;
}

template <typename T>
inline Queue<T>::~Queue() {
    while (!isEmpty())
        dequeue();
}

template <typename T>
inline bool Queue<T>::isEmpty() const {
    return start == nullptr;
}

template <typename T>
inline bool Queue<T>::enqueue(T data) {
    auto temp = new Node<T>(data);
    if (isEmpty()) {
        start = temp;
        end = temp;
    } else {
        end->next = temp;
        end = end->next;
    }
    return true;
}

template <typename T>
inline bool Queue<T>::dequeue() {
    if (isEmpty())
        return false;
    if (start == end)
        end = nullptr;
    auto temp = start;
    start = start->next;
    delete temp;
    return true;
}

template <typename T>
inline bool Queue<T>::dequeue(T &data) {
    getFront(data);
    return dequeue();
}

template <typename T>
inline bool Queue<T>::getFront(T &data) const {
    if (isEmpty())
        return false;
    data = start->data;
    return true;
}

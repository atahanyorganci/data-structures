#pragma once

#include "common/Node.h"

#include <ostream>

template <typename T>
class LinkedList {
  private:
    Node<T> *head;
    int size;

  public:
    LinkedList();
    LinkedList(const LinkedList<T> &list);
    LinkedList<T> &operator=(const LinkedList<T> &list);
    ~LinkedList();
    bool isEmpty() const;
    int getLength() const;
    bool insert(int index, T data);
    bool remove(int index);
    bool getItem(int index, T &data) const;

    template <typename U>
    friend std::ostream &operator<<(std::ostream &out,
                                    const LinkedList<U> &list);

  private:
    void copy(const LinkedList<T> &list);
};

template <typename T>
inline LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T> &list) {
    // if list is empty bail
    if (list.size == 0)
        return;

    // list at least one element
    head = new Node<T>();
    head->data = list.head->data;

    Node<T> *current = head;
    Node<T> *other = list.head;
    while (other->next) {
        other = other->next;
        current->next = new Node<T>(other->data);
        current = current->next;
        size++;
    }
}

template <typename T>
inline LinkedList<T>::LinkedList(const LinkedList<T> &list)
    : head(nullptr), size(0) {
    copy(list);
}

template <typename T>
inline LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &list) {
    if (this != &list)
        return *this;
    while (!isEmpty())
        remove(0);
    copy(list);
    return *this;
}

template <typename T>
inline LinkedList<T>::~LinkedList() {
    while (!isEmpty())
        remove(0);
}

template <typename T>
inline bool LinkedList<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
inline int LinkedList<T>::getLength() const {
    return size;
}

template <typename T>
inline bool LinkedList<T>::insert(int index, T data) {
    if (index < 0 || index > size)
        return false;

    auto node = new Node<T>(data);
    size++;

    if (index != 0) {
        auto current = head;
        Node<T> *previous = nullptr;
        for (int i = 0; i < index; i++) {
            previous = current;
            current = current->next;
        }
        previous->next = node;
        node->next = current;
    } else {
        node->next = head;
        head = node;
    }
    return true;
}

template <typename T>
inline bool LinkedList<T>::remove(int index) {
    if (index < 0 || index >= size)
        return false;

    if (index != 0) {
        auto current = head;
        Node<T> *previous;
        for (int i = 0; i < index; i++) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        delete current;
    } else {
        auto temp = head;
        if (head != nullptr)
            head = head->next;
        delete temp;
    }
    size--;
    return true;
}

template <typename T>
inline bool LinkedList<T>::getItem(int index, T &data) const {
    if (index < 0 || index >= size)
        return false;

    auto current = head;
    for (int i = 0; i < index; i++)
        current = current->next;
    data = current->data;
    return true;
}

template <typename T>
inline std::ostream &operator<<(std::ostream &out, const LinkedList<T> &list) {
    out << "LinkedList(data=[";
    if (!list.isEmpty()) {
        auto i = list.head;
        while (i->next != nullptr) {
            out << i->data << ", ";
            i = i->next;
        }
        out << i->data;
    }
    out << "], size=" << list.size << ")";
    return out;
}

#pragma once

#include "DoubleNode.h"
#include <iostream>
#include <ostream>

template <typename T> class DoublyLinkedList {
  private:
    DoubleNode<T> *head;
    int size;

  public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<T> &list);
    DoublyLinkedList<T> &operator=(const DoublyLinkedList<T> &list);
    ~DoublyLinkedList();
    bool isEmpty() const;
    int getLength() const;
    bool insert(int index, T data);
    bool remove(int index);
    bool getItem(int index, T &data) const;

    template <typename U>
    friend std::ostream &operator<<(std::ostream &out,
                                    const DoublyLinkedList<U> &list);

  private:
    int translate(int index) const;
};

template <typename T>
inline DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), size(0) {}

template <typename T>
inline DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &list)
    : head(nullptr), size(0) {
    auto current = list.head;
    auto length = list.getLength();
    for (int i = 1; i <= length; i++) {
        insert(i, current->data);
        current = current->next;
    }
}

template <typename T>
inline DoublyLinkedList<T> &
DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &list) {
    if (this == &list)
        return *this;
    while (!isEmpty())
        remove(1);
    auto current = list.head;
    for (int i = 1; i <= list.getLength(); i++) {
        insert(i, current->data);
        current = current->next;
    }
    return *this;
}

template <typename T> inline DoublyLinkedList<T>::~DoublyLinkedList() {
    while (!isEmpty())
        remove(1);
}

template <typename T> inline bool DoublyLinkedList<T>::isEmpty() const {
    return size == 0;
}

template <typename T> inline int DoublyLinkedList<T>::getLength() const {
    return size;
}

template <typename T>
inline bool DoublyLinkedList<T>::insert(int index, T data) {
    index = translate(index);
    if (index < 0 || index > size)
        return false;

    auto temp = new DoubleNode<T>(data);
    if (index == 0) {
        if (!isEmpty())
            head->prev = temp;
        temp->next = head;
        head = temp;
    } else {
        auto current = head;
        for (int i = 0; i < index - 1; i++)
            current = current->next;
        temp->prev = current;
        temp->next = current->next;
        current->next = temp;
        if (current->next)
            current->next->prev = current;
    }
    size++;
    return true;
}

template <typename T> inline bool DoublyLinkedList<T>::remove(int index) {
    index = translate(index);
    if (index < 0 || index >= size)
        return false;

    size--;
    if (index == 0) {
        auto current = head;
        if (!isEmpty())
            head = head->next;
        else
            head = nullptr;
        delete current;
    } else {
        auto current = head;
        for (int i = 0; i < index; i++)
            current = current->next;
        current->prev->next = current->next;
        if (current->next)
            current->next->prev = current->prev;
        delete current;
    }
    return true;
}

template <typename T>
inline bool DoublyLinkedList<T>::getItem(int index, T &data) const {
    index = translate(index);
    if (index < 0 || index >= size)
        return false;

    auto current = head;
    for (int i = 0; i < index; i++)
        current = current->next;
    data = current->data;
    return true;
}

template <typename T>
inline std::ostream &operator<<(std::ostream &out,
                                const DoublyLinkedList<T> &list) {
    out << "DoublyLinkedList(data=[";
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

template <typename T> int DoublyLinkedList<T>::translate(int index) const {
    return index - 1;
}

#pragma once

#include "Node.h"
#include <ostream>

template <typename T> class LinkedList {
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
    int translate(int index) const;
};

template <typename T>
inline LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

template <typename T>
inline LinkedList<T>::LinkedList(const LinkedList<T> &list)
    : head(nullptr), size(0) {
    auto current = list.head;
    auto length = list.getLength();
    for (int i = 1; i <= length; i++) {
        insert(i, current->data);
        current = current->next;
    }
}

template <typename T>
inline LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &list) {
    if (this != &list)
        return *this;
    while (!isEmpty())
        remove(1);
    for (int i = 1; i <= list.getLength(); i++) {
        T item;
        list.getItem(i, item);
        insert(i, item);
    }
    return *this;
}

template <typename T> inline LinkedList<T>::~LinkedList() {
    while (!isEmpty())
        remove(1);
}

template <typename T> inline bool LinkedList<T>::isEmpty() const {
    return size == 0;
}

template <typename T> inline int LinkedList<T>::getLength() const {
    return size;
}

template <typename T> inline bool LinkedList<T>::insert(int index, T data) {
    index = translate(index);
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

template <typename T> inline bool LinkedList<T>::remove(int index) {
    index = translate(index);
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

template <typename T> int LinkedList<T>::translate(int index) const {
    return index - 1;
}

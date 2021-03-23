#pragma once

template <typename T>
class DoubleNode {
  public:
    DoubleNode();
    DoubleNode(const T &data);
    DoubleNode<T> *next;
    DoubleNode<T> *prev;
    T data;
};

template <typename T>
inline DoubleNode<T>::DoubleNode() : next(nullptr), prev(nullptr) {}

template <typename T>
inline DoubleNode<T>::DoubleNode(const T &data)
    : next(nullptr), prev(nullptr), data(data) {}

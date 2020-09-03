#pragma once

template <typename T>
class Node
{
public:
    Node();
    Node(const T &data);
    Node<T> *next;
    T data;
};

template <typename T>
inline Node<T>::Node() : next(nullptr)
{
}

template <typename T>
inline Node<T>::Node(const T &data) : next(nullptr), data(data)
{
}

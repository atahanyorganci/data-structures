#pragma once

#include <ostream>

const int DEFAULT_SIZE = 20;
template <typename T>
class List
{
private:
    T *data;
    int size;
    int count;

public:
    List(int size = DEFAULT_SIZE);
    List(const List<T> &list);
    ~List();
    bool isEmpty() const;
    int getSize() const;
    int getCount() const;
    bool getItem(int index, T &item) const;
    bool insert(int index, T item);
    bool remove(int index);
    bool resize(int size);
    List<T> &operator=(const List<T> &list);
    template <typename U>
    friend std::ostream &operator<<(std::ostream &out, const List<U> &list);

private:
    int translate(int index) const;
};

template <typename T>
inline List<T> &List<T>::operator=(const List<T> &list)
{
    if (this != &list)
        return *this;
    delete[] data;
    size = list.size;
    count = list.count;
    data = new T[size];
    for (size_t i = 0; i < static_cast<size_t>(count); i++)
        data[i] = list.data[i];
    return *this;
}

template <typename T>
inline List<T>::List(const List<T> &list)
{
    if (this == &list)
        return;
    size = list.size;
    count = list.count;
    data = new T[size];
    for (size_t i = 0; i < static_cast<size_t>(count); i++)
        data[i] = list.data[i];
}

template <typename T>
inline List<T>::List(int size) : size(size), count(0)
{
    data = new T[size];
}

template <typename T>
inline List<T>::~List()
{
    if (size > 0)
        delete[] data;
}

template <typename T>
inline bool List<T>::isEmpty() const
{
    return count == 0;
}

template <typename T>
inline int List<T>::getSize() const
{
    return size;
}

template <typename T>
inline int List<T>::getCount() const
{
    return count;
}

template <typename T>
inline bool List<T>::getItem(int index, T &item) const
{
    index = translate(index);
    if (index < 0 || index >= count)
        return false;
    item = data[index];
    return true;
}

template <typename T>
inline bool List<T>::insert(int index, T item)
{
    index = translate(index);
    if (index < 0 || index > count || count == size)
        return false;
    for (size_t i = static_cast<size_t>(count); i > static_cast<size_t>(index); i--)
        data[i] = data[i - 1];
    data[index] = item;
    count++;
    return true;
}

template <typename T>
inline bool List<T>::remove(int index)
{
    index = translate(index);
    if (index < 0 || index > count || count == 0)
        return false;
    count--;
    for (size_t i = 0; i < static_cast<size_t>(count); i++)
    {
        if (i < static_cast<size_t>(index))
            continue;
        else
            data[i] = data[i + 1];
    }
    return true;
}

template <typename T>
inline bool List<T>::resize(int newSize)
{
    if (newSize < 0 || newSize < count)
        return false;
    auto temp = new T[newSize];
    for (size_t i = 0; i < static_cast<size_t>(count); i++)
        temp[i] = data[i];
    delete[] data;
    size = newSize;
    data = temp;
    return true;
}

template <typename T>
inline int List<T>::translate(int index) const
{
    return index - 1;
}

template <typename T>
inline std::ostream &operator<<(std::ostream &out, const List<T> &list)
{
    out << "List(data=[";
    auto count = static_cast<size_t>(list.count) - 1;
    for (size_t i = 0; i < count; i++)
        out << list.data[i] << ", ";
    out << list.data[count] << "], count=" << list.count;
    out << ", size=" << list.size << ")";
    return out;
}
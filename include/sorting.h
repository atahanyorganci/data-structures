#pragma once

#include <stddef.h>

template <typename T>
void swap(T &a, T &b) {
    const T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void selection_sort(T *arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        T least = i;
        for (size_t j = i + 1; j < size; j++) {
            if (arr[least] > arr[j])
                least = j;
        }
        swap(arr[i], arr[least]);
    }
}

template <typename T>
void bubble_sort(T *arr, const size_t size) {
    if (size == 0 || size == 1)
        return;

    bool sorted = false;
    size_t pass = 1;
    while (!sorted && size > pass) {
        sorted = true;
        for (size_t i = 0; i < size - pass; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }
    }
}

template <typename T>
void insertion_sort(T *arr, const size_t size) {
    for (size_t i = 1; i < size; i++) {
        const T to_insert = arr[i];
        for (int j = i; j >= 1; j--) {
            if (arr[j - 1] > to_insert)
                swap(arr[j - 1], arr[j]);
            else
                break;
        }
    }
}

template <typename T>
void merge(T *arr, const size_t size, size_t split, T *temp) {
    size_t index = 0;
    size_t first = 0;
    size_t second = split;

    while (first < split && second < size) {
        if (arr[first] < arr[second]) {
            temp[index] = arr[first];
            first++;
        } else {
            temp[index] = arr[second];
            second++;
        }
        index++;
    }

    while (first < split) {
        temp[index] = arr[first];
        index++;
        first++;
    }

    while (second < size) {
        temp[index] = arr[second];
        index++;
        second++;
    }

    for (size_t i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

template <typename T>
void inner_merge_sort(T *arr, const size_t size, T *temp) {
    if (size < 2)
        return;

    const size_t length = size;
    const size_t split = size / 2;
    inner_merge_sort(arr, split, temp);
    inner_merge_sort(&arr[split], length - split, temp);
    merge(arr, size, split, temp);
}

template <typename T>
void merge_sort(T *arr, int size) {
    auto temp = new T[size];
    inner_merge_sort(arr, size, temp);
    delete[] temp;
}

template <typename T>
size_t partition(int *arr, const size_t size, const T &pivot) {
    size_t first_s2 = 1;
    for (size_t unknown = 1; unknown < size; unknown++) {
        if (arr[unknown] < pivot) {
            swap(arr[first_s2], arr[unknown]);
            first_s2++;
        }
    }
    return first_s2 - 1;
}

template <typename T>
void quick_sort(T *arr, const size_t size) {
    if (size == 1 || size == 0)
        return;
    const T pivot = arr[0];

    size_t pivot_index = partition(arr, size, pivot);
    arr[0] = arr[pivot_index];
    arr[pivot_index] = pivot;

    quick_sort(arr, pivot_index);
    quick_sort(&arr[pivot_index + 1], size - pivot_index - 1);
}

template <typename T>
void create_bins(const T radix, const size_t size, T **&bins, size_t *&counts) {
    if (radix < 2) {
        bins = nullptr;
        counts = nullptr;
        return;
    }

    const size_t uradix = static_cast<size_t>(radix);
    counts = new size_t[uradix];
    bins = new T *[uradix];
    for (size_t i = 0; i < uradix; i++) {
        bins[i] = new T[size];
        counts[i] = 0;
    }
}

template <typename T>
void delete_bins(const T radix, T **&bins, size_t *&counts) {
    const size_t uradix = static_cast<size_t>(radix);
    for (size_t i = 0; i < uradix; i++) {
        delete[] bins[i];
    }
    delete[] counts;
    delete[] bins;

    bins = NULL;
    counts = NULL;
}

template <typename T>
void radix_sort(T *arr, const size_t size, const T radix) {
    int power = 1;
    T **bins = nullptr;
    size_t *counts = nullptr;
    create_bins(radix, size, bins, counts);

    bool sorted = false;
    while (!sorted) {
        const T curr_power = static_cast<T>(pow(radix, power));
        const T prev_power = static_cast<T>(pow(radix, power - 1));
        for (size_t i = 0; i < static_cast<size_t>(size); i++) {
            const size_t rem =
                static_cast<size_t>((arr[i] % curr_power) / prev_power);
            const size_t count = counts[rem];
            bins[rem][count] = arr[i];
            counts[rem]++;
        }

        size_t index = 0;
        sorted = true;

        for (size_t i = 0; i < static_cast<size_t>(radix); i++) {
            const size_t count = static_cast<size_t>(counts[i]);
            for (size_t j = 0; j < count; j++) {
                arr[index] = bins[i][j];
                if (index != 0 && arr[index - 1] > arr[index])
                    sorted = false;
                index++;
            }
            counts[i] = 0;
        }
        power++;
    }

    delete_bins(radix, bins, counts);
}

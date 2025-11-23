#pragma once
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct IntVector {
    /* ... */

    int& operator[](size_t pos) {
        return data_[pos];
    }

    size_t size() const {
        return size_;
    }

    IntVector& operator=(const IntVector& other) {
        if (this == &other)
            return *this;
        this->~IntVector();
        new(this) IntVector(other);
        return *this;
    }

    IntVector& operator=(IntVector&& other) noexcept{
        if (this == &other)
            return *this;
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        other.data_ = nullptr;
        return *this;
    }

    IntVector(const IntVector& other)
    : IntVector(other.data_, other.size_) {
    }

    IntVector(IntVector&& other) noexcept
        : data_(other.data_), size_(other.size_) {
        other.data_ = nullptr;
    }

    explicit IntVector(size_t size)
    : data_(new int[size]), size_(size) { }

    IntVector(initializer_list<int> arr)
    : data_(new int[arr.size()]), size_(arr.size()) {
        int i = 0;
        for (auto& elem : arr)
            data_[i++] = elem;
    }

    IntVector(int* p, size_t size)
        : data_(new int[size]), size_(size) {
        for (int i = 0; i < size; i++)
            data_[i] = p[i];
    }

    ~IntVector() {
        delete[] data_;
    }

private:
    int* data_ = nullptr;
    size_t size_ = 0;
};

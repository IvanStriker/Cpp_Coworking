#pragma once

struct IntUnique {
    IntUnique() = default;
    IntUnique(const IntUnique &) = delete;
    IntUnique &operator=(const IntUnique &) = delete;

    IntUnique(IntUnique && other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }

    IntUnique& operator=(IntUnique && other) noexcept {
        if (this == &other)
            return *this;
        delete ptr_;
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
        return *this;
    }

    IntUnique(int* ptr) : ptr_(ptr) {}

    ~IntUnique() {
        delete ptr_;
    }

    int* get() {
        return ptr_;
    }

    const int* get() const {
        return ptr_;
    }

    void reset(int* ptr = nullptr) {
        delete ptr_;
        if (ptr)
            ptr_ = ptr;
    }
    
    int* release() {
        int* tempPtr = ptr_;
        ptr_ = nullptr;
        return tempPtr;
    }

    int& operator*() {
        return *ptr_;
    }

    const int& operator*() const {
        return *ptr_;
    }

private:
    int* ptr_ = nullptr;
};

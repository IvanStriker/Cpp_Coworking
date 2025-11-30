#pragma once

struct SharedPtr {
    SharedPtr() = default;
    SharedPtr(SharedPtr&&) noexcept = default;
    SharedPtr& operator=(SharedPtr&& other) noexcept = default;

    SharedPtr(int* ptr) : ptr_(ptr), amount(new int(1)) {}

    SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), amount(other.amount) {
        *amount += 1;
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (this == &other)
            return *this;
        *amount -= 1;
        this->~SharedPtr();
        ptr_ = other.ptr_;
        amount = other.amount;
        *amount += 1;
        return *this;
    }

    ~SharedPtr() {
        if (!amount) {
            delete ptr_;
            delete amount;
        }
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

    int& operator*() {
        return *ptr_;
    }

    const int& operator*() const {
        return *ptr_;
    }

private:
    int* ptr_ = nullptr;
    int* amount = nullptr;
};

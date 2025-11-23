#pragma once

struct Shared {
    Shared() = default;
    Shared(Shared&&) noexcept = default;
    Shared& operator=(Shared&& other) noexcept = default;

    Shared(int* ptr) : ptr_(ptr), amount(new int(1)) {}

    Shared(const Shared& other) : ptr_(other.ptr_), amount(other.amount) {
        *amount += 1;
    }

    Shared& operator=(const Shared& other) {
        if (this == &other)
            return *this;
        *amount -= 1;
        this->~Shared();
        ptr_ = other.ptr_;
        amount = other.amount;
        *amount += 1;
        return *this;
    }

    ~Shared() {
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

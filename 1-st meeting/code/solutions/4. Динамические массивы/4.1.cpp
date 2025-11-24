#include <iostream>
#include <algorithm>

int* myAllocate(size_t n) {
    return new int[n]{};
}

void myFree(int* ptr) {
    delete [] ptr;
}

int* myCopyingRealloc(int* p, size_t prev_size, size_t new_size) {
    if (new_size < prev_size)
        throw std::invalid_argument("myCopyingRealloc: can't copy to an area with smaller size.");
    int* newPtr = myAllocate(new_size);
    std::copy_n(p, prev_size, newPtr);
    myFree(p);
    return newPtr;
}

void myPushBack(int*& p, size_t size, int elem) {
    p = myCopyingRealloc(p, size, size + 1);
    p[size] = elem;
}

int main() {

    return 0;
}

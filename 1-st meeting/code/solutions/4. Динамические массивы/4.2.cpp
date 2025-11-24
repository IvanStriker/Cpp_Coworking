#include <algorithm>
#include <iostream>

int* myAllocate(size_t n) {
    return new int[n]{};
}

void myFree(int* ptr) {
    delete [] ptr;
}

size_t countDistinct(const int* p, size_t size) {
    int* copyPtr = myAllocate(size);
    std::copy_n(p, size, copyPtr);
    std::sort(copyPtr, copyPtr + size);
    size_t cnt = size > 0;
    for (int i = 1; i < size; ++i) {
        cnt += copyPtr[i] != copyPtr[i - 1];
    }
    myFree(copyPtr);
    return cnt;
}

int main() {
    int arr[] = {1, 4, 4, 5, 12, 8, 8, 4, 6};
    std::cout << countDistinct(arr, std::size(arr)) << '\n';
    // 6
    return 0;
}

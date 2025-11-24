#include <iostream>

void swap(int& a, int& b) {
    int tempA = a;
    a = b;
    b = tempA;
}

void swap(int*& a, int*& b) {
    int* tempA = a;
    a = b;
    b = tempA;
}

void swapPtr(int* a, int* b) {
    int tempA = *a;
    *a = *b;
    *b = tempA;
}

void swapPtr(int** a, int** b) {
    int* tempA = *a;
    *a = *b;
    *b = tempA;
}

int main() {
    int a = 12;
    int b = 34;
    swap(a, b);
    // a == 34, b == 12
    swapPtr(&a, &b);
    // a == 12, b == 34
    int* p = &a;
    int* q = &b;
    swap(p, q);
    // p == &b, q == &a
    swapPtr(&p, &q);
    // p == &a, q == &b
    return 0;
}

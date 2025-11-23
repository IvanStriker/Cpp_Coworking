#include <iostream>
#include <algorithm>

#include "int_vector.hpp"

using namespace std;

IntVector sort(IntVector arr1, IntVector arr2) {
    std::sort(&arr1[0], &arr1[arr1.size() - 1] + 1);
    std::sort(&arr2[0], &arr2[arr2.size() - 1] + 1);
    IntVector arr3(arr1.size() + arr2.size());
    int* arr1back = &arr1[arr1.size() - 1];
    int* arr2back = &arr2[arr2.size() - 1];
    int* p = &arr1[0];
    int* q = &arr2[0];
    size_t i = 0;
    while (true) {
        if (p > arr1back && q > arr2back)
            break;
        if (p <= arr1back && (*p < *q || q > arr2back))
            arr3[i++] = *p++;
        else
            arr3[i++] = *q++;
    }
    return (IntVector&&)arr3;
}

int main() {
    IntVector arr4 = {5, 6, 3, 8};
    IntVector arr5 = {1, 4, 2, 9};
    IntVector arr6 = (IntVector&&)sort(arr4, arr5);
    for (int i = 0; i < 8; ++i) {
        cout << arr6[i] << '\n';
    }
    return 0;
}

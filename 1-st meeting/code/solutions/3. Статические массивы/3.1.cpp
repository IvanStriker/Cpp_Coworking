#include <iostream>

size_t countDistinct(const int* p, size_t size) {
    size_t cnt = 0;
    for (int i = 0; i < size; ++i) {
        bool distinct = 1;
        for (int j = 0; j < i; ++j)
            if (p[i] == p[j]) {
                distinct = 0;
                break;
            }
        cnt += distinct;
    }
    return cnt;
}


int main() {
    int arr[] = {1, 4, 4, 5, 12, 8, 8, 4, 6};
    std::cout << countDistinct(arr, std::size(arr)) << '\n';
    // 6
    return 0;
}

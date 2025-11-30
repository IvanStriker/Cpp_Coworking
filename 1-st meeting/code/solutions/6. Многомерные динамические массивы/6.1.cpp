#include <iostream>
#include <vector>

int** createArray(size_t rows, size_t cols) {
    int* arr = new int[rows * cols] {};
    int** table = new int*[rows];
    for (size_t i = 0; i < rows; i++) {
        table[i] = arr + i * cols;
    }
    return table;
}

void freeArray(int** ptr) {
    delete[] ptr[0];
    delete[] ptr;
}

std::vector<int> linearTransform(int** matrix, size_t rows,
                                 size_t cols, int* vec) {
    std::vector<int> res(rows, 0);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            res[i] += matrix[i][j] * vec[j];
    return res;
}

int main() {
    int** arr = createArray(3, 3);
    for (size_t i = 0; i < 9; ++i) {
        arr[0][i] = i + 1;
    }
    int vec[] = {1, 2, 3};
    auto res = linearTransform(arr, 3, 3, vec);
    for (size_t i = 0; i < 3; i++)
        std::cout << res[i] << '\n';
    freeArray(arr);
    return 0;
}

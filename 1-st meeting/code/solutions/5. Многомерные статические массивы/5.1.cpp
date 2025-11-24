#include <iostream>

bool multiply(int* l, size_t l_rows, size_t l_cols,
              int* r, size_t r_rows, size_t r_cols,
              int* res) {
    if (l_cols != r_rows)
        return false;
    for (size_t row = 0; row < l_rows; ++row)
        for (size_t col = 0; col < r_cols; ++col) {
            res[row*r_cols + col] = 0;
            for (size_t elem = 0; elem < l_cols; ++elem)
                res[row*r_cols + col] += l[row*l_cols + elem] * r[elem*r_cols + col];
        }
    return true;
}

int main() {
    int a[2][2] {
        {1, 2},
        {3, 4}
    };
    int b[2][3] {
        {1, 2, 3},
        {4, 5, 6}
    };
    int c[2][3] {};
    multiply((int*)b, std::size(a), std::size(a[0]),
                   (int*)b, std::size(b), std::size(b[0]),
                   (int*)c);
    for (auto& row : c) {
        for (auto elem : row) {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }
    // 9 12 15
    // 19 26 33
    return 0;
}

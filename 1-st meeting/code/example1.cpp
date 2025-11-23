#include <iostream>
#include <numeric>
#include <algorithm>
#include "int_vector.hpp"
using namespace std;

// Среднее значение наименьших 5-и значений
double myMetric1(const IntVector& inputArr) {
    cout << "const IntArray&\n";
    IntVector arr(inputArr);
    std::sort(&arr[0], &arr[arr.size() - 1] + 1);
    int amountToSum = min(&arr[arr.size() - 1] + 1, &arr[0] + 5) - &arr[0];
    double sum = std::accumulate(
        &arr[0],
        &arr[0] + amountToSum,
        0.0
    );
    return sum / amountToSum;
}

// double myMetric1(IntVector&& arr) {
//     cout << "IntArray&&\n";
//     std::sort(&arr[0], &arr[arr.size() - 1] + 1);
//     int amountToSum = min(&arr[arr.size() - 1] + 1, &arr[0] + 5) - &arr[0];
//     double sum = std::accumulate(
//         &arr[0],
//         &arr[0] + amountToSum,
//         0.0
//     );
//     return sum / amountToSum;
// }

int main3() {
    IntVector arr = {6, 5, 4, 3, 2, 1};
    cout << myMetric1(arr) << '\n';
    //cout << myMetric1((IntVector&&)arr) << '\n';
    return 0;
}

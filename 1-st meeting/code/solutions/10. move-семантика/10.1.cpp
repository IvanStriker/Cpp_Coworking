#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>

double standardDeviation(const std::vector<double>& lst) {
    double mean = std::ranges::fold_left(lst, 0.0, std::plus{}) / lst.size();
    double std = std::sqrt(std::transform_reduce(
        lst.begin(),
        lst.end(),
        0.0,
        std::plus{},
        [&mean](const double& val) {
            return std::pow((mean - val), 2);
        }));
    return std;
}

int main() {
    std::cout << standardDeviation({1, 2, 3, 4, 5}) << '\n';
    return 0;
}

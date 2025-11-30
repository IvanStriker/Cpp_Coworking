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

double median(std::vector<double>&& lst) {
    std::cout << "r-value: no copying...\n";
    std::ranges::sort(lst);
    if (lst.size() % 2 == 1)
        return lst[lst.size() / 2];
    return (lst[lst.size() / 2] + lst[lst.size() / 2 - 1]) / 2;
}

double median(const std::vector<double>& lst) {
    std::cout << "l-value: copying...\n";
    std::vector<double> copy(lst);
    std::ranges::sort(copy);
    if (copy.size() % 2 == 1)
        return copy[copy.size() / 2];
    return (copy[copy.size() / 2] + copy[copy.size() / 2 - 1]) / 2;
}

int main() {
    std::vector<double> lst = {5, 4, 2, 3, 1, 6};
    std::cout << median(lst) << '\n';
    std::cout << median((std::vector<double>&&)lst) << '\n';
    return 0;
}

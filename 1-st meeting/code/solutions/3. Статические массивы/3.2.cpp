#include <iostream>
#include <algorithm>

int* biggestPrime(int* p, int* q) {
    int sieve[1000] = {1, 1};
    for (int i = 2; i*i < 1000; ++i) {
        if (sieve[i])
            continue;
        for (int j = i*2; j < 1000; j += i)
            sieve[j] = 1;
    }
    return std::max_element(p, q, [sieve](auto l, auto r) {
        bool primeL = !sieve[l];
        bool primeR = !sieve[r];
        return std::min(l + primeL*1000, r + primeR*1000) == l + primeL*1000;
    });
}



int main() {
    std::array arr = {1, 4, 4, 5, 12, 8, 8, 4, 6, 29};
    std::cout << *biggestPrime(&arr.front(), &arr.back()) << '\n';
    // 29
    return 0;
}

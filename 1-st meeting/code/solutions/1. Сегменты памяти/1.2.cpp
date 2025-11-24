#include <iostream>

int main() {
    int a = 65535;
    double b = 266589;
    char c = 12;
    std::cout << "b - a = " << (char*)&a - (char*)&b << '\n';
    std::cout << "b - c = " << (char*)&b - &c << '\n';

    //std::cout << a << ' ' << b << ' ' << c << '\n';
    return 0;
}

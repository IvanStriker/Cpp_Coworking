#include <iostream>

int main() {
    int a = 65535;
    char* p = (char*)&a;
    std::cout << "Первый байт" << (int)*p << '\n';
    std::cout << "Второй байт" << (int)p[1] << '\n';
    std::cout << "Третий байт" << (int)p[2] << '\n';
    std::cout << "Четвёртый байт" << (int)p[3] << '\n';
    return 0;
}

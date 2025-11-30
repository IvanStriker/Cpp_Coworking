#include <iostream>
#include <vector>
#include <string>

class User {
    int id_; // 1 блок по 8 байт

    std::string firstName_ = "Ivan"; // 4 блока по 8 байт
    std::string lastName_ = "Vinogradov"; // 4 блока по 8 байт

    std::vector<int> friends_ = {1, 2, 3}; // 3 блока по 8 байт
    std::vector<int> subscriptions_ = {4, 5, 6}; // 3 блока по 8 байт

    std::string login_ = "login@gmail.com"; // 4 блока по 8 байт
    std::string password_ = "!Hello!"; // 4 блока по 8 байт

    // (1 + 4 + 4 + 3 + 3 + 4)*8 = 152 - кол-во байтов перед полем password_
    /* ... */
};

User admin;

#define print(a) std::cout << #a << ": " << a << '\n';
#define printNV(name, val) std::cout << #name << ": " << val << '\n';

int main() {
    // Исследование User...
    // С помощью указателей получим достук к полю password_
    print(sizeof(User));
    print(alignof(User));
    print(alignof(std::string))
    print(sizeof(std::string))
    print(alignof(std::vector<int>))
    print(sizeof(std::vector<int>))
    
    User* p = &admin;
    printNV(password_, *(std::string*)((char*)p + 152));
    return 0;
}

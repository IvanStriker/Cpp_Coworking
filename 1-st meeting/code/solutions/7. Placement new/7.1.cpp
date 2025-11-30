#include <iostream>
#include <string>

void assign(std::string& str, size_t size, char val) {
    using std::string;
    str.~string();
    new(&str) string(size, val);
}

int main() {
    std::string str = "Easiest programming language:)";
    assign(str, 10, ')');
    std::cout << str << '\n';
    // ))))))))))
    return 0;
}

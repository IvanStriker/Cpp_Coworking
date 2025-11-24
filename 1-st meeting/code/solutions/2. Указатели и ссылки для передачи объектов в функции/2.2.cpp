#include <iostream>
#include <utility>
// #include <algorithm>

void sortString(std::string& str) {
    // std::ranges::sort(str);
    for (int i = 0; i < str.size() - 1; ++i) {
        for (int j = 0; j < str.size() - 1 - i; ++j)
            if (str[j] > str[j + 1])
                std::swap(str[j], str[j + 1]);
        std::cout << str << '\n';
    }
}


int main() {
    std::string s = "ACEDBFG";
    sortString(s);
    std::cout << s << '\n';
    // ABCDEFG
    return 0;
}

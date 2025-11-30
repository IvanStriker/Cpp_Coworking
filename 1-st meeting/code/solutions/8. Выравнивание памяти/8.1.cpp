#include <iostream>

struct Neuron {
    short w1     = 1;
    long long w2 = 2;
    int w3       = 3;
    double bias  = 4;
    void* activator_function = nullptr;
};

#define print(a) std::cout << #a << ": " << a << '\n';
#define printNV(name, val) std::cout << #name << ": " << val << '\n';

int main() {
    // Исследование Neuron...
    // С помощью указателей получим достук ко всем полям
    print(sizeof(Neuron));
    print(alignof(Neuron));
    Neuron n;
    Neuron* p = &n;
    printNV(w1, *(short*)p);
    printNV(w2, *(long long*)((char*)p + 8));
    printNV(w3, *(int*)((char*)p + 16));
    printNV(w4, *(double*)((char*)p + 24));
    printNV(activator_function, *(double*)((char*)p + 32));
    return 0;
}

#include <iostream>
#include <string>
#include <cassert>
template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
void testMySwap() {
    int a = 10, b = 20;
    mySwap(a, b);
    assert(a == 20 && b == 10);
    double c = 1.5, d = 2.5;
    mySwap(c, d);
    assert(c == 2.5 && d == 1.5);
    std::string e = "hello", f = "world";
    mySwap(e, f);
    assert(e == "world" && f == "hello");
}
int main() {
    testMySwap();
    std::cout << "All tests passed!" << std::endl;
}

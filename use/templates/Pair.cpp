#include <iostream>
#include <string>

template <typename T1, typename T2>
class Pair {
private:
    T1 a;
    T2 b;
public:
    Pair() : a{}, b{} {};
    Pair(T1 _a, T2 _b) : a(_a), b(_b) {};
    void print() {
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }
};

void testPair() {
    Pair<double, std::string> p1(123.4567, "text example");
    p1.print();
    Pair<int, double> p2(10, 5.5);
    p2.print();
}

int main() {
    testPair();
    std::cout << "All tests passed!" << std::endl;
}

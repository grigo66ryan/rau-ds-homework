#include <iostream>
#include <string>

template <typename T>
void printElement(T value) {
    std::cout << value;
}

void testPrintElement() {
    printElement(10);
    std::cout << std::endl;
    printElement(12.5);
    std::cout << std::endl;
    printElement(std::string("hello"));
    std::cout << std::endl;
}

int main() {
    testPrintElement();
    std::cout << "All tests passed!" << std::endl;
}

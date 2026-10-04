#include <iostream>
#include <string>

template <typename T>
void printValue(T value) {
    std::cout << value << std::endl;
}

template <>
void printValue<bool>(bool value) {
    if (value) std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
}

template <>
void printValue<char*>(char* value) {
    std::cout << '"' << value << '"' << std::endl;
}

void testPrintValue() {
    printValue(10);
    printValue(true);
    printValue(false);
    char text[] = "hello";
    printValue(text);
}

int main() {
    testPrintValue();
    std::cout << "All tests passed!" << std::endl;
}

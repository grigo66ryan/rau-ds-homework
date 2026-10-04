#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
template <typename T>
bool isEqual(T a, T b) {
    return a == b;
}
template <>
bool isEqual<const char*>(const char* a, const char* b) {
    return !(std::strcmp(a, b));
}
void testIsEqual() {
    assert(isEqual(10, 10));
    assert(!isEqual(10, 20));
    assert(isEqual(2.5, 2.5));
    assert(!isEqual(2.5, 3.5));
    std::string s1 = "hello";
    std::string s2 = "hello";
    std::string s3 = "world";
    assert(isEqual(s1, s2));
    assert(!isEqual(s1, s3));
    const char a[] = "hello";
    const char b[] = "hello";
    const char c[] = "world";
    assert(isEqual(a, b));
    assert(!isEqual(a, c));
}
int main() {
    testIsEqual();
    std::cout << "All tests passed!" << std::endl;
}

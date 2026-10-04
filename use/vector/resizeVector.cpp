#include <iostream>
#include <vector>
#include <string>
#include <cassert>

template <typename T>
void resizeVector(std::vector<T>& vec, int newSize, T defaultValue) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i != vec.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    vec.resize(newSize, defaultValue);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i != vec.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
}

void testResizeVector() {
    std::vector<int> vec1 = { 1,2,3 };
    resizeVector(vec1, 5, 42);
    std::vector<int> expected1 = { 1,2,3,42,42 };
    assert(vec1 == expected1);

    std::vector<int> vec2 = { 1,2,3,4,5 };
    resizeVector(vec2, 2, 0);
    std::vector<int> expected2 = { 1,2 };
    assert(vec2 == expected2);

    std::vector<int> vec3 = { 7,8,9 };
    resizeVector(vec3, 3, 100);
    std::vector<int> expected3 = { 7,8,9 };
    assert(vec3 == expected3);

    std::vector<std::string> vec4 = { "a" };
    resizeVector(vec4, 3, std::string("x"));
    std::vector<std::string> expected4 = { "a","x","x" };
    assert(vec4 == expected4);
}

int main() {
    testResizeVector();
    std::cout << "All tests passed!" << std::endl;
}

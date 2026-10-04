#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
std::vector<T> filterVector(const std::vector<T>& vec, bool (*predicate)(T)) {
    std::vector<T> result;
    for (int i = 0; i < vec.size(); i++) {
        if (predicate(vec[i])) {
            result.push_back(vec[i]);
        }
    }
    return result;
}

bool isEven(int x) {
    return x % 2 == 0;
}

bool isPositive(int x) {
    return x > 0;
}

void testFilterVector() {
    std::vector<int> vec1 = { 1,2,3,4,5,6 };
    std::vector<int> expected1 = { 2,4,6 };
    assert(filterVector(vec1, isEven) == expected1);

    std::vector<int> vec2 = { 1,3,5 };
    assert(filterVector(vec2, isEven).empty());

    std::vector<int> vec3;
    assert(filterVector(vec3, isEven).empty());

    std::vector<int> vec4 = { -3,0,2,5,-1 };
    std::vector<int> expected4 = { 2,5 };
    assert(filterVector(vec4, isPositive) == expected4);
}

int main() {
    testFilterVector();
    std::cout << "All tests passed!" << std::endl;
}

#include <iostream>
#include <vector>
#include <cassert>

int removeElementsGreaterThan(std::vector<int>& vec, int n) {
    int removed = 0;
    while (!vec.empty() && vec.back() > n) {
        vec.pop_back();
        removed++;
    }
    return removed;
}

void testRemoveElementsGreaterThan() {
    std::vector<int> vec1 = { 1,3,5,7,9 };
    std::vector<int> expected1 = { 1,3,5 };
    assert(removeElementsGreaterThan(vec1, 5) == 2);
    assert(vec1 == expected1);

    std::vector<int> vec2 = { 1,2,3 };
    std::vector<int> expected2 = { 1,2,3 };
    assert(removeElementsGreaterThan(vec2, 5) == 0);
    assert(vec2 == expected2);

    std::vector<int> vec3 = { 6,7,8 };
    assert(removeElementsGreaterThan(vec3, 5) == 3);
    assert(vec3.empty());

    std::vector<int> vec4;
    assert(removeElementsGreaterThan(vec4, 5) == 0);
    assert(vec4.empty());
}

int main() {
    testRemoveElementsGreaterThan();
    std::cout << "All tests passed!" << std::endl;
}

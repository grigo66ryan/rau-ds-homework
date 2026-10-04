#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> mergeSortedVectors(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    std::vector<int> result;
    int i = 0;
    int j = 0;
    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] <= vec2[j]) {
            result.push_back(vec1[i]);
            i++;
        }
        else {
            result.push_back(vec2[j]);
            j++;
        }
    }
    while (i < vec1.size()) {
        result.push_back(vec1[i]);
        i++;
    }
    while (j < vec2.size()) {
        result.push_back(vec2[j]);
        j++;
    }
    return result;
}

void testMergeSortedVectors() {
    std::vector<int> vec1 = { 1,3,5,7 };
    std::vector<int> vec2 = { 2,4,6,8,9 };
    std::vector<int> expected1 = { 1,2,3,4,5,6,7,8,9 };
    assert(mergeSortedVectors(vec1, vec2) == expected1);

    std::vector<int> empty;
    std::vector<int> vec3 = { 1,2,3 };
    assert(mergeSortedVectors(empty, vec3) == vec3);
    assert(mergeSortedVectors(vec3, empty) == vec3);
    assert(mergeSortedVectors(empty, empty).empty());

    std::vector<int> vec4 = { 1,2,2 };
    std::vector<int> vec5 = { 2,2,3 };
    std::vector<int> expected2 = { 1,2,2,2,2,3 };
    assert(mergeSortedVectors(vec4, vec5) == expected2);
}

int main() {
    testMergeSortedVectors();
    std::cout << "All tests passed!" << std::endl;
}

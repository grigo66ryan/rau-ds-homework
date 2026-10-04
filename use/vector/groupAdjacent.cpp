#include <iostream>
#include <vector>
#include <cassert>

std::vector<std::vector<int>> groupAdjacent(const std::vector<int>& vec) {
    std::vector<std::vector<int>> groups;
    if (vec.empty()) return groups;
    std::vector<int> group;
    group.push_back(vec[0]);
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] == vec[i - 1]) {
            group.push_back(vec[i]);
        }
        else {
            groups.push_back(group);
            group.clear();
            group.push_back(vec[i]);
        }
    }
    groups.push_back(group);
    return groups;
}

void testGroupAdjacent() {
    std::vector<int> vec1 = { 1,1,2,2,2,3,1,1 };
    std::vector<std::vector<int>> expected1 = { {1,1}, {2,2,2}, {3}, {1,1} };
    assert(groupAdjacent(vec1) == expected1);

    std::vector<int> vec2;
    assert(groupAdjacent(vec2).empty());

    std::vector<int> vec3 = { 5 };
    std::vector<std::vector<int>> expected3 = { {5} };
    assert(groupAdjacent(vec3) == expected3);

    std::vector<int> vec4 = { 4,4,4,4 };
    std::vector<std::vector<int>> expected4 = { {4,4,4,4} };
    assert(groupAdjacent(vec4) == expected4);

    std::vector<int> vec5 = { 1,2,3 };
    std::vector<std::vector<int>> expected5 = { {1}, {2}, {3} };
    assert(groupAdjacent(vec5) == expected5);
}

int main() {
    testGroupAdjacent();
    std::cout << "All tests passed!" << std::endl;
}

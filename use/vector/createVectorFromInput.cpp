#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> createVectorFromInput() {
    std::vector<int> vec{};
    int input;
    std::cin >> input;
    while (input != 0) {
        vec.push_back(input);
        std::cin >> input;
    }
    return vec;
}

void testCreateVectorFromInput() {
    std::cout << "Enter: 1 2 3 0" << std::endl;
    std::vector<int> result1 = createVectorFromInput();
    std::vector<int> expected1 = { 1,2,3 };
    assert(result1 == expected1);

    std::cout << "Enter: 0" << std::endl;
    std::vector<int> result2 = createVectorFromInput();
    assert(result2.empty());
}

int main() {
    testCreateVectorFromInput();
    std::cout << "All tests passed!" << std::endl;
}

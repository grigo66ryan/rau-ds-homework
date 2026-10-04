#include <iostream>
#include <vector>

void workWithEmptyVector() {
    std::vector<int> vec{};
    for (int i = 1; i <= 10; i++) {
        vec.push_back(i);
        std::cout << "Size: " << vec.size() << std::endl;
        std::cout << "Capacity: " << vec.capacity() << std::endl;
    }
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i != vec.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
}

void testWorkWithEmptyVector() {
    workWithEmptyVector();
}

int main() {
    testWorkWithEmptyVector();
    std::cout << "All tests passed!" << std::endl;
}

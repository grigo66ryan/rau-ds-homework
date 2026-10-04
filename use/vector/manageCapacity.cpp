#include <iostream>
#include <vector>
#include <cassert>

void manageCapacity(std::vector<int>& vec) {
    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;
    vec.reserve(vec.size() + 500);
    for (int i = 1; i <= 500; i++) {
        vec.push_back(i);
    }
    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;
}

void testManageCapacity() {
    std::vector<int> vec1 = { 10,20,30 };
    manageCapacity(vec1);
    assert(vec1.size() == 503);
    assert(vec1.capacity() >= 503);
    assert(vec1[0] == 10);
    assert(vec1[1] == 20);
    assert(vec1[2] == 30);
    assert(vec1[3] == 1);
    assert(vec1[502] == 500);

    std::vector<int> vec2;
    manageCapacity(vec2);
    assert(vec2.size() == 500);
    assert(vec2.capacity() >= 500);
    assert(vec2.front() == 1);
    assert(vec2.back() == 500);
}

int main() {
    testManageCapacity();
    std::cout << "All tests passed!" << std::endl;
}

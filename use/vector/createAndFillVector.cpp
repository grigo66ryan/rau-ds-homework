#include <iostream>
#include <vector>

void createAndFillVector(int N) {
    std::vector<int> vec(N);
    for (int i = 1; i <= N; i++) {
        vec[i - 1] = i;
    }
    for (int i = 0; i < N; i++) {
        std::cout << vec[i];
        if (i != N - 1) std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;
}

void testCreateAndFillVector() {
    createAndFillVector(5);
    createAndFillVector(0);
}

int main() {
    testCreateAndFillVector();
    std::cout << "All tests passed!" << std::endl;
}

#include <iostream>
#include <string>
#include <cassert>
template <typename T>
T sumArray(T* array, int n) {
    T sum{};
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    return sum;
}
void testSumArray() {
    int array1[] = { 2,2,2,2,2 };
    assert(sumArray(array1, 5) == 10);
    double array2[] = { 1.1,2.2,3.3 };
    assert(sumArray(array2, 3) > 6.59 && sumArray(array2, 3) < 6.61);
    std::string array3[] = { "a","b","c" };
    assert(sumArray(array3, 3) == "abc");
    int* empty = nullptr;
    assert(sumArray(empty, 0) == 0);
}
int main() {
    testSumArray();
    std::cout << "All tests passed!" << std::endl;
}

#include <iostream>
#include <string>
#include <cassert>
template <typename T, int N>
class FixedArray {
private:
    T array[N];
public:
    FixedArray() : array{} {}
    void set(int index, T value) {
        array[index] = value;
    }
    T get(int index) {
        return array[index];
    }
    int size() {
        return N;
    }
};
void testFixedArray() {
    FixedArray<std::string, 5> arr;
    assert(arr.size() == 5);
    assert(arr.get(0) == "");
    arr.set(0, "a");
    arr.set(4, "e");
    assert(arr.get(0) == "a");
    assert(arr.get(4) == "e");
    FixedArray<int, 3> arr2;
    assert(arr2.size() == 3);
    assert(arr2.get(0) == 0);
    arr2.set(1, 20);
    assert(arr2.get(1) == 20);
}
int main() {
    testFixedArray();
    std::cout << "All tests passed!" << std::endl;
}

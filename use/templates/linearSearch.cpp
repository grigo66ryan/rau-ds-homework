#include <iostream>
#include <vector>
#include <string>
#include <cassert>
template <typename T>
int linearSearch(const std::vector<T>& vec, T target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target) return i;
    }
    return -1;
}
void testLinearSearch() {
    std::vector<int> a = { 1,2,3,4,5 };
    assert(linearSearch(a, 1) == 0);
    assert(linearSearch(a, 5) == 4);
    assert(linearSearch(a, 10) == -1);
    std::vector<double> b = { 1.1,2.2,3.3 };
    assert(linearSearch(b, 2.2) == 1);
    std::vector<std::string> c = { "a","b","c" };
    assert(linearSearch(c, std::string("b")) == 1);
    std::vector<int> empty;
    assert(linearSearch(empty, 1) == -1);
}
int main() {
    testLinearSearch();
    std::cout << "All tests passed!" << std::endl;
}

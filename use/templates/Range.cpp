#include <iostream>
#include <string>
#include <cassert>
template <typename T>
class Range {
private:
    T start;
    T end;
public:
    Range() : start{}, end{} {}
    Range(T _start, T _end) : start(_start), end(_end) {}
    bool contains(const T& value) {
        return value >= start && value <= end;
    }
    T length() {
        return end - start;
    }
    void print() {
        std::cout << "Start: " << start << std::endl << "End: " << end << std::endl;
    }
};
void testRange() {
    Range<int> r1(5, 17);
    assert(r1.contains(5));
    assert(r1.contains(15));
    assert(r1.contains(17));
    assert(!r1.contains(4));
    assert(!r1.contains(18));
    assert(r1.length() == 12);
    Range<double> r2(12.5, 25.6);
    assert(r2.contains(12.5));
    assert(r2.contains(20.0));
    assert(!r2.contains(26.4));
    assert(r2.length() > 13.09 && r2.length() < 13.11);
    Range<char> r3('a', 'f');
    assert(r3.contains('a'));
    assert(r3.contains('d'));
    assert(r3.contains('f'));
    assert(!r3.contains('z'));
}
int main() {
    testRange();
    std::cout << "All tests passed!" << std::endl;
}

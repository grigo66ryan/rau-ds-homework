#include "Vector.h"
#include <cassert>
#include <iostream>
#include <string>

void test_default_constructor() {
    Vector<int> v;
    assert(v.size() == 0);
    assert(v.capacity() == 0);
    assert(v.empty());
    assert(v.begin() == v.end());
    std::cout << "test_default_constructor passed" << std::endl;
}

void test_size_constructor() {
    Vector<int> v(3);
    assert(v.size() == 3);
    assert(v.capacity() == 3);
    assert(!v.empty());
    assert(v[0] == 0);
    assert(v[1] == 0);
    assert(v[2] == 0);

    Vector<int> empty(0);
    assert(empty.empty());
    std::cout << "test_size_constructor passed" << std::endl;
}

void test_destructor() {
    Vector<int>* v = new Vector<int>;
    v->push_back(10);
    v->push_back(20);
    delete v;
    std::cout << "test_destructor passed" << std::endl;
}

void test_copy_constructor() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.reserve(8);

    Vector<int> copy(v);
    assert(copy.size() == 2);
    assert(copy.capacity() == 8);
    assert(copy[0] == 10);
    assert(copy[1] == 20);

    v[0] = 99;
    assert(copy[0] == 10);

    Vector<int> empty;
    Vector<int> empty_copy(empty);
    assert(empty_copy.empty());
    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment_operator() {
    Vector<std::string> a;
    a.push_back("one");
    a.push_back("two");

    Vector<std::string> b;
    b.push_back("old");
    b = a;

    assert(b.size() == 2);
    assert(b[0] == "one");
    assert(b[1] == "two");

    a[0] = "changed";
    assert(b[0] == "one");

    Vector<std::string>& same = b;
    b = same;
    assert(b.size() == 2);
    assert(b[1] == "two");
    std::cout << "test_assignment_operator passed" << std::endl;
}

void test_push_back() {
    Vector<int> v;
    v.push_back(5);
    assert(v.size() == 1);
    assert(v[0] == 5);

    v.push_back(10);
    v.push_back(15);
    assert(v.size() == 3);
    assert(v.back() == 15);
    assert(v.capacity() >= v.size());
    std::cout << "test_push_back passed" << std::endl;
}

void test_pop_back() {
    Vector<int> v;
    v.pop_back();
    assert(v.empty());

    v.push_back(10);
    v.push_back(20);
    v.pop_back();
    assert(v.size() == 1);
    assert(v.back() == 10);

    v.pop_back();
    assert(v.empty());
    std::cout << "test_pop_back passed" << std::endl;
}

void test_operator_bracket() {
    Vector<int> v(3);
    v[0] = 4;
    v[1] = 5;
    v[2] = 6;
    assert(v[0] == 4);
    assert(v[2] == 6);

    const Vector<int>& cv = v;
    assert(cv[1] == 5);
    std::cout << "test_operator_bracket passed" << std::endl;
}

void test_at() {
    Vector<int> v;
    v.push_back(7);
    v.push_back(8);
    assert(v.at(0) == 7);
    assert(v.at(1) == 8);

    v.at(1) = 10;
    assert(v[1] == 10);

    bool thrown = false;
    try {
        v.at(2);
    }
    catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);

    const Vector<int>& cv = v;
    assert(cv.at(0) == 7);
    std::cout << "test_at passed" << std::endl;
}

void test_front() {
    Vector<int> v;
    bool thrown = false;
    try {
        v.front();
    }
    catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);

    v.push_back(3);
    v.push_back(4);
    assert(v.front() == 3);
    v.front() = 9;
    assert(v[0] == 9);

    const Vector<int>& cv = v;
    assert(cv.front() == 9);
    std::cout << "test_front passed" << std::endl;
}

void test_back() {
    Vector<int> v;
    bool thrown = false;
    try {
        v.back();
    }
    catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);

    v.push_back(3);
    v.push_back(4);
    assert(v.back() == 4);
    v.back() = 10;
    assert(v[1] == 10);

    const Vector<int>& cv = v;
    assert(cv.back() == 10);
    std::cout << "test_back passed" << std::endl;
}

void test_size() {
    Vector<int> v;
    assert(v.size() == 0);
    v.push_back(1);
    assert(v.size() == 1);
    v.push_back(2);
    assert(v.size() == 2);
    v.pop_back();
    assert(v.size() == 1);
    std::cout << "test_size passed" << std::endl;
}

void test_capacity() {
    Vector<int> v;
    assert(v.capacity() == 0);
    v.reserve(10);
    assert(v.capacity() == 10);
    v.push_back(1);
    assert(v.capacity() == 10);
    std::cout << "test_capacity passed" << std::endl;
}

void test_empty() {
    Vector<int> v;
    assert(v.empty());
    v.push_back(1);
    assert(!v.empty());
    v.pop_back();
    assert(v.empty());
    std::cout << "test_empty passed" << std::endl;
}

void test_reserve() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    size_t old_size = v.size();

    v.reserve(20);
    assert(v.capacity() == 20);
    assert(v.size() == old_size);
    assert(v[0] == 10);
    assert(v[1] == 20);

    v.reserve(5);
    assert(v.capacity() == 20);
    std::cout << "test_reserve passed" << std::endl;
}

void test_clear() {
    Vector<int> v;
    v.reserve(10);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    size_t old_capacity = v.capacity();

    v.clear();
    assert(v.empty());
    assert(v.size() == 0);
    assert(v.capacity() == old_capacity);

    v.push_back(7);
    assert(v.front() == 7);
    std::cout << "test_clear passed" << std::endl;
}

void test_begin() {
    Vector<int> v;
    assert(v.begin() == v.end());

    v.push_back(4);
    v.push_back(5);
    assert(*v.begin() == 4);
    *v.begin() = 10;
    assert(v[0] == 10);

    const Vector<int>& cv = v;
    assert(*cv.begin() == 10);
    std::cout << "test_begin passed" << std::endl;
}

void test_end() {
    Vector<int> v;
    assert(v.begin() == v.end());

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    assert(v.end() - v.begin() == 3);
    assert(*(v.end() - 1) == 3);

    const Vector<int>& cv = v;
    assert(cv.end() - cv.begin() == 3);
    std::cout << "test_end passed" << std::endl;
}

int main() {
    std::cout << "Running Vector tests" << std::endl;
    test_default_constructor();
    test_size_constructor();
    test_destructor();
    test_copy_constructor();
    test_assignment_operator();
    test_push_back();
    test_pop_back();
    test_operator_bracket();
    test_at();
    test_front();
    test_back();
    test_size();
    test_capacity();
    test_empty();
    test_reserve();
    test_clear();
    test_begin();
    test_end();
    std::cout << "All tests passed" << std::endl;
    return 0;
}

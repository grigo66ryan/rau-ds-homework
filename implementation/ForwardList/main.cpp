#include "ForwardList.h"
#include <cassert>
#include <iostream>
#include <string>

void test_default_constructor() {
    ForwardList<int> list;
    assert(list.size() == 0);
    assert(list.empty());
    assert(list.begin() == nullptr);
    std::cout << "test_default_constructor passed" << std::endl;
}

void test_destructor() {
    ForwardList<int>* list = new ForwardList<int>;
    list->push_front(1);
    list->push_front(2);
    delete list;
    std::cout << "test_destructor passed" << std::endl;
}

void test_copy_constructor() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    ForwardList<int> copy(list);
    assert(copy.size() == 3);
    assert(copy.front() == 3);

    list.pop_front();
    assert(list.front() == 2);
    assert(copy.front() == 3);

    copy.reverse();
    assert(copy.front() == 1);

    ForwardList<int> empty;
    ForwardList<int> empty_copy(empty);
    assert(empty_copy.empty());
    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment_operator() {
    ForwardList<std::string> a;
    a.push_front("one");
    a.push_front("two");

    ForwardList<std::string> b;
    b.push_front("old");
    b = a;

    assert(b.size() == 2);
    assert(b.front() == "two");

    a.pop_front();
    assert(a.front() == "one");
    assert(b.front() == "two");

    ForwardList<std::string>& same = b;
    b = same;
    assert(b.size() == 2);
    assert(b.front() == "two");
    std::cout << "test_assignment_operator passed" << std::endl;
}

void test_push_front() {
    ForwardList<int> list;
    list.push_front(1);
    assert(list.size() == 1);
    assert(list.front() == 1);

    list.push_front(2);
    list.push_front(3);
    assert(list.size() == 3);
    assert(list.front() == 3);
    std::cout << "test_push_front passed" << std::endl;
}

void test_pop_front() {
    ForwardList<int> list;
    list.pop_front();
    assert(list.empty());

    list.push_front(1);
    list.push_front(2);
    list.pop_front();
    assert(list.size() == 1);
    assert(list.front() == 1);

    list.pop_front();
    assert(list.empty());
    std::cout << "test_pop_front passed" << std::endl;
}

void test_front() {
    ForwardList<int> list;
    bool thrown = false;
    try {
        list.front();
    }
    catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);

    list.push_front(5);
    assert(list.front() == 5);
    list.front() = 10;
    assert(list.front() == 10);

    const ForwardList<int>& const_list = list;
    assert(const_list.front() == 10);
    std::cout << "test_front passed" << std::endl;
}

void test_insert_after() {
    ForwardList<int> list;
    list.insert_after(nullptr, 5);
    assert(list.empty());

    list.push_front(1);
    list.insert_after(list.begin(), 2);
    assert(list.size() == 2);
    assert(list.front() == 1);

    list.reverse();
    assert(list.front() == 2);
    std::cout << "test_insert_after passed" << std::endl;
}

void test_erase_after() {
    ForwardList<int> list;
    list.erase_after(nullptr);
    assert(list.empty());

    list.push_front(1);
    list.erase_after(list.begin());
    assert(list.size() == 1);
    assert(list.front() == 1);

    list.push_front(2);
    list.push_front(3);
    list.erase_after(list.begin());
    assert(list.size() == 2);
    assert(list.front() == 3);

    list.reverse();
    assert(list.front() == 1);
    std::cout << "test_erase_after passed" << std::endl;
}

void test_clear() {
    ForwardList<int> list;
    list.clear();
    assert(list.empty());

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.clear();
    assert(list.size() == 0);
    assert(list.empty());
    assert(list.begin() == nullptr);

    list.push_front(5);
    assert(list.front() == 5);
    std::cout << "test_clear passed" << std::endl;
}

void test_reverse() {
    ForwardList<int> list;
    list.reverse();
    assert(list.empty());

    list.push_front(1);
    list.reverse();
    assert(list.front() == 1);

    list.push_front(2);
    list.push_front(3);
    list.reverse();
    assert(list.front() == 1);
    assert(list.size() == 3);
    std::cout << "test_reverse passed" << std::endl;
}

void test_size() {
    ForwardList<int> list;
    assert(list.size() == 0);
    list.push_front(1);
    assert(list.size() == 1);
    list.push_front(2);
    assert(list.size() == 2);
    list.pop_front();
    assert(list.size() == 1);
    std::cout << "test_size passed" << std::endl;
}

void test_empty() {
    ForwardList<int> list;
    assert(list.empty());
    list.push_front(1);
    assert(!list.empty());
    list.pop_front();
    assert(list.empty());
    std::cout << "test_empty passed" << std::endl;
}

void test_begin() {
    ForwardList<int> list;
    assert(list.begin() == nullptr);

    list.push_front(10);
    assert(list.begin() != nullptr);
    list.insert_after(list.begin(), 20);
    assert(list.size() == 2);

    const ForwardList<int>& const_list = list;
    assert(const_list.begin() != nullptr);
    std::cout << "test_begin passed" << std::endl;
}

int main() {
    std::cout << "Running ForwardList tests" << std::endl;
    test_default_constructor();
    test_destructor();
    test_copy_constructor();
    test_assignment_operator();
    test_push_front();
    test_pop_front();
    test_front();
    test_insert_after();
    test_erase_after();
    test_clear();
    test_reverse();
    test_size();
    test_empty();
    test_begin();
    std::cout << "All tests passed" << std::endl;
    return 0;
}

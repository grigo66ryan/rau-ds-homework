#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <stdexcept>

template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* _head;
    int _size;

public:
    ForwardList() : _head(nullptr), _size(0) {}

    ~ForwardList() {
        clear();
    }

    ForwardList(const ForwardList& other) : _head(nullptr), _size(0) {
        Node* current = other._head;
        Node* tail = nullptr;

        while (current != nullptr) {
            Node* new_node = new Node(current->data);
            if (_head == nullptr) {
                _head = new_node;
            }
            else {
                tail->next = new_node;
            }
            tail = new_node;
            current = current->next;
            _size++;
        }
    }

    ForwardList& operator=(const ForwardList& other) {
        if (this == &other) {
            return *this;
        }

        clear();
        Node* current = other._head;
        Node* tail = nullptr;

        while (current != nullptr) {
            Node* new_node = new Node(current->data);
            if (_head == nullptr) {
                _head = new_node;
            }
            else {
                tail->next = new_node;
            }
            tail = new_node;
            current = current->next;
            _size++;
        }

        return *this;
    }

    void push_front(const T& x) {
        Node* new_node = new Node(x);
        new_node->next = _head;
        _head = new_node;
        _size++;
    }

    void pop_front() {
        if (_head == nullptr) {
            return;
        }

        Node* old_head = _head;
        _head = _head->next;
        delete old_head;
        _size--;
    }

    T& front() {
        if (_head == nullptr) {
            throw std::out_of_range("ForwardList is empty");
        }
        return _head->data;
    }

    const T& front() const {
        if (_head == nullptr) {
            throw std::out_of_range("ForwardList is empty");
        }
        return _head->data;
    }

    void insert_after(Node* node, const T& value) {
        if (node == nullptr) {
            return;
        }

        Node* new_node = new Node(value);
        new_node->next = node->next;
        node->next = new_node;
        _size++;
    }

    void erase_after(Node* node) {
        if (node == nullptr || node->next == nullptr) {
            return;
        }

        Node* to_delete = node->next;
        node->next = to_delete->next;
        delete to_delete;
        _size--;
    }

    void clear() {
        while (_head != nullptr) {
            Node* to_delete = _head;
            _head = _head->next;
            delete to_delete;
        }
        _size = 0;
    }

    void reverse() {
        Node* previous = nullptr;
        Node* current = _head;

        while (current != nullptr) {
            Node* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        _head = previous;
    }

    int size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }

    Node* begin() {
        return _head;
    }

    Node* begin() const {
        return _head;
    }
};

#endif

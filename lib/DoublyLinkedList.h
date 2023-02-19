//
// Created by Peter Vaiciulis on 2/4/23.
//

#pragma once

#include "Node.h"

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* _head;
    Node<T>* _tail;
    int _size;
public:
    // Constructors & Destructor
    DoublyLinkedList() : _head(nullptr), _tail(nullptr), _size(0) {}
    DoublyLinkedList(const DoublyLinkedList& other );
    DoublyLinkedList& operator=(const DoublyLinkedList& other);
    ~DoublyLinkedList();

    // Methods
    void append(T data);
    void prepend(T data);
    T index(int index) const;  // Return value at index
    Node<T> *find(T data) const;  // Return first node with matching data value
    void remove(T data);  // Remove first occurrence of data
    bool isEmpty() const { return _size == 0; }

    // Class Accessors
    int size() { return _size; }

    // Iterator & Reverse Iterator
    struct Iterator {
        Node<T>* _current;
        explicit Iterator(Node<T>* current) : _current(current) {}

        // Reference & Access
        T& operator*() const { return _current->_data; }
        Node<T>* operator->() const { return _current; }

        // Move
        Iterator& operator++() { _current = _current->_next; return *this; }
        Iterator operator++(int) {DoublyLinkedList::Iterator temp = *this; _current = _current->_next; return temp;}

        friend bool operator!=(const Iterator& left, const Iterator& right) { return left._current != right._current; }
        friend bool operator==(const Iterator& left, const Iterator& right) { return left._current == right._current; }
    };
    struct rIterator {
        Node<T>* _current;
        explicit rIterator(Node<T>* current) : _current(current) {}

        // Reference & Access
        T& operator*() const { return _current->_data; }
        Node<T>* operator->() const { return _current; }

        // Move
        rIterator& operator++() { _current = _current->_prev; return *this; }

        friend bool operator!=(const rIterator& left, const rIterator& right)  { return left._current != right._current; }
        friend bool operator==(const rIterator& left, const rIterator& right) { return left._current == right._current; }
    };
    Iterator begin() const { return Iterator(_head); }
    Iterator end() const { return Iterator(nullptr); }
    rIterator rBegin() const { return rIterator(_tail); }
    rIterator rEnd() const { return rIterator(nullptr); }
};

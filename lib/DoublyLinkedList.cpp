//
// Created by Peter Vaiciulis on 2/4/23.
//

#include <stdexcept>
#include <string>
#include "DoublyLinkedList.h"



namespace psv
{
    // Constructors & Destructor
    template <typename T>
    DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other) {
        _head = nullptr;
        _tail = nullptr;
        _size = 0;
        for (auto i : other) {
            this->append(i);
        }
    }

    template <typename T>
    DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &other) {

        if (this == &other)
            return *this;

        if (other.isEmpty()) {
            while (_head->_next != nullptr) {
                Node<T>* temp = _head;
                _head = _head->_next;
                delete temp;
            }
            delete _head;
            _head = nullptr;
            _tail = nullptr;
            _size = 0;
            return *this;
        }

        // copy other list into current
        _head = nullptr;
        _tail = nullptr;
        _size = 0;
        for (auto i : other) {
            this->append(i);
        }
        return *this;
    }

    template <typename T>
    DoublyLinkedList<T>::~DoublyLinkedList() {
        if (_head == nullptr)
            return;
        while (_head->_next != nullptr) {
            Node<T>* temp = _head;
            _head = _head->_next;
            delete temp;
        }
        delete _head;
    }

    // Methods
    template <typename T>
    void DoublyLinkedList<T>::append(T data) {
        auto* newNode = new Node<T>(data);
        if (_head == nullptr) {
            _head = newNode;
            _tail = newNode;
        } else {
            _tail->_next = newNode;
            newNode->_prev = _tail;
            _tail = newNode;
        }
        _size++;
    }

    template <typename T>
    void DoublyLinkedList<T>::prepend(T data) {
        auto* newNode = new Node<T>(data);
        if (_head == nullptr) {
            _head = newNode;
            _tail = newNode;
        } else {
            _head->_prev = newNode;
            newNode->_next = _head;
            _head = newNode;
        }
        _size++;
    }

    // Given an index, returns what is at that index
    // Probably quite useless in practice, but useful for unit testing
    template <typename T>
    T DoublyLinkedList<T>::index(const int index) const {
        if (index > _size) {
            throw std::out_of_range("Index out of range");
        }

        int i = 0;
        for(auto it = this->begin(); it != this->end(); ++it) {
            if (i++ == index)
                return *it;
        }
        // safety clause; should never be reached
        throw std::out_of_range("Index out of range");
    }

    // Given a value, returns the Node if found
    template <typename T>
    Node<T>* DoublyLinkedList<T>::find(T data) const {
        for(auto it = this->begin(); it != this->end(); it++) {
            if (*it == data)
                return it._current;
        }
        return nullptr;
    }

    template <typename T>
    void DoublyLinkedList<T>::remove(T data) {
        Node<T>* dataNode = this->find(data);
        if (dataNode == nullptr)
            return;

        dataNode->_prev == nullptr ?
            _head = _head->_next : dataNode->_prev->_next = dataNode->_next;

        dataNode->_next == nullptr ?
            _tail = _tail->_prev : dataNode->_next->_prev = dataNode->_prev;

        delete dataNode;

        _size--;
    }
};

template class psv::DoublyLinkedList<int>;
template class psv::DoublyLinkedList<float>;
template class psv::DoublyLinkedList<std::string>;

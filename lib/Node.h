//
// Created by Peter Vaiciulis on 2/4/23.
//

#pragma once

template <typename T>
class Node {
public:
    explicit Node(T data) : _data(data) {}
    T _data;
    Node<T>* _next = nullptr;
    Node<T>* _prev = nullptr;
};



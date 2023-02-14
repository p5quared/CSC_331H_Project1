//
// Created by Peter Vaiciulis on 2/4/23.
//

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    explicit Node(T data) : _data(data) {}
    T _data;
    Node<T>* _next = nullptr;
    Node<T>* _prev = nullptr;
};


#endif //NODE_H

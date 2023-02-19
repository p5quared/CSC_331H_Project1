//
// Created by Peter Vaiciulis on 2/9/23.
//

#include <catch2/catch_test_macros.hpp>
#include "DoublyLinkedList.h"
#include "Node.h"



TEST_CASE( "Node<int>", "[Node]" ) {
    Node<int> node(1);
    REQUIRE( node._data == 1 );
    REQUIRE( node._next == nullptr );
    REQUIRE( node._prev == nullptr );
}

TEST_CASE( "Node<string>", "[Node]" ) {
    Node<std::string> node("foo");
    REQUIRE( node._data == "foo" );
    // at least I would hope this is not the case
    REQUIRE( node._data != "bar" );
    REQUIRE( node._next == nullptr );
    REQUIRE( node._prev == nullptr );
}

TEST_CASE( "DoublyLinkedList<int>", "[DoublyLinkedList]") {
    // All tests are run starting with a list of 4 ints; enough to cover all cases.
    // {0...3}
    DoublyLinkedList<int> list;
    REQUIRE( list.isEmpty() );
    for (int i = 0; i < 4; ++i) {
        list.append(i);
    }
    REQUIRE( list.size() == 4 );


    SECTION("Index") {
        // Index should return the item at the given index

        // Cases:
        // Index is out of bounds
        REQUIRE_THROWS_AS( list.index(10), std::out_of_range );
        // Index is head
        REQUIRE( list.index(0) == 0 );
        // Index is in middle
        REQUIRE( list.index(1) == 1 );
        // Index is tail
        REQUIRE( list.index(3) == 3 );
    }

    SECTION("Find") {
        // Find should return a pointer to the first node containing the item

        // Cases:
        // Item not in list
        REQUIRE( list.find(10) == nullptr );
        // Item is head
        REQUIRE( list.find(0) == list.begin()._current );
        // Item is in middle
        REQUIRE( list.find(1) == list.begin()._current->_next );
        // Item is tail
        REQUIRE( list.find(3) == list.rBegin()._current );
    }

    SECTION("Remove") {
        // Remove should remove the first instance of the item from the list

        // Cases:
        // Item not in list
        list.remove(10);
        REQUIRE( list.size() == 4 );

        // Item is tail
        list.remove(3);
        REQUIRE( list.size() == 3 );
        REQUIRE( list.index(2) == 2 );

        // Item is head
        list.remove(0);
        REQUIRE( list.size() == 2 );
        REQUIRE( list.index(0) == 1 );

        // Item is in middle
        list.append(3);
        list.remove(2);
        REQUIRE( list.size() == 2 );
        REQUIRE( list.index(0) == 1 );
        REQUIRE( list.index(1) == 3 );
    }

    SECTION("Prepend") {
        // Prepend should add an item to the beginning of the list
        list.prepend(99);
        REQUIRE( list.size() == 5 );
        REQUIRE( list.index(0) == 99 );
        REQUIRE( list.index(1) == 0 );

        // Prepend should work on an empty list
        DoublyLinkedList<int> emptyList;
        emptyList.prepend(99);
        REQUIRE( emptyList.size() == 1 );
        REQUIRE( emptyList.index(0) == 99 );
    }

    SECTION("Copy Constructor") {
        // Copy constructor should create a new list with the same items
        DoublyLinkedList<int> copy(list);
        REQUIRE( copy.size() == 4 );
        REQUIRE( copy.index(0) == 0 );
        REQUIRE( copy.index(1) == 1 );
        REQUIRE( copy.index(2) == 2 );
        REQUIRE( copy.index(3) == 3 );
    }

    SECTION("Assignment Operator") {
        // Assignment operator should create a new list with the same items
        DoublyLinkedList<int> copy = list;
        REQUIRE( copy.size() == 4 );
        REQUIRE( copy.index(0) == 0 );
        REQUIRE( copy.index(1) == 1 );
        REQUIRE( copy.index(2) == 2 );
        REQUIRE( copy.index(3) == 3 );


        // Assignment operator should work on an empty list
        DoublyLinkedList<int> emptyList;
        DoublyLinkedList<int> copy2 = emptyList;
        REQUIRE( copy2.size() == 0 );
    }

    SECTION("Iteration") {
        for(auto i : list) {
            REQUIRE( i == list.index(i) );
        }

        for(auto i = list.rBegin(); i != list.rEnd(); ++i) {
            REQUIRE( i._current->_data == list.index(i._current->_data) );
        }
    }
}

TEST_CASE("DoublyLinkedList<std::string>","[DoublyLinkedList]") {
    // I think excessive testing of the template usage is unnecessary
    using std::string;
    using std::to_string;

    DoublyLinkedList<string> list;
    for(int i = 10; i < 100; i+=10) {
        list.append(to_string(i));
    }
    REQUIRE( list.size() == 9 );
    REQUIRE( list.index(0) == "10" );
    REQUIRE( list.index(8) == "90" );
}
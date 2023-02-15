#include <iostream>
#include "DoublyLinkedList.h"
#include "DoublylinkedList.cpp"




using std::cout;
using std::endl;

namespace pFuncs
{
    template<typename t>
    void print(const std::string& msg="", const DoublyLinkedList<t>& l=DoublyLinkedList<t>());

    void displayMenu();
}



int main() {
    DoublyLinkedList<int> someList;

    cout << "Welcome to the Doubly Linked List Program!" << endl;
    cout << "This program will allow you to create a Doubly Linked List and manipulate it." << endl;
    cout << "You can append, prepend, and delete data from the list." << endl;
    // Continuously take user input and execute commands.
    while (true) {
        pFuncs::displayMenu();
        char input;
        std::cin >> input;
        switch (input) {
            case 'a':
                cout << "Enter data to append: ";
                int data;
                std::cin >> data;
                someList.append(data);
                break;
            case 'p':
                cout << "Enter data to prepend: ";
                int data2;
                std::cin >> data2;
                someList.prepend(data2);
                break;
            case 'd':
                cout << "Enter data to delete: ";
                int data3;
                std::cin >> data3;
                someList.remove(data3);
                break;
            case 'q':
                cout << "Quitting..." << endl;
                return 0;
            default:
                cout << "Invalid input. Please try again." << endl;
                break;
        }
        cout << "\n";
        pFuncs::print("List state: ", someList);
        cout << "\n";
    }

    return 0;
}


template<typename t>
void pFuncs::print(const std::string& msg, const DoublyLinkedList<t>& l){
    if(l.isEmpty())
        cout << "[]" << endl;
    if(!msg.empty())
        cout << msg << endl;

    cout << "[";
    for (auto i : l) {
        cout << i << ", ";
    }
    cout << "\b\b]" << endl;
}

void pFuncs::displayMenu(){
    cout << "Select an option:\n";
    cout << "a. Append data\n";
    cout << "p. Prepend data\n";
    cout << "d. Delete data\n";
    cout << "q. Quit\n>";
}

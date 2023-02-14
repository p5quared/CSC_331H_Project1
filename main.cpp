#include <iostream>
#include "DoublyLinkedList.h"
#include "DoublylinkedList.cpp"

// TODO: Resolve the need to include the .cpp file
// Likely due to building library at the same time as the main executable

// Menu features:
//   Implement using FTXGUI
// Commands:
//   t: visualize with table
//   a: append data
//   p: prepend data
//     ex: p 5 (prepend 5)
//       or p 5 6 7 (prepend 5, 6, 7)
//       or p (prepend random Node<T>)

// extra: use IMGUI? maybe not for this project

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
    cout << "You are starting with an empty linked-list." << endl;
    char input;
    do {
        pFuncs::displayMenu();
        std::cin >> input;
        switch (input) {
            int data;
            case 'a':
                cout << "Enter data to append: ";
                std::cin >> data;
                someList.append(data);
                break;
            case 'p':
                cout << "Enter data to prepend: ";
                std::cin >> data;
                someList.prepend(data);
                break;
            case 'd':
                cout << "Enter data to delete: ";
                std::cin >> data;
                someList.remove(data);
                break;
            case 'o':
                pFuncs::print("List:", someList);
                break;
            case 'q':
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    } while (input != 'q');
    cout << "Goodbye!" << endl;

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
    cout << "o. Print list\n";
    cout << "q. Quit\n>";
}

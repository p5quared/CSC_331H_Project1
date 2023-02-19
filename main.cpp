#include <iostream>
#include <iomanip>
#include "DoublyLinkedList.h"

#define pause(); std::cin.get();

using std::cout;
using std::endl;


namespace pFuncs
{
    // helper functions
    template<typename t>
    void print(const std::string& msg="", DoublyLinkedList<t> l=DoublyLinkedList<t>());

    template<typename t>
    void getData(const std::string&, t& data);

    void displayMenu();
    void clearDisplay();

}


int main() {
    DoublyLinkedList<int> nummies = DoublyLinkedList<int>();

    cout << "Welcome to the Doubly Linked List Program!\n";
    cout << "This program will allow you to create a Doubly Linked List and manipulate it.\n";
    cout << "You can append, prepend, and delete data from the list.\n";
    cout << "The first data you enter will set the type of data the list will hold." << endl;
    cout << "\nPress enter to continue...\n";
    pause();

    // Continuously take user input and execute commands.
    char input;
    do {
        pFuncs::clearDisplay();
        pFuncs::print("List state: ", nummies);
        cout << "\n";
        pFuncs::displayMenu();
        pFuncs::getData((std::string) "", input);
        switch (input) {
            int data;
            case 'a':
                pFuncs::getData("Enter data to append:", data);
                nummies.append(data);
                break;
            case 'p':
                pFuncs::getData("Enter data to prepend:", data);
                nummies.prepend(data);
                break;
            case 'd':
                pFuncs::getData("Enter data to delete:", data);
                nummies.remove(data);
                break;
            default:
                cout << "Command not recognized. Please try again." << endl;
                break;
        }
        cout << "\n";
    } while (input != 'q');
    pFuncs::clearDisplay();
    cout << "Thank you for using the Doubly Linked List Program!\n";
    pFuncs::print("Final list state: ", nummies);

    return 0;
}


template<typename t>
void pFuncs::print(const std::string& msg, DoublyLinkedList<t> l){
    using std::setw;
    using std::setfill;
    if(!msg.empty())
        cout << msg << endl;

    std::string output = "[";
    for (auto i : l) {
        output += std::to_string(i) + ", ";
    }
    output.length() > 1 ? output += "\b\b]"
            : output += "]";
    cout << output;


}

void pFuncs::displayMenu(){
    cout << "Select an option:\n";
    cout << "a. Append data\n";
    cout << "p. Prepend data\n";
    cout << "d. Delete data\n";
    cout << "q. Quit" << endl;
}


void pFuncs::clearDisplay(){
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

template<typename t>
void pFuncs::getData(const std::string& msg, t& data) {
    std::cout << msg << "\n>>";
    for (;;) {
        if (std::cin >> data)
            break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again:\n>>";
    }
}

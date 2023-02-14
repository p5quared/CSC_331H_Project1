# CSC331H PROJECT---PART 1
For info on this project and my specific implementation, feel free to skip to the "About This Project" section.

### Design and implement a class representing  an unsorted doubly linked list. The class must have the following requirements:

"X" means that the requirement is met and tested
1.	The linked list and the nodes must be implemented as  C++ templates [X]
2.	It must include a constructor, a destructor, a copy constructor and an operator= [X]
3.	It must include functions to delete a given item, search for a given item, check if the list is empty, return the length of the list [X]
4.	It must include functions to insert at the front and at the back of the list [X]
5.	It must provide an iterator to access items from front to back [X]
6.	It must provide an iterator to access items from back to front [X]

As of 2/11/2023, the class is complete and tested.

### Write a menu-driven program to test all the functions in your class.

## Timeline
* DUE FOR PEER REVIEW : 2/28
* PEER REVIEWS DUE:  3/2
* FINAL PROGRAM DUE:  3/7




## About This Project
Here is some information about using this project, and my process in creating it.
### Build
This project is built using CMake. Two targets are produced: "main" and "tests" (self explanatory). 
#### Dependencies
* [Catch2](https://github.com/catchorg/Catch2)
* [FTXUI](https://github.com/ArthurSonzogni/FTXU)

To build the project from within your terminal, run the following commands:
```
# From src/
mkdir build && cd build
cmake ..
make
./main
```
I enjoyed working on this project and feel that I learned *a lot* about C++ that I did not know before this.
Here are a couple issues that really plagued me in developing this project:
* My iterator would not reach the end of the list. I was using list.end() = list._tail rather than nullptr. (UGH)
  I spent an embarrassing amount of time stepping through in debug mode scratching my head at why it would not work.
  On the bright side, I am much more familiar with the debug tools in CLion now.
* Implementing Catch2 for testing was not as simple as it looked online, or as simple as I would have imagined.
  That being said, once it was integrated, it was super convenient to use. My one gripe is that CLion does not properly
  support its interface on the production build, so I have been using the "early access" version of CLion in order
  to get a proper integration. (It seems to be an error with the IDE's parsing of Catch's XML output which is solved in upcomming versions of CLion.)
* Installing libraries was something that I have never done before in C++ and while it is really not that difficult,
I was surprised at how few good resources there are to figure out how it is done... I spent a lot of time reading about
CMake and build tools in general, which really helped me understand how to use them.

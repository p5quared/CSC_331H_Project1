# CSC331H PROJECT---PART 1
For info on this project and my specific implementation, feel free to skip to the
[About this Project](#about-this-project) section.

### Design and implement a class representing  an unsorted doubly linked list. The class must have the following requirements:

"X" means that the requirement is met and tested
1.	The linked list and the nodes must be implemented as  C++ templates [X]
2.	It must include a constructor, a destructor, a copy constructor and an operator= [X]
3.	It must include functions to delete a given item, search for a given item, check if the list is empty, return the length of the list [X]
4.	It must include functions to insert at the front and at the back of the list [X]
5.	It must provide an iterator to access items from front to back [X]
6.	It must provide an iterator to access items from back to front [X]

As of 2/11/2023, the class is complete and tested.

As of  2/23/2023, the GUI is completed.



## About This Project
#### Dependencies
* [Catch2](https://github.com/catchorg/Catch2) - Testing
* [FTXUI](https://github.com/ArthurSonzogni/FTXU) - GUI


### Build
This project is built using CMake. Two targets are produced: "main" and "tests" (self explanatory). 

To build and run the project from within your terminal, run the following commands:
```
# From src/
mkdir build && cd build
cmake ..
make
```
There are two outputs: "main" and "tests".
"main" is the executable for the program, and "tests" is the executable for the tests.

I enjoyed working on this project and feel that I learned *a lot* about C++ that I did not know before this.
Here are a couple issues that really plagued me in developing this project:
* My iterator would not reach the end of the list. I was using list.end() = list._tail rather than nullptr. (UGH)
  I spent an embarrassing amount of time stepping through in debug mode scratching my head at why it would not work.
  On the bright side, I am much more familiar with the debug tools in CLion now (haha, *cries*).
* Installing libraries was something that I have never done before in C++ and while it is really not that difficult,
  I was surprised at how few good resources there are to figure out how it is done... I spent a lot of time reading about
  CMake and build tools in general, which really helped me understand how to use them.
* Implementing Catch2 for testing was not as simple as it looked online, or as simple as I would have imagined.
  That being said, once it was integrated, it was super easy to use. My one gripe is that CLion does not properly
  support its interface on the production build, so I have been using the "early access" version of CLion in order
  to get a proper integration. (It seems to be an error with the IDE's parsing of Catch's XML output which is solved in upcomming versions of CLion.)
* I am also quite please to have had the opportunity to make my first open course contribution (to a project not owned
  by me or someone I know). While rewriting a small portion of the documentation for FTXUI is a small contribution, 
  I am still quite proud to have done it. I hope to contribute to more projects in the future.

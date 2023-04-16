#include <iostream>
#include <exception>
using namespace std;

class GraphInitException : public exception {
public:
    virtual const char* what() const throw() {
        return "invalid input";
    }
};
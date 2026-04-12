#include <iostream>
#include "HelloWorld.hpp"

void printFromHeader()
{
    std::cout << "Hello from .hpp" << std::endl;
}

int main(){

    printFromHeader();

    return 0;
}
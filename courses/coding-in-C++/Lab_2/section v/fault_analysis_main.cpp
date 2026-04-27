/**
 * File: fault_analysis_main.cpp
 * Description: Main-function for using the methods of the 'Article'-class
 */

#include "fault_analysis.hpp"

int main() 
{
    Article a("Laptop", LAPTOP_PRICE, 10, "Electronics", LAPTOP_ID);

    a.sell(15);
    a.restock(-5);
    a.setPrice(-100);
    a.applyDiscount(150);

    if (a.isAvailable()) std::cout << "Article available" << std::endl;

    a.printInfo();

    return 0;
}
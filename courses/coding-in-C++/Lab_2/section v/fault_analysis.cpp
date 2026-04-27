/**
 * File: fault_analysis.cpp
 * Description: Implementation of primarily functions used in the 'Article'-class
 */

#include "fault_analysis.hpp"

/**
 * @brief:  Function for setting the price of an Article-object
 * 
 * @param[in]   price   Put in value for the price 
 */
void Article::setPrice(double price) 
{
    if(price <= 0)
    {
        std::cout << "Error. Price could not be set. Given Price of " << price << " Euros is invalid. (Less than or " << MIN_PRICE << ")" << std::endl;
        return;
    }
    this->price = price;
}

/**
 * @brief:  Function for selling articles and refreshing the amount in stock
 * 
 * @param[in]   amount      Number of articles that are supposed to be selled
 */
void Article::sell(std::uint8_t amount) {
    if(amount < stock)
    {
        std::cout << "Error. Amount to be selled is greater than amount of stock (stock: " << stock << ")" << std::endl;
        return;
    }
    this->stock = stock - amount;
}

/**
 * @brief:  Function for checking whether articles are available
 */
bool const Article::isAvailable() 
{
    if (stock > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief:  Function for putting articles in stock
 * 
 * @param[in]   amount      Amount of articles supposed to be put in stock
 */
void Article::restock(std::uint8_t amount) 
{
    this->stock += amount;
}

/**
 * @brief:  Function of applying discount onto the price
 * 
 * @param[in]   percent     Percentage which is supposed to be reduced of the price
 */
double Article::applyDiscount(double percent) {
    this->price = price - price * percent / 100;
    return price;
}

/**
 * @brief:  Function fo returning the price of an article
 */
double const Article::getPrice() 
{
    return price;
}

/**
 * @brief:  Function for printing the parameters of an article
 */
void const Article::printInfo() {
    std::cout << "Article: " << name << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Stock: " << stock << std::endl;
    std::cout << "ID: " << id << std::endl;
}
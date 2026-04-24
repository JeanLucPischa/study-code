/*
 * File: fluent_drink_builder.cpp
 * Description: Implemenation of functions used for building a drink via method chaining.
 */

#include "fluent_drink_builder.hpp"

/**
 * @brief Sets the name of the drink
 *
 * @param[in]   name            String-reference which contains the name of the drink
 * @param[out]  DrinkBuilder    DrinkBuilder object with new name     
 */
DrinkBuilder& DrinkBuilder::setName(const std::string& name)
{
    this->name = name;
    return *this;
}

/**
 * @brief Sets the amount of sugar in the drink
 *
 * @param[in]   sugar           Amount of sugar thats supposed to be added to the drink
 * @param[out]  DrinkBuilder    DrinkBuilder object with set amount of sugar  
 */
DrinkBuilder& DrinkBuilder::setSugar(std::uint8_t sugar)
{
    this->sugar = sugar;
    return *this;
}

/**
 * @brief Sets the temperatur of the drink
 *
 * @param[in]   temperatur      Temperature that the drink is supposed to have
 * @param[in]   DrinkBuilder    DrinkBuilder object with set temperature
 */
DrinkBuilder& DrinkBuilder::setTemperatur(std::int8_t temperatur)
{
    this->temperatur = temperatur;
    return *this;
}

/**
 * @brief Sets the option whether the drink contains milk or not
 *
 * @param[in]   with_milk       Flag whether drink is supposed to have milk or not
 * @param[out]  DrinkBuilder    DrinkBuilder object with or without milk      
 */
DrinkBuilder& DrinkBuilder::setWithMilk(bool with_milk)
{
    this->with_milk = with_milk;
    return *this;
}

/**
 * @brief Prints the current configuration of ingredients
 */
void DrinkBuilder::print()
{
    //configure string appended to "with" for printing wether drink has milk or not
    std::string status_milk;
    if(with_milk)
    {
        status_milk = " ";
    }
    else{
        status_milk = "out ";
    }

    //printing out properties of the drink
    std::cout << "The current configurated drink \"" << name << "\" has following properties:" << std::endl;
    std::cout << " - " << static_cast<int>(sugar) << "g of sugar" << std::endl;
    std::cout << " - " << static_cast<int>(temperatur) << " Degrees Celsius" << std::endl;
    std::cout << " - with" << status_milk << "milk" << std::endl << std::endl;
}

/**
 * @brief Checks the ingredients or given parameters for validity and prints out message in case of error
 *
 * @param[out]  flag            Flag containing info whether a parameter is not valid                      
 */
const bool DrinkBuilder::isValid()
{
    bool flag = false;   //flag for checking if invalid parameter has been found

    if(temperatur >= MAX_TEMP)
    {
        std::cout << "Drink configuration invalid: temperatur too high (maximum: " << static_cast<int>(MAX_TEMP) << ")." << std::endl;
        flag = true;
    }
    else if(temperatur <= MIN_TEMP)
    {
        std::cout << "Drink configuration invalid: temperatur too low (minimum: " << static_cast<int>(MIN_TEMP) << ")." << std::endl;
        flag = true;
    }
    if(sugar >= MAX_SUGAR)
    {
        std::cout << "Drink configuration invalid: sugar amount too high (maximum: " << static_cast<int>(MAX_SUGAR) << ")." << std::endl;
        flag = true;
    }
    else if(sugar <= MIN_SUGAR)
    {
        std::cout << "Drink configuration invalid: sugar amount too low (minimum: " << static_cast<int>(MIN_SUGAR) << ")." << std::endl;
        flag = true;
    }
    return flag;
}
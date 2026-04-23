#include "fluent_drink_builder.hpp"

DrinkBuilder& DrinkBuilder::setName(const std::string& name)
{
    this->name = name;
    return *this;
}

DrinkBuilder& DrinkBuilder::setSugar(std::uint8_t sugar)
{
    this->sugar = sugar;
    return *this;
}

DrinkBuilder& DrinkBuilder::setTemperatur(std::int8_t temperatur)
{
    this->temperatur = temperatur;
    return *this;
}

DrinkBuilder& DrinkBuilder::setWithMilk(bool with_milk)
{
    this->with_milk = with_milk;
    return *this;
}

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
    std::cout << " - with" << status_milk << "milk" << std::endl;
}

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
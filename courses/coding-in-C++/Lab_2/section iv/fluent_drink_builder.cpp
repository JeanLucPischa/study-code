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
    std::cout << " - " << sugar << "g of sugar" << std::endl;
    std::cout << " - " << temperatur << " Degrees Celsius" << std::endl;
    std::cout << " - with" << status_milk << "milk" << std::endl;
}

const bool DrinkBuilder::isValid()
{
    std::int8_t flag = 0;   //flag for checking if invalid parameter has been found

    if(temperatur >= MAX_TEMP)
    {
        std::cout << "Drink configuration invalid: temperatur too high (maximum: " << MAX_TEMP << ")." << std::endl;
        flag = 1;
    }
    else if(temperatur <= MIN_TEMP)
    {
        std::cout << "Drink configuration invalid: temperatur too low (minimum: " << MIN_TEMP << ")." << std::endl;
        flag = 1;
    }
    if(sugar >= MAX_SUGAR)
    {
        std::cout << "Drink configuration invalid: sugar amount too high ()."
    }
}
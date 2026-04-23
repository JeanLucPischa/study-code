#include "fluent_drink_builder.hpp"

int main()
{
    DrinkBuilder drink;
    drink.setName("Tea")
         .setSugar(20)
         .setTemperatur(-20)
         .setWithMilk(false)
         .print();

    drink.isValid();

    return 0;
}
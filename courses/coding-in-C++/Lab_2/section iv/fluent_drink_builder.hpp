#ifndef FLUENT_DRINK_BUILDER
#define FLUENT_DRINK_BUILDER

#include <iostream>
#include <string>
#include <cstdint>

constexpr std::uint8_t MAX_TEMP = 100;  //in celsius
constexpr std::uint8_t MIN_TEMP = -20;
constexpr std::int8_t MAX_SUGAR = 10;   //in grams

class DrinkBuilder
{
    private:
        std::string name;
        std::uint8_t sugar;
        std::int8_t temperatur;
        bool with_milk;

    public:
        DrinkBuilder& setName(const std::string& name);
        DrinkBuilder& setSugar(std::uint8_t sugar);
        DrinkBuilder& setTemperatur(std::int8_t temperatur);
        DrinkBuilder& setWithMilk(bool with_milk);
        void print();
        const bool isValid();
};

#endif
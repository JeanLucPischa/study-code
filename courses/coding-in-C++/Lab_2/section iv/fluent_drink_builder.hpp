#ifndef FLUENT_DRINK_BUILDER
#define FLUENT_DRINK_BUILDER

#include <iostream>
#include <string>
#include <cstdint>

const std::string DEFAULT_NAME = "Water";
constexpr std::uint8_t DEFAULT_SUGAR = 0;
constexpr std::uint8_t DEFAULT_TEMP = 15;
constexpr std::uint8_t DEFAULT_MILK = false;

constexpr std::uint8_t MAX_TEMP = 100;  //in celsius
constexpr std::uint8_t MIN_TEMP = 0;
constexpr std::uint8_t MAX_SUGAR = 10;   //in grams
constexpr std::uint8_t MIN_SUGAR = 0;

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
        DrinkBuilder() : name(DEFAULT_NAME), sugar(DEFAULT_SUGAR), temperatur(DEFAULT_TEMP), with_milk(DEFAULT_MILK) {};
};

#endif
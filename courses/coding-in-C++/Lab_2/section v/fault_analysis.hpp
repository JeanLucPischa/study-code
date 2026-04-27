#ifndef FAULT_ANALYSIS_HPP
#define FAULT_ANALYSIS_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdint>

constexpr std::uint8_t MIN_PRICE = 0;
constexpr double LAPTOP_PRICE = 999.99;
constexpr std::uint8_t LAPTOP_ID = 101;

class Article 
{
    private:
        std::string name;
        double price;
        std::uint8_t stock;
        std::string category;
        std::uint8_t id;

    public:
        Article(std::string name, double price, std::uint8_t stock, std::string category, std::uint8_t id)
        : name(name), price(price), stock(stock), category(category), id(id) {}

        ~Article(){}

        void setPrice(double price);
        void sell(std::uint8_t amount);
        void restock(std::uint8_t amount);
        double applyDiscount(double percent);
        double const getPrice();
        bool const isAvailable();
        void const printInfo();
};

#endif
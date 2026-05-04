/**
 * File:            static_polymorphism.cpp
 * Description:     Practicing function overloading and operator overloading (member vs free functions)
 */

#include <iostream>
#include <cmath>
#include <string>

class Vector2D
{
    private:
        double x, y;
    public:
        Vector2D() : x(0.0), y(0.0) {};
        Vector2D(double x, double y) : x(x), y(y) {};
        double get_x() const {return this->x;};
        double get_y() const {return this->y;};
        void print_coords(std::string name) const {std::cout << name << "(" << this->x << "|" << this->y << ")" << std::endl;};
        double vec_len() const
        {
            return std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2));
        };
        double vec_len(double precision) const
        {
            return std::round((std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2))) / precision) * precision;
        };
        
};

Vector2D operator+(const Vector2D& vec_obj1, const Vector2D& vec_obj2) 
{
    return Vector2D(vec_obj1.get_x() + vec_obj2.get_x(), vec_obj1.get_y() + vec_obj2.get_y());
};

Vector2D operator+=(const Vector2D& vec_obj1, const Vector2D& vec_obj2)
{
    return Vector2D(0,0);
};

int main()
{
    Vector2D vec0;
    Vector2D vec1(10, 473);
    Vector2D vec2(0.2, 9.5);

    vec0.print_coords("vec0");
    vec1.print_coords("vec1");
    vec2.print_coords("vec2");

    std::cout << "Lenght of vec1: " << vec1.vec_len() << std::endl;
    std::cout << "Lenght of vec2: " << vec2.vec_len() << std::endl << std::endl;; 
    
    double precision_vec1 = 0.00001;
    double precision_vec2 = 0.000001;
    std::cout << "Lenght of vec1 with precision of " << precision_vec1 << ": " << vec1.vec_len(precision_vec1) << std::endl;
    std::cout << "Lenght of vec2 with precision of " << precision_vec2 << ": " << vec2.vec_len(precision_vec2) << std::endl;

    return 0;
}
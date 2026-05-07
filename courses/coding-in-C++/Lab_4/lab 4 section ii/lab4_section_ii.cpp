#include <iostream>

class Shape {
    private:
        double area;

    public:
        virtual double calc_area() const {return 0.0;};
        virtual ~Shape() {};
};

class Circle : public Shape {
    private:
        double radius;
        static constexpr double PI = 3.141;
    
    public:

        double calc_area() const override 
        {
            return PI * radius * radius;
        }
        Circle(double radius) : radius(radius) {};
        ~Circle() override {};
};

class Rectangle  : public Shape {
    private:
        double width;
        double length;
    
    public:
        Rectangle(double width, double length) : width(width), length(length) {};
        double calc_area() const override
        {
            return width * length;
        };
        
        ~Rectangle() override {};
};

int main()
{
    constexpr int ARR_SIZE = 4;

    Circle cir_0(10);
    Circle cir_1(20);
    Rectangle rect_0(2, 5);
    Rectangle rect_1(3, 10);
    
    // Shape* shape_arr[4] = {&cir_0, &cir_1, &rect_0, &rect_1};

    // for(int i = 0; i < ARR_SIZE; i++)
    // {
    //     std::cout << shape_arr[i]->area() << std::endl;
    // }

    return 0;
}

/**
 * Part 1:
 * the method for calculating the area of the shape should be virtual so an definition in a derived class is 
 * mandatory, given that the calculation of the area of any shape without specified parameteres does not make sense
 * 
 * the class should have a virtual destructor so no memory leak occours
 * 
 * Part 2:
 * 
 */
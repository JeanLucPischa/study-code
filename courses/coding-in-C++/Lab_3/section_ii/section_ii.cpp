#include <iostream>
#include <string>
#include <cstdint>

class User 
{
    protected:
        std::string name;
        std::uint8_t id;

    public:
        User() {};
        User(std::string name, std::uint8_t id) : name(name), id(id) {}
        void printfInfo();
};

class Student : public User
{
    private:
        std::uint8_t active_classes;
        std::uint8_t mat_number;

    public:
        Student(std::string name, std::uint8_t id, std::uint8_t active_classes, std::uint8_t mat_number) : User(name, id), active_classes(active_classes), mat_number(mat_number) {};
};

class Instructor : public User
{
    private:
        std::uint8_t object_age;

    public:
        Instructor(std::string name, std::uint8_t id, std::uint8_t object_age) : User(name, id), object_age(object_age) {};
};

void User::printfInfo()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "ID: " << id << std::endl;
    return;
}
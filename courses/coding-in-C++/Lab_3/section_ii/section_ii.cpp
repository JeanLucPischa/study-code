#include <iostream>
#include <string>
#include <cstdint>

class User 
{
    protected:
        std::string name;
        std::uint16_t id;

    public:
        User() {};
        User(std::string name, std::uint16_t id) : name(name), id(id) {}
        void printfInfo();
};

class Student : public User
{
    private:
        std::uint16_t active_classes;

    public:
        Student(std::string name, std::uint16_t id, std::uint8_t active_classes) : User(name, id), active_classes(active_classes) {};
        void printRole();
};

class Instructor : public User
{
    private:
        std::uint8_t object_age;

    public:
        Instructor(std::string name, std::uint16_t id, std::uint8_t object_age) : User(name, id), object_age(object_age) {};
        void printRole();
};

void User::printfInfo()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "ID: " << id << std::endl;
    return;
}

void Student::printRole()
{
    std::cout << "Student" << std::endl;
    return;
}

void Instructor::printRole()
{
    std::cout << "Instructor" << std::endl << std::endl;
    return;
}

//########################################################################################################################

int main()
{
    Student greg("greg", 9823, 7);
    Student sophie("sophie", 1934, 6);

    Instructor schmidt("schmidt", 7412, 53);
    Instructor  mueller("mueller", 1046, 32);

    greg.printfInfo();
    greg.printRole();
    sophie.printfInfo();
    sophie.printRole();

    schmidt.printfInfo();
    schmidt.printRole();
    mueller.printfInfo();
    mueller.printRole();

    return 0;
}

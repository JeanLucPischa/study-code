#ifndef LAB3_SECTION_I_HPP
#define LAB3_SECTION_I_HPP

#include <iostream>
#include <string>
#include <cstdint>

constexpr std::uint8_t MAX_COURSES = 100;

class Platform 
{
    private:
        const std::uint8_t max_courses = MAX_COURSES;
        std::uint8_t amount_courses = 0;

    public:
        Platform(){};
        const std::uint8_t get_amount_courses(){};
};

class Course
{
    private:
        std::string title;
        std::string description;
        Platform* ptr_according_platform;

    public:
        const void print_info(){};
        void add_material(){};
        void organize_material(){};
};

class Lesson
{
    private:
        Course* ptr_accourding_course;
        std::uint8_t amount_content;
    
    public:
        void edit_content(){};
};

class Content
{
    private:
        std::string type;
        Lesson* according_lesson;

    public:
        void view_content(){};
};

class User
{
    private:
        const std::
};

#endif  //LAB3_SECTION_I_HPP
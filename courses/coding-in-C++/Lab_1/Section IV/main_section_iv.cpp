#include "grade_report_formatter.hpp"

int main()
{
    std::string name;
    std::uint8_t homework, midterm, final_exam;
    readStudentData(name, homework, midterm, final_exam);

    std::cout << name << std::endl << homework << std::endl << midterm << std::endl << final_exam << std::endl;

    return 0;
}
/*
 * File: main_section_iv.cpp
 * Description: Implementation of the main-function of the programm used for calculating and printing students scores.
 */

#include "grade_report_formatter.hpp"

int main()
{
    std::string name, letter_grade;
    std::uint16_t homework, midterm, final_exam, final_grade;
    readStudentData(name, homework, midterm, final_exam);

    calculateGrade(homework, midterm, final_exam, final_grade, letter_grade);

    printReport(name, homework, midterm, final_exam, final_grade, letter_grade);

    return 0;
}
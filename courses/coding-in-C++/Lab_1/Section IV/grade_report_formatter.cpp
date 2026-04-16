/*
 * File: grade_report_formatter.cpp
 * Description: Implemenation of functions used in reading, calculating and printing grades and scores of students.
 */

#include "grade_report_formatter.hpp"

void readScore(const std::string &text, std::uint16_t &value)
{
    const int MAX_POINTS = 100;

    while (true)
    {
        std::cout << text;

        if (!(std::cin >> value))
        {
            std::cout << "Error: please type in a valid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else if (value > MAX_POINTS)
        {
            std::cout << "Number is not in range (0-100). Please try again." << std::endl;
            continue;
        }
        break;
    }
}

void readStudentData(std::string &name, std::uint16_t &homework, std::uint16_t &midterm, std::uint16_t &final_exam)
{
    std::cout << "Please put in student name: ";
    std::cin >> std::ws;

    if(!(std::getline(std::cin, name)))
    {
        std::cout << "An error occured." << std::endl;
    }
    
    readScore("Please put in homework-score (0-100): ", homework);
    readScore("Please put in midterm-score (0-100): ", midterm);
    readScore("Please put in score of the final exam (0-100): ", final_exam);
}

void calculateGrade(const std::uint16_t homework, const std::uint16_t midterm, const std::uint16_t final_exam, std::uint16_t &final_grade, std::string &letter_grade)
{
   final_grade = (0.4*homework)+(0.25*midterm)+(0.35*final_exam);
   if(final_grade >= 90)
   {
        letter_grade = 'A';
   }
   else if(final_grade >= 80)
   {
        letter_grade = 'B';
   }
   else if(final_grade >= 70)
   {
        letter_grade = 'C';
   }
   else if(final_grade >= 60)
   {
        letter_grade = 'D';
   }
   else if(final_grade >= 50)
   {
        letter_grade = 'E';
   }
   else
   {
        letter_grade = 'F';
   }
}

std::string status(const std::string letter_grade)
{
    if((letter_grade == "A") || (letter_grade == "B") || (letter_grade == "C"))
    {
        return PASS;
    }
    else if((letter_grade == "D") || (letter_grade == "E"))
    {
        return CONDITIONAL PASS;
    }
    else if(letter_grade == "F")
    {
        return FAIL;
    }
    return "error: grade-letter did not match rating-system (A-F)";
}

void printReport(const std::string name, const std::uint16_t homework, const std::uint16_t midterm, const std::uint16_t final_exam, const std::uint16_t final_grade, std::string letter_grade)
{
    std::cout << LINE << std::endl;
    std::cout << std::left << "Student Report" << std::endl;
    std::cout << LINE << std::endl;
    std::cout << "Name: " << name << std::endl << std::endl;

    std::cout << "Scores" << std::endl;
    std::cout << LINE << std::endl;
    std::cout << std::setw(15) << "Homework" << ": " << std::setprecision(2) << homework << std::endl;
    std::cout << std::setw(15) << "Midterm" << ": " << std::setprecision(2) << midterm << std::endl;
    std::cout << std::setw(15) << "Final Exam" << ": " << std::setprecision(2) << final_exam << std::endl << std::endl;

    std::cout << std::setw(15) << "Final Grade" << ": " << std::setprecision(2) << final_grade << std::endl;
    std::cout << std::setw(15) << "Letter Grade" << ": " << letter_grade << std::endl;

    std::cout << std::setw(15) << "Status" << ": " << status(letter_grade) << std::endl;
    std::cout << LINE << std::endl;
}
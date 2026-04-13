#include "grade_report_formatter.hpp"

void readScore(const std::string &text, std::uint8_t value)
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

void readStudentData(std::string &name, std::uint8_t &homework, std::uint8_t &midterm, std::uint8_t &final_exam)
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
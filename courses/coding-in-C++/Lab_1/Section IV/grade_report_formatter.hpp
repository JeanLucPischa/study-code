#ifndef GRADE_REPORT_FORMATTER_HPP
#define GRADE_REPORT_FORMATTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdint>
#include <iomanip>

#define LINE "----------------------------"
#define PASS "PASS"
#define CONDITIONAL PASS "CONDITIONAL PASS"
#define FAIL "FAIL"

/**
 * @brief Reads singular inputs of values / scores
 *
 * @param[in] text          String containing the displayed user-input request
 * @param[in] value         Integer used to store the input of the user      
 */
void readScore(const std::string &text, std::uint16_t &value);

/**
 * @brief Reads user input (scores, grades, name of the student)
 *
 * @param[in] name          String used for saving the students name
 * @param[in] homework      Score of homework
 * @param[in] midterm       Score of the midterm
 * @param[in] final_exam    Score of the final exam
 */
void readStudentData(std::string &name, std::uint16_t &homework, std::uint16_t &midterm, std::uint16_t &final_exam);

/**
 * @brief Calculates the final grade and the letter-grade
 *
 * @param[in] homework      Score of homework
 * @param[in] midterm       Score of the midterm
 * @param[in] final_exam    Score of the final exam
 * @param[in] final_grade   Integer where the calculated final grade is stored
 * @param[in] letter_grade  String-literal of the final grade in form of a letter (A-F)
 */
void calculateGrade(const std::uint16_t homework, const std::uint16_t midterm, const std::uint16_t final_exam, std::uint16_t &final_grade, std::string &letter_grade);

/**
 * @brief Returns the according status to the given letter-grade
 * 
 * @param[in] letter_grade  String-literal of the final grade in form of a letter (A-F)
 * @param[out] status       According statis ("PASS", "CONDITIONAL PASS" or "FAIL")
 */
std::string status(const std::string letter_grade);

/**
 * @brief Prints out an overview of the scores and grades that were given and calculated
 *
 * @param[in] name          String used for saving the students name
 * @param[in] homework      Score of homework
 * @param[in] midterm       Score of the midterm
 * @param[in] final_exam    Score of the final exam
 * @param[in] final_grade   Calculated final grade
 * @param[in] letter_grade  String-literal of the final grade in form of a letter (A-F)
 */
void printReport(const std::string name, const std::uint16_t homework, const std::uint16_t midterm, const std::uint16_t final_exam, const std::uint16_t final_grade, std::string letter_grade);

#endif
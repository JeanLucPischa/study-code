#ifndef GRADE_REPORT_FORMATTER_HPP
#define GRADE_REPORT_FORMATTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdint>

void readScore(const std::string &text, std::uint8_t value);

void readStudentData(std::string &name, std::uint8_t &homework, std::uint8_t &midterm, std::uint8_t &final_exam);

#endif
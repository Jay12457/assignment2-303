// EmployeeTypes.cpp

#include "EmployeeTypes.h"

// Implementation of the Employee class constructor
Employee::Employee(const std::string& name, int age)
    : name(name), age(age) {}

// Implementation of the Professional class constructor
Professional::Professional(const std::string& name, int age, double monthlySalary, int vacationDays)
    : Employee(name, age), monthlySalary(monthlySalary), vacationDays(vacationDays) {}

// Calculate the weekly salary for a professional employee
double Professional::calculateWeeklySalary() const {
    // Assuming a month consists of 4 weeks
    return monthlySalary / 4;
}

// Compute healthcare contributions for a professional employee
double Professional::computeHealthCareContributions() const {
    // Example rule: 5% of monthly salary
    return monthlySalary * 0.05;
}

// Compute vacation days for a professional employee
int Professional::computeVacationDays() const {
    // Assuming 5 working days in a week
    return vacationDays / 5;
}

// Implementation of the Nonprofessional class constructor
Nonprofessional::Nonprofessional(const std::string& name, int age, double hourlyRate, int vacationHours)
    : Employee(name, age), hourlyRate(hourlyRate), vacationHours(vacationHours) {}

// Calculate the weekly salary for a nonprofessional employee
double Nonprofessional::calculateWeeklySalary() const {
    // Assuming 40 working hours in a week
    return hourlyRate * 40;
}

// Compute healthcare contributions for a nonprofessional employee
double Nonprofessional::computeHealthCareContributions() const {
    // Example rule: 2% of weekly salary
    return calculateWeeklySalary() * 0.02;
}

// Compute vacation days for a nonprofessional employee
int Nonprofessional::computeVacationDays() const {
    // Assuming 8 working hours in a day
    return vacationHours / 8;
}

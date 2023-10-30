// Main.cpp

#include <iostream>
#include "SingleLinkedList.h"
#include "EmployeeTypes.h"

int main() {
    // Creates a single linked list of integers
    SingleLinkedList<int> myList;

    myList.push_front(5);
    myList.displayList();  // Output: List: 5
    std::cout << std::endl;

    myList.push_front(15);
    myList.displayList();  // Output: List: 15 5
    std::cout << std::endl;

    myList.push_back(25);
    myList.displayList();  // Output: List: 15 5 25
    std::cout << std::endl;

    // Displays the list
    myList.displayList();  // Output: List: 15 5 25

    // Removes elements from the front and back
    myList.pop_front();
    myList.pop_back();

    // Displays the modified list
    myList.displayList();  // Output: List: 5

    // Inserts an element at a specific position
    myList.insert(1, 15);

    // Displays the list after insertion
    myList.displayList();  // Output: List: 5 15

    // Removes an element from a specific position
    myList.remove(0);

    // Displays the list after removal
    myList.displayList();  // Output: List: 15

    // Search for an item and display the result
    int item = 40;
    size_t index = myList.find(item);
    if (index != myList.find(item)) {
        std::cout << "Item " << item << " found at index " << index << std::endl;
    } else {
        std::cout << "Item " << item << " not found" << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    // Created instances of Professional and Nonprofessional employees
    Professional prof("Alice Johnson", 28, 5500.0, 25);
    Nonprofessional nonProf("Bob Davis", 35, 18.5, 80);

    // Displays information for the Professional employee
    std::cout << "Professional Employee: " << std::endl;
    std::cout << "Weekly Salary: $" << prof.calculateWeeklySalary() << std::endl;
    std::cout << "Health Care Contributions: $" << prof.computeHealthCareContributions() << std::endl;
    std::cout << "Vacation Days: " << prof.computeVacationDays() << " days" << std::endl;

    // Displays information for the Nonprofessional employee
    std::cout << "\nNonprofessional Employee: " << std::endl;
    std::cout << "Weekly Salary: $" << nonProf.calculateWeeklySalary() << std::endl;
    std::cout << "Health Care Contributions: $" << nonProf.computeHealthCareContributions() << std::endl;
    std::cout << "Vacation Hours: " << nonProf.computeVacationDays() << " hours" << std::endl;

    return 0;
}

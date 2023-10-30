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
    myList.displayList();  // Output: List: 5 10 20

    // Removes elements from the front and back
    myList.pop_front();
    myList.pop_back();

    // Displays the modified list
    myList.displayList();  // Output: List: 10

    // Inserts an element at a specific position
    myList.insert(1, 15);

    // Displays the list after insertion
    myList.displayList();  // Output: List: 10 15

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
    std::cout << "The Professional Employee Weekly Salary would be: " << prof.calculateWeeklySalary() << std::endl;
    std::cout << "The Health Care Contributions would be: " << prof.computeHealthCareContributions() << std::endl;
    std::cout << "The given Vacation Days are: " << prof.computeVacationDays() << std::endl;

    // Displays information for the Nonprofessional employee
    std::cout << "\nThe Nonprofessional Employee Weekly Salary would be: " << nonProf.calculateWeeklySalary() << std::endl;
    std::cout << "The Health Care Contributions is: " << nonProf.computeHealthCareContributions() << std::endl;
    std::cout << "The given Vacation Days are: " << nonProf.computeVacationDays() << std::endl;

    return 0;
}

// SingleLinkedList.cpp

#include <iostream>
#include "SingleLinkedList.h"
#include "EmployeeTypes.h"

// Define a class for a single-linked list
template <typename T>
SingleLinkedList<T>::SingleLinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor to free memory for all nodes
template <typename T>
SingleLinkedList<T>::~SingleLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Add a new item to the front of the list
template <typename T>
void SingleLinkedList<T>::push_front(const T& item) {
    Node* newNode = new Node{ item, head };
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
    num_items++;
}

// Add a new item to the end of the list
template <typename T>
void SingleLinkedList<T>::push_back(const T& item) {
    Node* newNode = new Node{ item, nullptr };
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    num_items++;
}

// Remove the first item in the list
template <typename T>
void SingleLinkedList<T>::pop_front() {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
        num_items--;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

// Remove the last item in the list
template <typename T>
void SingleLinkedList<T>::pop_back() {
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        num_items = 0;
    } else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
        num_items--;
    }
}

// Get the first item in the list (non-const version)
template <typename T>
T& SingleLinkedList<T>::front() {
    return head->data;
}

// Get the first item in the list (const version)
template <typename T>
const T& SingleLinkedList<T>::front() const {
    return head->data;
}

// Get the last item in the list (non-const version)
template <typename T>
T& SingleLinkedList<T>::back() {
    return tail->data;
}

// Get the last item in the list (const version)
template <typename T>
const T& SingleLinkedList<T>::back() const {
    return tail->data;
}

// Check if the list is empty
template <typename T>
bool SingleLinkedList<T>::empty() const {
    return num_items == 0;
}

// Insert an item at a specified index
template <typename T>
void SingleLinkedList<T>::insert(size_t index, const T& item) {
    if (index == 0) {
        push_front(item);
    } else if (index >= num_items) {
        push_back(item);
    } else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* newNode = new Node{ item, current->next };
        current->next = newNode;
        num_items++;
    }
}

// Remove an item at a specified index
template <typename T>
bool SingleLinkedList<T>::remove(size_t index) {
    if (index >= num_items) {
        return false;
    }
    if (index == 0) {
        pop_front();
    } else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        if (current->next == nullptr) {
            tail = current;
        }
        num_items--;
    }
    return true;
}

// Find the position of the first occurrence of an item in the list
template <typename T>
size_t SingleLinkedList<T>::find(const T& item) const {
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;
}

// Display the contents of the list
template <typename T>
void SingleLinkedList<T>::displayList() const {
    Node* current = head;
    std::cout << "List: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Explicit instantiation for the int type
template class SingleLinkedList<int>;

